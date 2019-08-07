#include <Arduino.h>
#include <ESP8266mDNS.h>
#include <ESP8266WiFi.h>
#include <FS.h>
#include <ESPAsyncWebServer.h>
#include <ESPAsyncTCP.h>
#include <ArduinoJson.h>

class Webserver {
  private:
    AsyncWebServer * server = new AsyncWebServer(80);
    AsyncWebSocket * ws = new AsyncWebSocket("/ws");

  public:
    Webserver();
    ~Webserver();
};