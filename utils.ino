
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
