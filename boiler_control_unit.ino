#include <LiquidCrystal.h>
#include "definitions.h"
#include <EEPROM.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define TEMP_BUS 13

OneWire oneWire(TEMP_BUS); 
DallasTemperature tempSensor(&oneWire);
 
LiquidCrystal lcd(8,9,4,5,6,7);

void setup() {
  Serial.begin(9600);
  Serial.println(F("Start!"));

  tempSensor.begin();

  menuInit();

  int val = EEPROM.read(temp1DefaultEEPROMAddress);
  if (val != 255) {temp1Default = val;}
  val = EEPROM.read(temp2DefaultEEPROMAddress);
  if (val != 255) {temp2Default = val;}
  val = EEPROM.read(time1DefaultEEPROMAddressFrom);
  if (val != 255) {readTimeFromEEPROM();}

  temp1 = temp1Default;
  temp2 = temp2Default;
  time1 = time1Default;
  
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print(F("Serus gazda!"));

  navigate = true;
}

void loop() {
//  for (int i = 200; i<=255; i+=1)
//  {
//    analogWrite(11, i);
//    delay(10);
//  }
//  for (int i = 255; i!=200; i-=1)
//  {
//    analogWrite(11, i);
//    delay(10);
//  } 
  
  currentMillis = millis();
  analogInput = analogRead(A0);

  // display welcome message for 1 sec
  if(currentMillis < 1000) {return;}

  if(currentMillis - buttonPressMillis > 200){
    buttonIdx = getButtonIdx(buttonIdx, analogInput);
  }

  if(buttonIdx != prevButtonIdx && buttonIdx != -1){
    navigate = true;
    
    buttonPressMillis = currentMillis; 
  }

  if(currentMillis - lastProcessMillis > 5000 && programState != 0) {
    if(processStarted == false) {
      processStarted = true;
      startProcessMillis = currentMillis;
    }
    processProgram();
    
    lastProcessMillis = currentMillis;
  }

  if(navigate) {
    menuAction();
  
    menuCode = verifyMenuCode(menuCode, menuCodePrev);
    menuCodeIdx = findIdxFromCode(menuCode);
    
    parentCode = menuCode / 10;
    if (parentCode == 0) {
      parentCode = 1;
    }

    if ((menuCode == 1 && menuCodePrev == 10) || (menuCode == 2 && menuCodePrev == 20) || (menuCode == 3 && menuCodePrev == 30) || (menuCode == 4 && menuCodePrev == 40)) {
      temp1 = temp1Default;
      temp2 = temp2Default;
      time1 = time1Default;
    }
    
    if (menuCode == 41 && menuCodePrev == 411) {EEPROM.write(temp1DefaultEEPROMAddress, temp1Default);}
    if (menuCode == 42 && menuCodePrev == 421) {EEPROM.write(temp2DefaultEEPROMAddress, temp2Default);}
    if (menuCode == 43 && menuCodePrev == 431) {writeTimeToEEPROM();}
  
    menuDraw();
    
    menuCodePrev = menuCode;
  }

  prevButtonIdx = buttonIdx;
  navigate = false;
}
