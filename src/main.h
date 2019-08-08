#include <Arduino.h>

#include <Adafruit_NeoPixel.h>
#include <Rotary.h>
#include <DS3231.h>

#include "display.h"

Rotary hourRotary = Rotary(2, 3);
Rotary minuteRotary = Rotary(4, 5);

Display * display;

DS3231 rtc (SDA,SCL);

void loop();
void setup();