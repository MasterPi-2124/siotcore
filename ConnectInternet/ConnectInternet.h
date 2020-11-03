

#include "Arduino.h"
#include "WiFiManager.h"


#define SSID_DEFAULT "SOICT_CORE_BOARD"
class ConnectInternet
{
private:
    /* data */
public:
    char *ssid;
    char *pass;
    ConnectInternet();
    ConnectInternet(char *ssid,char *pass);
    void setSSID(char *ssid);
    void setPass(char *pass);
    String getSSID();
    String getPass();
    void connect();
    bool isConnected();
    bool resetConnect();
};
