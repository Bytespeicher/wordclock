#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#define EXTRA_MINUTE_PIXEL_START 110

#define PIN            6
#define NUMPIXELS      114

#define defaultColor CRGB::Olive
#define offColor CRGB::Black
#define brightness 160

template<typename T, int sz>
int size(T(&)[sz])
{
    return sz;
}

static const uint8_t DEFAULT_LIT_PIXEL[] PROGMEM = {109, 108, 106, 105, 104};

static const uint8_t MFUENF[] PROGMEM = {99, 100, 101, 102};
static const uint8_t MZEHN[] PROGMEM = {88, 89, 90, 91};
static const uint8_t FUENFZEHN[] PROGMEM = {88, 89, 90, 91, 99, 100, 101, 102};
static const uint8_t ZWANZIG[] PROGMEM = {92, 93, 94, 95, 96, 97, 98};

static const uint8_t VIERTEL[] PROGMEM = { 83, 82, 81, 80, 79, 78, 77};
static const uint8_t HALB[] PROGMEM = {62, 63, 64, 65};
static const uint8_t DREIVIERTEL[] PROGMEM = {87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77};

static const uint8_t NACH[] PROGMEM = {71, 70, 69, 68};
static const uint8_t VOR[] PROGMEM = {74, 73, 72};

static const uint8_t EINS[] PROGMEM = {46, 47, 48, 49};
static const uint8_t EIN[] PROGMEM = {46, 47, 48};
static const uint8_t ZWEI[] PROGMEM = {44, 45, 46, 47};
static const uint8_t DREI[] PROGMEM = {39, 40, 41, 42};
static const uint8_t VIER[] PROGMEM = {29, 30, 31, 32};
static const uint8_t FUENF[] PROGMEM = {33, 34, 35, 36};
static const uint8_t SECHS[] PROGMEM = {1, 2, 3, 4, 5};
static const uint8_t SIEBEN[] PROGMEM = {49, 50, 51, 52, 53, 54};
static const uint8_t ACHT[] PROGMEM = {17, 18, 19, 20};
static const uint8_t NEUN[] PROGMEM = {25, 26, 27, 28};
static const uint8_t ZEHN[] PROGMEM = {13, 14, 15, 16};
static const uint8_t ELF[] PROGMEM = {22, 23, 24};
static const uint8_t ZWOELF[] PROGMEM = { 56, 57, 58, 59, 60};

static const uint8_t UHR[] PROGMEM = {8, 9, 10};

//static const uint8_t WELCOME[] PROGMEM = {12, 13, 17, 19, 21, 23, 25, 27, 36, 38, 40, 42, 45, 49, 52, 53, 69, 72, 74, 79, 80, 81, 84, 90, 91, 92, 94, 96};
#endif