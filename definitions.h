unsigned int temp1Default = 0;
unsigned int temp2Default = 0;
unsigned int time1Default = 0;

unsigned int temp1DefaultEEPROMAddress = 1;
unsigned int temp2DefaultEEPROMAddress = 2;
unsigned int time1DefaultEEPROMAddressFrom = 3;
unsigned int time1DefaultEEPROMAddressTo = 8;

const unsigned long time1Max = 999999;

unsigned int temp1 = 0;
unsigned int temp2 = 0;
unsigned int time1 = 0;

bool manual_spirala = false;
bool manual_cerpadlo = false;
bool manual_miesanie = false;

bool semi_ohrev = false;
bool semi_chladenie = false;
bool semi_miesanie = false;

unsingned int processTimeElapsed = 0;

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
unsigned long processMillis = 0;
unsigned long buttonPressMillis = 0;
int analogInput = 1023;
