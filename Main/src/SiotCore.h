#ifndef _SIOTCORE_H
#define _SIOTCORE_H_

#include "Arduino.h"
#include "Debug.h"
#include "Board.h"
#include "Conmon.h"
#include "Sensor.h"
#include "ConnectServer.h"
#include "ConnectInternet.h"

class SiotCore
{
private:
    /* data */
    String _ssid;
    String _pass;
    int _baudrate;
    String _version;



public:
    SiotCore(/* args */);
   // SiotCore(String ssid, String pass, int baudrate);
    ~SiotCore();
    void updateFirmware(String version);
    void init();

};


#endif