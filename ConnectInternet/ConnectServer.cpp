#include "Arduino.h"
#define CONNECT_SERVER_DEBUG
#include "ConnectServer.h"
#include "ConnectInternet.h" 
#include "RestClient.h"
#include <ESP8266httpUpdate.h>

#define STATUS_CODE_OKE 200

void update_progress(int cur, int total) {
  Serial.printf("Update %d of %d bytes...\n", cur, total);
}

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
int ConnectServer::getVersion(){
  String currentVersion = "";
  int status = client.get(URI_CHECK_COMMUNICATION, &currentVersion);
  if(status == STATUS_CODE_OKE){
    return STATUS_CODE_OKE;
  }
  return status;
}
int ConnectServer::updateFirmware(void){
  ESPhttpUpdate.onProgress(update_progress);
  DEBUG_CONNECT_PRINT("Start upload firmware......");
  t_httpUpdate_return ret = ESPhttpUpdate.update(URI_GET_FIRMWARE, "1.0");
  switch (ret) {
  case HTTP_UPDATE_FAILED:
    DEBUG_CONNECT_PRINT("HTTP_UPDATE_FAILD Error (%d): %s");
    break;
  case HTTP_UPDATE_NO_UPDATES:
    DEBUG_CONNECT_PRINT("HTTP_UPDATE_NO_UPDATES");
    break;
  case HTTP_UPDATE_OK:
    DEBUG_CONNECT_PRINT("HTTP_UPDATE_OK");
    break;
  }
}
