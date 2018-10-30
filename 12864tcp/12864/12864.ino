
#include "ESP8266WiFi.h"
#include <U8g2lib.h>
const char* ssid     = "Len";
const char* password = "11223355";
uint8_t testb[1024]={};
WiFiClient client;

U8G2_ST7920_128X64_F_SW_SPI u8g2(U8G2_R0, /* clock=*/ 2, /* data=*/ 0, /* CS=*/ 4, /* reset=*/ 5);
void setup() {
  WiFi.begin(ssid, password);
  u8g2.begin();
}

void loop() {
  if(WiFi.status()!=WL_CONNECTED){
    WiFi.begin(ssid, password);
    }
  if(WiFi.status()==WL_CONNECTED&&!client.connected())
  {
    const int httpPort = 1884;
    client.connect("192.168.43.133", httpPort);
  }
  while(client.available()){
    client.read(testb,1024);
    u8g2.firstPage();
    do {
      u8g2.drawXBMP(0,0, 128, 64, testb);
      //u8g2.drawXBM(0,0, 128, 64, testb);
    } while (u8g2.nextPage());
  }
}
