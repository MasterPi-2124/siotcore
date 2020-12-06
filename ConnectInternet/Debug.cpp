#include "Debug.h"
#include <Wire.h>  // include wire library (for I2C devices such as the SSD1306 display)
#include "SSD1306Wire.h"
static SSD1306Wire display(0x3c, 5, 4);  // ADDRESS, SDA, SCL

Debug::Debug(){};
Debug::~Debug(){};
void Debug::LOG_TO_SCREEN(int x,int y,String string){
    display.init();
    display.displayOn(); 
    if(x >128) x=0;
    if(y>64)   y=0;
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    //display.setTextAlignment(TEXT_ALIGN_CENTER_BOTH);
    display.drawStringMaxWidth(x,y,MAX_WIDTH,string);
    display.display();
}
void Debug::LOG_PROGRESS_UPDATE(int current,int sum){
   delay(10);
   display.init();
   display.displayOn(); 
   display.clear();
  int progress = current*100/sum;
  Serial.println(String(current)+"   "+String(sum)+"    "+String(progress));
  // draw the progress bar 
  display.drawProgressBar(0, 32, 120, 10, progress);
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.drawString(64, 15, "Update..."+String(progress) + "%");
  display.drawString(64, 50, String(current)+" of "+String(sum) + "kb");
  display.display();
}
