
#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);   // All Boards without Reset of the Display

 
const int AirValue = 620;   //you need to replace this value with Value_1
const int WaterValue = 310;  //you need to replace this value with Value_2
int soilMoistureValue = 0;
int soilmoisturepercent=0;
void setup() {
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
   u8g2.begin();
}
void loop() {
   u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_ncenB08_tr);
soilMoistureValue = analogRead(A0);  //put Sensor insert into soil
Serial.println(soilMoistureValue);
soilmoisturepercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
if(soilmoisturepercent >= 100)
{
  Serial.println("100 %");
  
 u8g2.drawStr(4,10,"Soil");
 u8g2.drawStr(4,30,"Moisture");
  
u8g2.drawStr(4,50,"%");
  u8g2.sendBuffer();
  
  delay(250);
  u8g2.clearBuffer();
}
else if(soilmoisturepercent <=0)
{
  Serial.println("0 %");
  
 u8g2.drawStr(4,10,"Soil");
u8g2.drawStr(4,30,"Moisture");
  
u8g2.drawStr(4,50,"0 %");
   u8g2.sendBuffer();
 
  delay(250);
  u8g2.clearBuffer();	
}
else if(soilmoisturepercent >0 && soilmoisturepercent < 100)
{
  Serial.print(soilmoisturepercent);
  Serial.println("%");
  
 u8g2.drawStr(4,10,"Soil");
u8g2.drawStr(4,30,"Moisture");

u8g2.drawStr(4,50,"0 %");
   u8g2.sendBuffer();
 
  delay(250);
  u8g2.clearBuffer();	
}  
}