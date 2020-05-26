void processProgram () {
  switch (programState) {
    case 0:
    break;
    case 1:
      processProgramAuto();
    break;
    case 2:
      processProgramSemi();
    break;
    case 3:
      processProgramManual();
    break;
  }
  
  // somewhere inside the switch we have raise menuDraw flag to draw menu
}

void processProgramAuto() {
  
}

void processProgramSemi() {
  
}

void processProgramManual() {
  
}
