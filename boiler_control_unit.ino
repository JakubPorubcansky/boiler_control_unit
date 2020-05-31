#include <LiquidCrystal.h>
#include "definitions.h"
#include <EEPROM.h>

LiquidCrystal lcd(8,9,4,5,6,7);

void setup() {
  Serial.begin(9600);
  Serial.println(F("Start!"));

  temp1 = temp1Default;
  temp2 = temp2Default;
  time1 = time1Default;
  
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

  // display welcome message for 2 seconds
  if(currentMillis < 1000) {return;}

  if(currentMillis - buttonPressMillis > 200){
    buttonIdx = getButtonIdx(buttonIdx, analogInput);
  }

  if(buttonIdx != prevButtonIdx && buttonIdx != -1){
    navigate = true;
    
    buttonPressMillis = currentMillis; 
  }

  if(currentMillis - processMillis > 5000) {
    processProgram();
    
    processMillis = currentMillis;
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

void writeTimeToEEPROM() {
  int nDigits = getNumberOfDigits(time1Default);
  int val = time1Default;
  for (int i=nDigits; i>0; i--) {
    if (i == 1) {
      EEPROM.write(time1DefaultEEPROMAddressFrom + nDigits - i, time1Default % 10);
    } else {
      EEPROM.write(time1DefaultEEPROMAddressFrom + nDigits - i, val / pow(10,(i-1)));
    }
    val = val % int(pow(10,(i-1)));
  }
  for (int i=time1DefaultEEPROMAddressFrom + nDigits; i <= time1DefaultEEPROMAddressTo; i++) {
    EEPROM.write(i, 255);
  }
}

void readTimeFromEEPROM() {
  time1Default = 0;
  int val = 0; 
  for(int i=time1DefaultEEPROMAddressFrom; i<=time1DefaultEEPROMAddressTo; i++) {
    val = EEPROM.read(i);
    if(val == 255) {break;}
    time1Default = (time1Default * 10) + val;
  }
}
