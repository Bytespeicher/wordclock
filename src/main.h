#include <Arduino.h>

#include <Adafruit_NeoPixel.h>
#include <Wire.h>

#include "RTClib.h"

#define PIN            D4
#define NUMPIXELS      114

#define defaultColor Adafruit_NeoPixel::Color(255,0,0)
#define offColor Adafruit_NeoPixel::Color(0,0,0)
 
RTC_DS3231 rtc;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

uint8_t currentPixels[NUMPIXELS];

template<typename T, int sz>
int size(T(&)[sz])
{
    return sz;
}

void loop();
void setup();

void clearDisplay();
void setDefault();
void setMinute(uint8_t minute);
void setHour(uint8_t minute, uint8_t hour);
void setExtraMinutes(uint8_t mins);