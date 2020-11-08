#include "ConnectInternet.h"
#include <EEPROM.h>



WiFiManager wifiManager;
ConnectInternet::ConnectInternet(){
    this->pass="";
    this->ssid="";
}
ConnectInternet::ConnectInternet(char *ssid,char *pass){
    this->pass=pass;
    this->ssid=ssid;
}
void ConnectInternet::setSSID(char *ssid){
  //  ssid = &ssid;
  this->ssid =ssid;
}
void ConnectInternet::setPass(char *pass){
  //  ssid = &ssid;
  this->pass =pass;
}
String ConnectInternet::getSSID(){
  //  ssid = &ssid;
   return WiFi.SSID();
}
String ConnectInternet::getPass(){
  //  ssid = &ssid;
    return  WiFi.psk();
}
void ConnectInternet::connect(){
    if(this->ssid ==""){
      this->ssid =SSID_DEFAULT;  
    }
    wifiManager.autoConnect(this->ssid,this->pass);
}
bool ConnectInternet::isConnected(){
    return (WiFi.status() == WL_CONNECTED ? true:false);
}
bool ConnectInternet::resetConnect(){
    wifiManager.resetSettings();
}
