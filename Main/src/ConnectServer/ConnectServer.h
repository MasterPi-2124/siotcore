#ifndef _CONNECTSERVER_H_
#define _CONNECTSERVER_H_

#include "Arduino.h"
#include "../Debug/Debug.h"
#include "Restclient/RestClient.h"
#include <ESP8266httpUpdate.h>
#include "../ConnectInternet/ConnectInternet.h"
#include "../All_info.h"
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
    int updateFirmware(String version);
    String getBoardId();
    int pushData();

};

#endif
