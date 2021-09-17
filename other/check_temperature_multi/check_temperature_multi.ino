// https://lastminuteengineers.com/multiple-ds18b20-arduino-tutorial/

#include <LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define TEMP_BUS 2

OneWire oneWire(TEMP_BUS); 
DallasTemperature tempSensors(&oneWire);
 
LiquidCrystal lcd(8,9,4,5,6,7);

DeviceAddress deviceAddress1;
DeviceAddress deviceAddress2;

int deviceCount = 0;
float temp1 = 0.0;
float temp2 = 0.0;
bool showTemp = true;

unsigned long currentMillis = 0;
unsigned long buttonPressMillis = 0;
unsigned long getTempMillis = 0;
int analogInput = 1023;
int buttonIdx = -1;

void setup() {
  Serial.begin(9600);
  Serial.println(F("Start!"));

  tempSensors.begin();

  // locate devices on the bus
  Serial.print("Locating devices...");
  Serial.print("Found ");
  deviceCount = tempSensors.getDeviceCount();
  Serial.print(deviceCount, DEC);
  Serial.println(" devices.");
  Serial.println("");

  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(F("Teplomer"));

  tempSensors.getAddress(deviceAddress1, 0);
  if (deviceCount == 2) {
    tempSensors.getAddress(deviceAddress2, 1);
  }

}

void loop(void)
{ 
  currentMillis = millis();
  analogInput = analogRead(A0);

  if(currentMillis - buttonPressMillis > 200){
    buttonIdx = getButtonIdx(buttonIdx, analogInput);
  }

  if(currentMillis - getTempMillis > 1000){
    tempSensors.requestTemperatures(); 
    temp1 = tempSensors.getTempC(deviceAddress1);
    temp2 = tempSensors.getTempC(deviceAddress2);
    getTempMillis = currentMillis;
  }

  if(buttonIdx == 3){
    Serial.println("CLICK");
    lcd.clear();
    showTemp = !showTemp;
    buttonPressMillis = currentMillis; 
  }

  if(showTemp) {
    printTemperature();
  } else {
    printAddresses();
  }

  buttonIdx = -1;
}

void printAddresses() {
  lcd.setCursor(0,0);
  lcd.print(F("Adresy:"));
  
  lcd.setCursor(0,1);
  lcd.print(deviceAddress1[7], HEX);
  if (deviceCount == 2){
    lcd.setCursor(8,1);
    lcd.print(deviceAddress2[7], HEX);
  }
}

void printTemperature() { 
  lcd.setCursor(0,0);
  lcd.print(F("Teplota ("));
  lcd.print((char)223);
  lcd.print(F("C)"));
  
  lcd.setCursor(0,1);
  lcd.print(temp1);
  if (deviceCount == 2){
    lcd.setCursor(8,1);
    lcd.print(temp2);
  }
}

int getButtonIdx(int bIdx, int aInput) {

  if(aInput == 1023) {
    return -1;
  }
  else 
  {
    if(bIdx != -1) {
      return bIdx;
    }
    else {
      if(aInput < 50 && aInput >= 0){
        return 0;
      }
      else
      if(aInput < 150){
        return 1;
      }
      else
      if(aInput < 300){
        return 2;
      }
      else
      if(aInput < 500){
        return 3;
      }
      else
      if(aInput < 750){
        return 4;
      }
    }
  }
}
