#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);


void setup() 
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

}

void loop() 
{
  display.setTextSize(1);
  display.setTextColor(WHITE);
//  display.setCursor(4,4);
//  display.println("Shivansh Mishra");
display.drawCircle(32,32,8,WHITE);
  display.display();


}
