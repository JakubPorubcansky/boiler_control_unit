// https://lastminuteengineers.com/ds18b20-arduino-tutorial/

#include <LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define TEMP_BUS 2

OneWire oneWire(TEMP_BUS); 
DallasTemperature tempSensor(&oneWire);
 
LiquidCrystal lcd(8,9,4,5,6,7);

void setup() {
  Serial.begin(9600);
  Serial.println(F("Start!"));

  tempSensor.begin();

  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(F("Teplomer"));
}

void loop(void)
{ 
  tempSensor.requestTemperatures(); 

  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print(F("Teplota:"));

  lcd.setCursor(0,1);
  lcd.print(tempSensor.getTempCByIndex(0));
  lcd.print((char)223);
  lcd.print(F("C"));
  
  delay(1000);
}
