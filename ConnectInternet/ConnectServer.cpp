#include "Arduino.h"

#include "ConnectServer.h"
#include "ConnectInternet.h" 
#include "RestClient.h"

#define CONNECT_SERVER_DEBUG

#ifdef CONNECT_SERVER_DEBUG
    #define DEBUG_CONNECT_PRINT(string) (Serial.println(string))
#endif
#ifndef CONNECT_SERVER_DEBUG
    #define DEBUG_CONNECT_PRINT(string)
#endif

enum CONNECT_SERVER{
    CONNECT_FAIL,
    CONNECT_SUCCESSFULL
};
static ConnectInternet cni;
RestClient client = RestClient(BASE_URL);

ConnectServer::ConnectServer(){}

ConnectServer::~ConnectServer(){}

bool ConnectServer::isServerConnected(){
    while(!cni.isConnected()){
        // statement
        cni.connect();
        DEBUG_CONNECT_PRINT("Waiting for connect...");
        delay(100);
    }
    DEBUG_CONNECT_PRINT("Start connect...");
    String response="";
    int status = client.get(URI_CHECK_COMMUNICATION, &response);
    if(status==200 && response.equalsIgnoreCase("CONNECTED")){
        return CONNECT_SUCCESSFULL;
    }
    DEBUG_CONNECT_PRINT(status+"  "+response);
    return CONNECT_FAIL;
    
}
