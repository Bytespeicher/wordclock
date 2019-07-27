#include <Arduino.h>

#include <Adafruit_NeoPixel.h>
#include <Rotary.h>
#include <DS3231.h>

#define PIN            6
#define NUMPIXELS      114

Rotary hourRotary = Rotary(2, 3);
Rotary minuteRotary = Rotary(4, 5);

DS3231 rtc (SDA,SCL);

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_RGB + NEO_KHZ800);
uint8_t currentPixels[NUMPIXELS];

uint32_t defaultColor = Adafruit_NeoPixel::Color(255,255,255);

void loop();
void setup();


void updateDisplay(uint8_t pixels[], uint32_t color = defaultColor, bool fade = false);