#include "Board.h"
#include <EEPROM.h>
#include <ESP8266WiFi.h>
void writeString(int address, String data)
{
  EEPROM.begin(512);
  int stringSize = data.length();
  for(int i=0;i<stringSize;i++)
  {
    EEPROM.write(address+i, data[i]);
  }
  EEPROM.write(address + stringSize,'\0');   //Add termination null character
  EEPROM.commit();  
}
Board::Board(){};
Board::~Board(){};
void Board::getChipInfo(ESP8266_Info *esp_info){
    esp_info->chipId = ESP.getChipId();
    esp_info->coreVersion=ESP.getCoreVersion();
    esp_info->sketchSize =ESP.getSketchSize();
    esp_info->freeSketchSize =ESP.getFreeSketchSpace();
}

bool Board::checkActived(){
  EEPROM.begin(512);
  char status[] = "actived";
  int startAddress = 10;
  int index =0;
  while(status[index] == EEPROM.read(startAddress+index) && status[index] !='\0'){
    Serial.print(EEPROM.read(startAddress+index));
    index++;
  }
  if(index ==7) return true;
  return false;
}
void Board::getBoardInfo(Board_Info *board_info){
  
}
