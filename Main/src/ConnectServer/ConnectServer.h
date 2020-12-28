#ifndef _CONNECTSERVER_H_
#define _CONNECTSERVER_H_

#include "Arduino.h"
#include "../Debug/Debug.h"
#include "Restclient/RestClient.h"
#include <ESP8266httpUpdate.h>
#include "../ConnectInternet/ConnectInternet.h"
#define BASE_URL "soict-core-01.herokuapp.com"
#define URI_CHECK_COMMUNICATION "/communication"
#define URI_GET_VERSION "/version"
#define URI_GET_BOARD_ID "/boardId"
#define URI_GET_FIRMWARE "http://soict-core-01.herokuapp.com/updateFirmware" 
#define STATUS_CODE_OKE 200
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

};

#endif
