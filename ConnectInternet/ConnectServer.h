#include "Arduino.h"
#include "ConnectInternet.h"

#ifndef _CONNECT_SERVER_H
#define _CONNECT_SERVER_H

#define BASE_URL "soict-core-01.herokuapp.com"
#define PATH_GET_VERSION ""
#define URI_CHECK_COMMUNICATION "/communication"
#define PATH_GET_FIRMWARE "" 

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