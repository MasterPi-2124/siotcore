#include "Arduino.h"
#include "ConnectInternet.h"

#ifndef _CONNECT_SERVER_H
#define _CONNECT_SERVER_H

#ifdef CONNECT_SERVER_DEBUG
    #define DEBUG_CONNECT_PRINT(string) (Serial.println(string))
#endif
#ifndef CONNECT_SERVER_DEBUG
    #define DEBUG_CONNECT_PRINT(string)
#endif

#define BASE_URL "soict-core-01.herokuapp.com"
#define PATH_GET_VERSION ""
#define URI_CHECK_COMMUNICATION "/communication"
#define URI_GET_VERSION "/version"
#define URI_GET_FIRMWARE "http://soict-core-01.herokuapp.com/updateFirmware" 

/*
    Define list error code

*/

//#define DEBUG 1


class ConnectServer
{
private:
    /* data */
public:
    ConnectServer(/* args */);
    ~ConnectServer();
    bool isServerConnected(void);
    int getVersion(void);
    int updateFirmware(void);

};

#endif
