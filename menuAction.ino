void menuAction(){
  if (menuCode == 111 || menuCode == 211) {
    switch (buttonIdx) {
    case 1:
      temp1++;
      if (temp1 > 100) {temp1--;}
      break;
    case 2:
      if (temp1 != 0) {temp1--;}
      break;
    case 4:
      menuCode = menuCode / 10U;
      break;
    }
  }
  else if (menuCode == 121 || menuCode == 221) {
    switch (buttonIdx) {
    case 1:
      temp2++;
      if (temp2 > 100) {temp2--;}
      break;
    case 2:
      if (temp2 != 0) {temp2--;}
      break;
    case 4:
      menuCode = menuCode / 10U;
      break;
    }
  }
  else if (menuCode == 131) {
    switch (buttonIdx) {
    case 1:
      if ((time1 + 30) > time1) {time1 = time1 + 30;}
      break;
    case 2:
      if ((time1 - 30) < time1) {time1 = time1 - 30;}
      break;
    case 4:
      menuCode = menuCode / 10U;
      break;
    }
  }
  else {
    switch (buttonIdx) {
    case 0:
      menuCode++;
      break;
    case 3:
      menuCode--;
      break;
    case 4:
      if ((menuCode % 10) == 0) {
        menuCode = menuCode / 10U;
      } else
      {
        menuCode = ((menuCode * 10) / 10U) * 10 + 1;
      }

      // running the selected program
      if (menuCodePrev == 14) {programState = 1;} // auto
      if (menuCodePrev== 23) {programState = 2;} // semi
      if (menuCodePrev == 31) {programState = 3;} // manual
      break;
    }
  }
}
