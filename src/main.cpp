
#include "main.h"
#include "definitions.h"

void setup()
{
  strip.begin();
  strip.setBrightness(255);
  strip.show();

  Serial.begin(9600);
  rtc.begin();

  PCICR |= (1 << PCIE2) | (1 << PCIE1);
  PCMSK2 |= (1 << PCINT18) | (1 << PCINT19) | (1 << PCINT20) | (1 << PCINT21);

  sei();  
}

ISR(PCINT2_vect)
{
  char hourResult = hourRotary.process();
  char minuteResult = minuteRotary.process();

  if (hourResult || minuteResult)
  {
    Time tm = rtc.getTime();

    if (hourResult == DIR_CW)
    {
      rtc.setTime(tm.hour == 23 ? 0 : tm.hour + 1, tm.min, tm.sec);
    }
    else if (hourResult == DIR_CCW)
    {
      rtc.setTime(tm.hour == 1 ? 23 : tm.hour - 1, tm.min, tm.sec);
    }
    else if (minuteResult == DIR_CW)
    {
      rtc.setTime(tm.hour, tm.min == 59 ? 0 : tm.min + 1, tm.sec);
    }
    else if (minuteResult == DIR_CCW)
    {
      rtc.setTime(tm.hour, tm.min == 0 ? 59 : tm.min - 1, tm.sec);
    }


    Serial.print("Time: ");
    Serial.print(rtc.getTimeStr());
    Serial.print("\r\n");
  }
}

void loop()
{
  Time time = rtc.getTime();
  
  clearDisplay();

  setDefault();
  setMinute(time.min);
  setHour(time.min, time.hour);
  setExtraMinutes(time.min % 5);

  strip.show();

  delay(100);
}

void printArray( int arr[], int n) {
  

  for (auto i = 0; i < n; i++) {
    strip.setPixelColor(arr[i], defaultColor);
  }
}

void clearDisplay() {
  for(int i = 0; i<NUMPIXELS;i++) {
    strip.setPixelColor(i, offColor);
  }
}

void setDefault() {
  size_t n = sizeof(DEFAULT_LIT_PIXEL)/sizeof(DEFAULT_LIT_PIXEL[0]);
  for (unsigned int i = 0; i < n; i++) {
    strip.setPixelColor(DEFAULT_LIT_PIXEL[i], defaultColor);
  }
}

void setMinute(uint8_t minute) {
  if (minute >= 5 && minute < 10) {
    printArray(MFUENF, size(MFUENF));
    printArray(NACH, size(NACH));
  } else if (minute >= 10 && minute < 15) {
    printArray(MZEHN, size(MZEHN));
    printArray(NACH, size(NACH));
  } else if (minute >= 15 && minute < 20) {
    printArray(VIERTEL, size(VIERTEL));
  } else if (minute >= 20 && minute < 25) {
    printArray(ZWANZIG, size(ZWANZIG));
    printArray(NACH, size(NACH));
  } else if (minute >= 25 && minute < 30) {
    printArray(MFUENF, size(MFUENF));
    printArray(VOR, size(VOR));
    printArray(HALB, size(HALB));
  } else if (minute >= 30 && minute < 35) {
    printArray(HALB, size(HALB));
  } else if (minute >= 35 && minute < 40) {
    printArray(MFUENF, size(MFUENF));
    printArray(NACH, size(NACH));
    printArray(HALB, size(HALB));
  } else if (minute >= 40 && minute < 45) {
    printArray(MZEHN, size(MZEHN));
    printArray(NACH, size(NACH));
    printArray(HALB, size(HALB));
  } else if (minute >= 45 && minute < 50) {
    printArray(DREIVIERTEL, size(DREIVIERTEL));
  } else if (minute >= 50 && minute < 55) {
    printArray(MZEHN, size(MZEHN));
    printArray(VOR, size(VOR));
  } else if (minute >= 55 && minute < 60) {
    printArray(MFUENF, size(MFUENF));
    printArray(VOR, size(VOR));
  }

  if (minute < 5) {
    printArray(UHR, size(UHR));
  }
}

void setHour(uint8_t minute, uint8_t hour) {
  if (hour >= 12) {
    hour -= 12;
  }

  if ((minute < 15 || (minute > 45 && minute < 50)) || (minute >= 20 && minute < 25)) {
    switch(hour) {
      case 1:
        if (minute >= 5) {
          printArray(EINS, size(EINS));
        } else {
          printArray(EIN, size(EIN));
        }
        break;
      case 2:
        printArray(ZWEI, size(ZWEI));
        break;
      case 3:
        printArray(DREI, size(DREI));
        break;
      case 4:
        printArray(VIER, size(VIER));
        break;
      case 5:
        printArray(FUENF, size(FUENF));
        break;
      case 6:
        printArray(SECHS, size(SECHS));
        break;
      case 7:
        printArray(SIEBEN, size(SIEBEN));
        break;
      case 8:
        printArray(ACHT, size(ACHT));
        break;
      case 9:
        printArray(NEUN, size(NEUN));
        break;
      case 10:
        printArray(ZEHN, size(ZEHN));
        break;
      case 11:
        printArray(ELF, size(ELF));
        break;
      case 0:
        printArray(ZWOELF, size(ZWOELF));
        break;
    }
  } else {

    switch(hour) {
      case 1:
        printArray(ZWEI, size(ZWEI));
        break;
      case 2:
        printArray(DREI, size(DREI));
        break;
      case 3:
        printArray(VIER, size(VIER));
        break;
      case 4:
        printArray(FUENF, size(FUENF));
        break;
      case 5:
        printArray(SECHS, size(SECHS));
        break;
      case 6:
        printArray(SIEBEN, size(SIEBEN));
        break;
      case 7:
        printArray(ACHT, size(ACHT));
        break;
      case 8:
        printArray(NEUN, size(NEUN));
        break;
      case 9:
        printArray(ZEHN, size(ZEHN));
        break;
      case 10:
        printArray(ELF, size(ELF));
        break;
      case 11:
        printArray(ZWOELF, size(ZWOELF));
        break;
      case 0:
        if (minute >= 5) {
          printArray(EINS, size(EINS));
        } else {
          printArray(EIN, size(EIN));
        }
        break;
      
    }
  }
}

void setExtraMinutes(uint8_t mins) {
  for (int i = 0; i < 4; i++) {
    strip.setPixelColor(EXTRA_MINUTE_PIXEL_START + i, mins > i ? defaultColor : offColor);
  }
}