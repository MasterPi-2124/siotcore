#include "Arduino.h"
#include "Debug.h"
#include "ConnectServer.h"
#include "ConnectInternet.h" 
#include "RestClient.h"
#include <ESP8266httpUpdate.h>

#define STATUS_CODE_OKE 200

void update_progress(int cur, int total) {
  Debug::LOG_PROGRESS_UPDATE(cur,total);
}
void update_finished() {
  Debug::LOG_TO_SCREEN(0,10,"Firmeware update successfully!");
}
void update_error(int err) {
  Debug::LOG_TO_SCREEN(0,10,"Firmeware update error!");
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
        Debug::LOG_TO_SCREEN(0,0,"Waiting for connect...");
        delay(100);
    }
    Debug::LOG_TO_SCREEN(0,0,"Start connect...");
    String response="";
    int status = client.get(URI_CHECK_COMMUNICATION, &response);
    if(status==200 && response.equalsIgnoreCase("CONNECTED")){
        return CONNECT_SUCCESSFULL;
    }
    String txt =status+"  "+response;
    Debug::LOG_TO_SCREEN(0,0,txt);
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
  
  ESPhttpUpdate.onEnd(update_finished);
  ESPhttpUpdate.onProgress(update_progress);
  ESPhttpUpdate.onError(update_error);
  Debug::LOG_TO_SCREEN(0,0,"Start upload firmware......");
  t_httpUpdate_return ret = ESPhttpUpdate.update(URI_GET_FIRMWARE, "1.0");
  switch (ret) {
  case HTTP_UPDATE_FAILED:
    Debug::LOG_TO_SCREEN(0,0,"HTTP_UPDATE_FAILD Error");
    break;
  case HTTP_UPDATE_NO_UPDATES:
    Debug::LOG_TO_SCREEN(0,0,"HTTP_UPDATE_NO_UPDATES");
    break;
  case HTTP_UPDATE_OK:
    Debug::LOG_TO_SCREEN(0,0,"HTTP_UPDATE_OK");
    break;
  }
}
