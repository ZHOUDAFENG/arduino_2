//Demo LCD12864 spi
//www.dfrobot.com
 #include <ESP8266WiFi.h>
#ifndef LCD12864RSPI_h
#define LCD12864RSPI_h
#include <pgmspace.h>
#include <inttypes.h>


class LCD12864RSPI {
typedef unsigned char uchar;


public:

LCD12864RSPI();

void Initialise(void);
void delayns(void);

void WriteByte(int dat);
void WriteCommand(int CMD);
void WriteData(int CMD);


void CLEAR(void);
void DisplayString(int X,int Y,uchar *ptr,int dat);
void DisplaySig(int M,int N,int sig);
void DrawFullScreen(uchar *p);

int delaytime;
int DEFAULTTIME;


static const int latchPin = 0; //8 /esp d5
static const int clockPin = 4;  //3  /6
static const int dataPin = 5;//9    //d2

};
extern LCD12864RSPI LCDA;    
#endif
