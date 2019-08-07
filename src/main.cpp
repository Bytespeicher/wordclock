#include "main.h"
extern "C" {
  #include "user_interface.h"
}

#include "definitions.h"

void setup()
{
  wifi_set_sleep_type(LIGHT_SLEEP_T);
  
  Serial.begin(9600);
  
  display->printArray(WELCOME, size(WELCOME));
  display->instantCommitChanges();
  
  
  delay(1000);
  
  AsyncWebServer server(80);
  DNSServer dns;
  AsyncWiFiManager wifiManager(&server,&dns);

  WiFi.hostname("wordclock");
  
  rtc->queryTime();

  ota->checkForUpdate();
}

void loop()
{
  if (rtc->gotTimeOnce()) {
    display->setTime(rtc->getHours(), rtc->getMinutes());
    display->render(10);
  }
}