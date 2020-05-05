#include <LiquidCrystal.h>
#include "definitions.h"
//#include "menuInit.h"

LiquidCrystal lcd(8,9,4,5,6,7);

void setup() {
  Serial.begin(9600);
  Serial.println(F("Start!"));

  menuInit();

  lcd.begin(16, 2);
  lcd.clear();
  lcd.print(F("Serus gazda!"));

  navigate = true;
}

void loop() {
  currentMillis = millis();
  analogInput = analogRead(A0);

  // display welcome message for 2 seconds
  if(currentMillis < 1000) {return;}

  if(currentMillis - buttonPressMillis > 200){
    buttonIdx = getButtonIdx(buttonIdx, analogInput);
  }

  if(buttonIdx != prevButtonIdx && buttonIdx != -1){
    Serial.println(buttons[buttonIdx]);

    navigate = true;
    
    buttonPressMillis = currentMillis; 
  }

  if(navigate) {
    menuUpdate();
  }

  prevButtonIdx = buttonIdx;
  navigate = false;
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
