void processProgram () {
  processTimeElapsed = (currentMillis - startProcessMillis) / 1000;
  tempSensor.requestTemperatures();

  tempReading = (int) tempSensor.getTempCByIndex(0);
  
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
  
  menuDraw();
}

void processProgramAuto() {
  
}

void processProgramSemi() {
  
}

void processProgramManual() {
  
}
