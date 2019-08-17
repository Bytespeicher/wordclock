#include <Arduino.h>

#include <Rotary.h>
#include <DS3231.h>

#include "display.h"

Rotary hourRotary = Rotary(2, 3);
Rotary minuteRotary = Rotary(4, 5);

Display * display;

DS3231 * rtc;

volatile int offsetMinute = 0;
volatile int offsetHour = 0;

void updateTime();

void loop();
void setup();