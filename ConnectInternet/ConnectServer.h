#ifndef _CONNECT_SERVER_H_
#define _CONNECT_SERVER_H_

#include "Arduino.h"
#include "ConnectInternet.h"
#define BASE_URL "soict-core-01.herokuapp.com"
#define PATH_GET_VERSION ""
#define URI_CHECK_COMMUNICATION "/communication"
#define URI_GET_VERSION "/version"
#define URI_GET_BOARD_ID "/boardId"
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
    String getBoardId();

};

#endif
