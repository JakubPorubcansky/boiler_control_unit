int verifyMenuCode(unsigned int menuCode, unsigned int menuCodePrev) {
  if(menuCodePrev == 1 && menuCode == 0) {return menuCodePrev;}

  unsigned int mc10 = menuCode / 10U;
  unsigned int mc10Prev = menuCodePrev / 10U;

  if(abs(mc10 - mc10Prev) == 1 && (mc10 != 1 && mc10Prev != 0)) {return menuCodePrev;}
  if(mc10 == 1 && mc10Prev == 0 && menuCode == (menuCodePrev + 1)) {return menuCodePrev;}
  
  for (unsigned int j = 0; j <= (maxMenuItems - 1); j++ ) {
    if (menuCode == menu[j].code) {
      return menuCode;
      break;
    }
  }
  
  return menuCodePrev;
}

int findIdxFromCode(unsigned int menuCode) {
  for (unsigned int j = 0; j <= (maxMenuItems - 1); j++ ) {
    if (menuCode == menu[j].code) {
      return j;
      break;
    }
  }
  return -1;
}

int getNumberOfDigits(unsigned int num) {
  unsigned int nDigits = 1;
  while((num / 10) != 0) {
    num = num / 10;
    nDigits++;
  }
  return nDigits;
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
