void menuUpdate(){

  menuAction();
  
  menuCode = verifyMenuCode(menuCode, menuCodePrev);
  menuCodeIdx = findIdxFromCode(menuCode);
  
  parentCode = menuCode / 10;
  if (parentCode == 0) {
    parentCode = 1;
  }

  menuDraw();
  
  menuCodePrev = menuCode;
}
