#ifndef _BOARD_H
#define _BOARD_H
#include"Arduino.h"
struct ESP8266_Info
{
    /* data */
    int chipId;
    unsigned int sketchSize;
    unsigned int freeSketchSize;
    String coreVersion;
};
struct Board_Info{
  int chipId;
  char* boardId;
  char* currentFirmware;
  bool checkActived;
  
};
class Board
{
private:
public:
    Board();
    ~Board();
    void getChipInfo(ESP8266_Info *esp_info);
    bool checkActived();
    void getBoardInfo(Board_Info *board_info);

};





#endif
