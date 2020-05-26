void menuInit() {
  unsigned int i = 0;

  menu[i].code = 1;
  strcpy(menu[i++].text, "Auto");
    menu[i].code = 10;
    strcpy(menu[i++].text, "Naspat");
    menu[i].code = 11;
    strcpy(menu[i++].text, "teplota 1");
      menu[i].code = 111;
      strcpy(menu[i++].text, "");
    menu[i].code = 12;
    strcpy(menu[i++].text, "teplota 2");
      menu[i].code = 121;
      strcpy(menu[i++].text, "");
    menu[i].code = 13;
    strcpy(menu[i++].text, "doba hriatia");
      menu[i].code = 131;
      strcpy(menu[i++].text, "");
    menu[i].code = 14;
    strcpy(menu[i++].text, "Spustit");
      menu[i].code = 140;
      strcpy(menu[i++].text, "Ukonci");
      menu[i].code = 141;
      strcpy(menu[i++].text, "AA");

  menu[i].code = 2;
  strcpy(menu[i++].text, "Semi");
    menu[i].code = 20;
    strcpy(menu[i++].text, "Naspat");
    menu[i].code = 21;
    strcpy(menu[i++].text, "teplota 1");
      menu[i].code = 211;
      strcpy(menu[i++].text, "");
    menu[i].code = 22;
    strcpy(menu[i++].text, "teplota 2");
      menu[i].code = 221;
      strcpy(menu[i++].text, "");
    menu[i].code = 23;
    strcpy(menu[i++].text, "Spustit");
      menu[i].code = 230;
      strcpy(menu[i++].text, "Ukonci");
      menu[i].code = 231;
      strcpy(menu[i++].text, "Zohrej na");
      menu[i].code = 232;
      strcpy(menu[i++].text, "Ochlad na");
      menu[i].code = 233;
      strcpy(menu[i++].text, "Miesanie");
      
  menu[i].code = 3;
  strcpy(menu[i++].text, "Manual");
    menu[i].code = 30;
    strcpy(menu[i++].text, "Naspat");
    menu[i].code = 31;
    strcpy(menu[i++].text, "Spustit");
      menu[i].code = 310;
      strcpy(menu[i++].text, "Ukonci");
      menu[i].code = 311;
      strcpy(menu[i++].text, "Spirala");
      menu[i].code = 312;
      strcpy(menu[i++].text, "Cerpadlo");
      menu[i].code = 313;
      strcpy(menu[i++].text, "Miesanie");

  menu[i].code = 4;
  strcpy(menu[i++].text, "Nastavenia");
    menu[i].code = 40;
    strcpy(menu[i++].text, "Naspat");
    menu[i].code = 41;
    strcpy(menu[i++].text, "D");

 maxMenuItems = i + 1;
}
