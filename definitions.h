unsigned int temp1 = 0;
unsigned int temp2 = 0;
unsigned int time1 = 0;

bool manual_spirala = false;
bool manual_cerpadlo = false;
bool manual_miesanie = false;

bool semi_ohrev = false;
bool semi_chladenie = false;
bool semi_miesanie = false;

// state of the program (0 - menu, 1 - auto, 2 - semi, 3 - manual)
unsigned int programState = 0;

unsigned int maxMenuItems;

unsigned int menuCode = 1;
unsigned int menuCodePrev = 1;
unsigned int parentCode = 1;

unsigned int menuCodeIdx = 0;

typedef struct menu_type
 {
     
     menu_type()
     : code(0), text("")
     {
       //do nothing
     }
     
     unsigned int code;
     char text[17];
     
 }  menu_type;

menu_type menu[50] = {};

bool navigate = false;

const char button1[6] = "RIGHT";
const char button2[3] = "UP";
const char button3[5] = "DOWN";
const char button4[5] = "LEFT";
const char button5[7] = "SELECT";

const char * buttons[5] =
{
  button1,
  button2,
  button3,
  button4,
  button5
};

int buttonIdx = -1;
int prevButtonIdx = -1;

unsigned long currentMillis = 0;
unsigned long buttonPressMillis = 0;
int analogInput = 1023;

//const int nMenuItems = 4;
//const char menuItem1[5] = "Auto";
//const char menuItem2[10] = "Semi-auto";
//const char menuItem3[7] = "Manual";
//const char menuItem4[11] = "Moznosti";
//
//const char * menuItems[nMenuItems] =
//{
//  menuItem1,
//  menuItem2,
//  menuItem3,
//  menuItem4
//};
//
//int menuItemIdx = 0;
//
//const int nAutoItems = 1;
//const char autoItem1[5] = "Naspat";
//
//const char * autoItems[nAutoItems] =
//{
//  autoItem1
//};
//
//const int nSemiItems = 1;
//const char semiItem1[5] = "Naspat";
//
//const char * semiItems[nSemiItems] =
//{
//  semiItem1
//};
//
//const int nManualItems = 1;
//const char manualItem1[5] = "Naspat";
//
//const char * manualItems[nManualItems] =
//{
//  manualItem1
//};
//
//const int nMoznostiItems = 1;
//const char moznostiItem1[5] = "Naspat";
//
//const char * moznostiItems[nMoznostiItems] =
//{
//  moznostiItem1
//};
