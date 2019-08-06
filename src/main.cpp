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
  
  WiFiManager wifiManager;
  wifiManager.autoConnect("Wordclock by Till");
  WiFi.hostname("wordclock");
  
  //wifiManager.resetSettings();
  //return;

}

void loop()
{
  //rtc->Tick();
  //Serial.println(rtc->gotTimeOnce());
  if (rtc->gotTimeOnce()) {
    display->setTime(rtc->getHours(), rtc->getMinutes());
    display->render(15);
  }
}