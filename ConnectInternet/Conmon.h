#ifndef _CONMON_H
#define _CONMON_H
#include<Arduino.h>
void read_eeprom(int s_address,int length,byte *value);
void write_eeprom(int s_address,int length,byte *value);
#endif
