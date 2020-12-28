#include "ConnectServer.h"


void update_progress(int cur, int total) {
  Debug::LOG_PROGRESS_UPDATE(cur,total);
}
void update_finished() {
  Debug::LOG_TO_SCREEN(0,10,"Firmeware update successfully!");
  delay(1000);
  Debug::LOG_TO_SCREEN(0,10,"");
  

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
String ConnectServer::getBoardId(){
  String boardID = "";
  int status = client.get(URI_GET_BOARD_ID, &boardID);
  if(status == STATUS_CODE_OKE){
    return boardID;
  }
  return "";
  
}
int ConnectServer::updateFirmware(String version){
  
  ESPhttpUpdate.onEnd(update_finished);
  ESPhttpUpdate.onProgress(update_progress);
  ESPhttpUpdate.onError(update_error);
  Debug::LOG_TO_SCREEN(0,0,"Start upload firmware......");
  t_httpUpdate_return ret = ESPhttpUpdate.update(URI_GET_FIRMWARE, version);
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
