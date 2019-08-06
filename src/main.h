#include <Arduino.h>
//#include <Adafruit_NeoPixel.h>


#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h> 

#include "definitions.h"
#include "display.h"
#include "clock.h"

Display * display = new Display();
RTClock * rtc = new RTClock();

void loop();
void setup();