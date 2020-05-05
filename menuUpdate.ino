void menuUpdate(){

  menuAction();
  
  menuCode = verifyMenuCode(menuCode, menuCodePrev);
  menuCodeIdx = findIdxFromCode(menuCode);
  
  parentCode = menuCode / 10;
  if (parentCode == 0) {
    parentCode = 1;
  }

  switch (programState) {
  case 0:
    drawMenu();
    break;
  case 1:
    break;
  case 2:
    drawSemi();
    break;
  case 3:
    break;
  }
  
  menuCodePrev = menuCode;
}

void drawMenu() {
  unsigned int codeNDigits = getNumberOfDigits(menuCode);
  
  lcd.clear();
  
  switch (codeNDigits) {
  case 1:
      lcd.print(F("Zvol program"));
      break;
    default:
      unsigned int parentCodeIdx = findIdxFromCode(parentCode);
      lcd.print(menu[parentCodeIdx].text);
      break;
  }

  lcd.setCursor(0,1);
  lcd.print(F("-> "));
  
  if (menuCode == 111 || menuCode == 211) {
    lcd.print(temp1);
    lcd.print((char)223);
    lcd.print(F("C"));
  }
  else if (menuCode == 121 || menuCode == 221) {
    lcd.print(temp2);
    lcd.print((char)223);
    lcd.print(F("C"));
  }
  else if (menuCode == 131) {
    lcd.print(time1);
    lcd.print(F(" s."));
  } else {
    lcd.print(menu[menuCodeIdx].text);
  }
}

void drawSemi() {
  lcd.clear();
  lcd.print(menu[menuCodeIdx].text);

  switch (menuCode) {
  case 231:
    lcd.print(F(" "));
    lcd.print(temp1);
    lcd.print((char)223);
    lcd.print(F("C"));
    lcd.setCursor(0,1);
    if (semi_ohrev) {lcd.print(F("Zap."));}
    else {lcd.print(F("Vyp."));}
    lcd.print(F(" (0"));
    lcd.print((char)223);
    lcd.print(F("C)"));
    break;
  case 232:
    lcd.print(F(" "));
    lcd.print(temp2);
    lcd.print((char)223);
    lcd.print(F("C"));
    lcd.setCursor(0,1);
    if (semi_chladenie) {lcd.print(F("Zap."));}
    else {lcd.print(F("Vyp."));}
    lcd.print(F(" (0"));
    lcd.print((char)223);
    lcd.print(F("C)"));
    break;
  case 233:
    lcd.setCursor(0,1);
    if (semi_miesanie) {lcd.print(F("Zap."));}
    else {lcd.print(F("Vyp."));}
    break;
  }

}