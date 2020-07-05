void menuDraw() {
  switch (programState) {
  case 0:
    menuDrawMain();
    break;
  case 1:
    menuDrawAuto();
    break;
  case 2:
    menuDrawSemi();
    break;
  case 3:
    menuDrawManual();
    break;
  }
}

void menuDrawMain() {
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
    lcd.print(time1 / 60);
    if ((time1 % 60) == 0) {lcd.print(F(".0 min."));} 
    else {lcd.print(F(".5 min."));}
  } 
  else if (menuCode == 411) {
    lcd.print(temp1Default);
    lcd.print((char)223);
    lcd.print(F("C"));
  }
  else if (menuCode == 421) {
    lcd.print(temp2Default);
    lcd.print((char)223);
    lcd.print(F("C"));
  }
  else if (menuCode == 431) {
    lcd.print(time1Default / 60);
    if ((time1Default % 60) == 0) {lcd.print(F(".0 min."));} 
    else {lcd.print(F(".5 min."));}
  }
  else {
    lcd.print(menu[menuCodeIdx].text);
  }
}

void menuDrawAuto() {
  lcd.clear();
  lcd.print(menu[menuCodeIdx].text);
}

void menuDrawSemi() {
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
    lcd.print(F(" (10"));
    lcd.print((char)223);
    lcd.print(F("C,120m)"));
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

void menuDrawManual() {
  lcd.clear();
  lcd.print(menu[menuCodeIdx].text);

  switch (menuCode) {
  case 311:
    lcd.setCursor(0,1);
    if (manual_spirala) {lcd.print(F("Zap."));}
    else {lcd.print(F("Vyp."));}
    break;
  case 312:
    lcd.setCursor(0,1);
    if (manual_cerpadlo) {lcd.print(F("Zap."));}
    else {lcd.print(F("Vyp."));}
    break;
  case 313:
    lcd.setCursor(0,1);
    if (manual_miesanie) {lcd.print(F("Zap."));}
    else {lcd.print(F("Vyp."));}
    break;
  }
}
