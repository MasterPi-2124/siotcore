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
  bool autoUpdate;
  
};
class Board
{
private:
public:
    ESP8266_Info esp;
    Board_Info board;
    Board();
    ~Board();
    void getChipInfo();
    bool checkActived();
    void getBoardInfo();

};





#endif
