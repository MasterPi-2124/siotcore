#include "Arduino.h"
#ifndef _DEBUG_H_
#define _DEBUG_H_
#define MAX_WIDTH 128
#define MAX_HIGHT 64

 class Debug
 {
     public:
         Debug();
         ~Debug();
         static void LOG_TO_SCREEN(int x,int y,String string);
         static void LOG_PROGRESS_UPDATE(int current,int sum);
         // Data members
 
     private:
         // Data members
 };

 #endif
 
