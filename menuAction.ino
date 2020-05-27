void menuAction(){
  switch (programState) {
    case 0:
      menuActionMain();
      break;
    case 1:
      menuActionAuto();
      break;
    case 2:
      menuActionSemi();
      break;
    case 3:
      menuActionManual();
      break;
  }
}

void menuActionMain() {
  if (menuCode == 111 || menuCode == 211) {
    switch (buttonIdx) {
    case 1:
      if (temp1 != 100) {temp1++;}
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
      if (temp2 != 100) {temp2++;}
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
  else if (menuCode == 411) {
    switch (buttonIdx) {
    case 1:
      if (temp1Default != 100) {temp1Default++;}
      break;
    case 2:
      if (temp1Default != 0) {temp1Default--;}
      break;
    case 4:
      menuCode = menuCode / 10U;
      break;
    }
  }
  else if (menuCode == 421) {
    switch (buttonIdx) {
    case 1:
      if (temp2Default != 100) {temp2Default++;}
      break;
    case 2:
      if (temp2Default != 0) {temp2Default--;}
      break;
    case 4:
      menuCode = menuCode / 10U;
      break;
    }
  }
  else if (menuCode == 431) {
    switch (buttonIdx) {
    case 1:
      if ((time1Default + 30) > time1Default) {time1Default = time1Default + 30;}
      break;
    case 2:
      if ((time1Default - 30) < time1Default) {time1Default = time1Default - 30;}
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
      if (menuCodePrev == 23) {programState = 2;} // semi
      if (menuCodePrev == 31) {programState = 3;} // manual
      break;
    }
  }
}

void menuActionAuto() {
  if (buttonIdx == 4) {
    switch (menuCode) {
      case 140:
        restart();
      break;
    }
  }
  else if (buttonIdx == 0) {
    menuCode++;
  } else if (buttonIdx == 3) {
    menuCode--;
  }
}

void menuActionSemi() {
  if (buttonIdx == 4) {
    switch (menuCode) {
      case 231:
        if (!semi_chladenie){
          semi_ohrev = !semi_ohrev;
        }
      break;
      case 232:
        if (!semi_ohrev) {
          semi_chladenie = !semi_chladenie;  
        }
      break;
      case 233:
        semi_miesanie = !semi_miesanie;
      break;
      case 230:
        restart();
      break;
    }
  }
  else if (buttonIdx == 0) {
    menuCode++;
  } else if (buttonIdx == 3) {
    menuCode--;
  }
}

void menuActionManual() {
  if (buttonIdx == 4) {
    switch (menuCode) {
      case 310:
        restart();
      break;
      case 311:
        manual_spirala = !manual_spirala;
      break;
      case 312:
       manual_cerpadlo = !manual_cerpadlo;
      break;
      case 313:
       manual_miesanie = !manual_miesanie;
      break;
    }
  }
  else if (buttonIdx == 0) {
    menuCode++;
  } else if (buttonIdx == 3) {
    menuCode--;
  }
}

void restart() {
  programState = 0;

  temp1 = temp1Default;
  temp2 = temp2Default;
  time1 = time1Default;
  
  menuCode = 1;
  menuCodePrev = 1;
  parentCode = 1;
  
  menuCodeIdx = 0;

  semi_ohrev = false;
  semi_chladenie = false;
  semi_miesanie = false;

  manual_spirala = false;
  manual_cerpadlo = false;
  manual_miesanie = false;
}
