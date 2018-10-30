#include "LCD12864RSPI.h"
#define AR_SIZE( a ) sizeof( a ) / sizeof( a[0] )

unsigned char show0[]={0xBC,0xAB,0xBF,0xCD,0xB9,0xA4,0xB7,0xBB};//极客工坊
unsigned char show1[]="geek-workshop";
unsigned char logo0[]={                                         //笑脸
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xFF,
      0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xFF,
      0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,
      0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x03,0xFE,0x00,
      0x7F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,
      0x0F,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x1F,0x80,0x00,
      0x01,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x3E,0x00,0x00,
      0x00,0x7C,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0xF8,0x00,0x00,
      0x00,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x01,0xF0,0x00,0x00,
      0x00,0x0F,0x80,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x03,0xE0,0x00,0x00,
      0x00,0x07,0xC0,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x07,0xC0,0x00,0x00,
      0x00,0x01,0xE0,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x07,0x80,0x00,0x00,
      0x00,0x00,0xE0,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x0F,0x00,0x00,0x00,
      0x00,0x00,0xF0,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x1E,0x00,0x00,0x00,
      0x00,0x00,0x78,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x3C,0x00,0x00,0x00,
      0x00,0x00,0x3C,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x38,0x00,0x40,0x00,
      0x00,0x80,0x1C,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x78,0x03,0xF8,0x00,
      0x07,0xF0,0x1E,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x70,0x07,0xFE,0x00,
      0x0F,0xFC,0x0E,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0xF0,0x1F,0xBF,0x00,
      0x3F,0x7E,0x0F,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0xE0,0x3E,0x0F,0x80,
      0x7C,0x1F,0x07,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0xE0,0x7C,0x07,0xC0,
      0xF8,0x0F,0x87,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x01,0xE0,0xF8,0x01,0xE1,
      0xF0,0x03,0xC3,0x80,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x01,0xC0,0xF0,0x01,0xE1,
      0xE0,0x03,0xC3,0x80,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x01,0xC0,0xE0,0x00,0xE1,
      0xC0,0x01,0xC3,0x80,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x01,0xC0,0x00,0x00,0x00,
      0x00,0x00,0x03,0x80,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x03,0x80,0x00,0x00,0x00,
      0x00,0x00,0x01,0xC0,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x03,0x80,0x00,0x00,0x00,
      0x00,0x00,0x01,0xC0,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x03,0x80,0x00,0x00,0x00,
      0x00,0x00,0x01,0xC0,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x03,0x80,0x00,0x00,0x00,
      0x00,0x00,0x01,0xC0,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x03,0x80,0x00,0x00,0x00,
      0x00,0x00,0x01,0xC0,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x03,0x80,0x00,0x00,0x00,
      0x00,0x00,0x01,0xC0,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x03,0x80,0x00,0x00,0x00,
      0x00,0x00,0x01,0xC0,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x03,0x80,0x00,0x00,0x00,
      0x00,0x00,0x01,0xC0,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x03,0x80,0x00,0x00,0x00,
      0x00,0x00,0x01,0xC0,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x03,0x80,0x00,0x00,0x00,
      0x00,0x00,0x01,0xC0,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x01,0xC0,0x00,0x00,0x00,
      0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x01,0xC0,0x00,0x00,0x00,
      0x00,0x00,0x03,0x80,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x01,0xC0,0x00,0x00,0x00,
      0x00,0x00,0x03,0x80,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x01,0xE0,0x00,0x00,0x00,
      0x00,0x00,0x03,0x80,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,
      0x00,0x00,0x07,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,
      0x00,0x00,0x07,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0xF0,0x00,0x0C,0x00,
      0x0C,0x00,0x0F,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x70,0x00,0x1E,0x00,
      0x1E,0x00,0x0E,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x78,0x00,0x1F,0x00,
      0x3E,0x00,0x1E,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x38,0x00,0x07,0x80,
      0xF8,0x00,0x1C,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x3C,0x00,0x03,0xE1,
      0xF0,0x00,0x3C,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x1E,0x00,0x01,0xFF,
      0xE0,0x00,0x78,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x0F,0x00,0x00,0xFF,
      0x80,0x00,0xF0,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x07,0x00,0x00,0x3F,
      0x00,0x00,0xF0,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x07,0x80,0x00,0x00,
      0x00,0x01,0xE0,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x03,0xE0,0x00,0x00,
      0x00,0x07,0xC0,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x01,0xF0,0x00,0x00,
      0x00,0x0F,0x80,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0xF8,0x00,0x00,
      0x00,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x3E,0x00,0x00,
      0x00,0x7E,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x1F,0x80,0x00,
      0x01,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x0F,0xE0,0x00,
      0x07,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x03,0xFE,0x00,
      0x3F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,
      0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xFF,
      0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xFF,
      0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
const int analogOutPin = 10;
void setup()
{
LCDA.Initialise(); // 屏幕初始化

delay(100);
}

void loop()
{
analogWrite(analogOutPin, 250);
LCDA.CLEAR();//清屏
delay(100);
LCDA.DrawFullScreen(logo0);
analogWrite(analogOutPin, 10);//
delay(500);
}
