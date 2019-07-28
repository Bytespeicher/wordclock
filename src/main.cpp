
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
  // process rotary encoder 
  char hourResult = hourRotary.process();
  char minuteResult = minuteRotary.process();

  // If there is rotation update the hours and minutes corectly
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


    //TODO: Remove Debug stuff
    //char output[5];
    //sprintf(output, "%02d:%02d", hour, minute);
    //Serial.println(output);

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
/*   for (auto i = 0; i < (sizeof(ZWOELF)/2); i++) {
    strip.setPixelColor(ZWOELF[i], defaultColor);
  } */

  //strip.fill(0, 11, strip.Color(255,255,255));
  /* for(int i = 0; i<NUMPIXELS;i++) {
    delay(50);
    strip.setPixelColor(i-1, strip.Color(0,0,0));
    strip.setPixelColor(i,  strip.Color(255,0,0));
  strip.show();
  } */
  strip.show();

/*   Serial.println(time.min % 5);
  Serial.print("Time: ");
  Serial.print(rtc.getTimeStr());
  Serial.print("\r\n"); */

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
    printArray(MFUENF, sizeof(MFUENF)/2);
    printArray(NACH, sizeof(NACH)/2);
  } else if (minute >= 10 && minute < 15) {
    printArray(MZEHN, sizeof(MZEHN)/2);
    printArray(NACH, sizeof(NACH)/2);
  } else if (minute >= 15 && minute < 20) {
    printArray(VIERTEL, sizeof(VIERTEL)/2);
  } else if (minute >= 20 && minute < 25) {
    printArray(ZWANZIG, sizeof(ZWANZIG)/2);
    printArray(NACH, sizeof(NACH)/2);
  } else if (minute >= 25 && minute < 30) {
    printArray(MFUENF, sizeof(MFUENF)/2);
    printArray(VOR, sizeof(VOR)/2);
    printArray(HALB, sizeof(HALB)/2);
  } else if (minute >= 30 && minute < 35) {
    printArray(HALB, sizeof(HALB)/2);
  } else if (minute >= 35 && minute < 40) {
    printArray(MFUENF, sizeof(MFUENF)/2);
    printArray(NACH, sizeof(NACH)/2);
    printArray(HALB, sizeof(HALB)/2);
  } else if (minute >= 40 && minute < 45) {
    printArray(MZEHN, sizeof(MZEHN)/2);
    printArray(NACH, sizeof(NACH)/2);
    printArray(HALB, sizeof(HALB)/2);
  } else if (minute >= 45 && minute < 50) {
    printArray(DREIVIERTEL, sizeof(DREIVIERTEL)/2);
  } else if (minute >= 50 && minute < 55) {
    printArray(MZEHN, sizeof(MZEHN)/2);
    printArray(VOR, sizeof(VOR)/2);
  } else if (minute >= 55 && minute < 60) {
    printArray(MFUENF, sizeof(MFUENF)/2);
    printArray(VOR, sizeof(VOR)/2);
  }

  if (minute < 5) {
    printArray(UHR, sizeof(UHR)/2);
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
          printArray(EINS, sizeof(EINS)/2);
        } else {
          printArray(EIN, sizeof(EIN)/2);
        }
        break;
      case 2:
        printArray(ZWEI, sizeof(ZWEI)/2);
        break;
      case 3:
        printArray(DREI, sizeof(DREI)/2);
        break;
      case 4:
        printArray(VIER, sizeof(VIER)/2);
        break;
      case 5:
        printArray(FUENF, sizeof(FUENF)/2);
        break;
      case 6:
        printArray(SECHS, sizeof(SECHS)/2);
        break;
      case 7:
        printArray(SIEBEN, sizeof(SIEBEN)/2);
        break;
      case 8:
        printArray(ACHT, sizeof(ACHT)/2);
        break;
      case 9:
        printArray(NEUN, sizeof(NEUN)/2);
        break;
      case 10:
        printArray(ZEHN, sizeof(ZEHN)/2);
        break;
      case 11:
        printArray(ELF, sizeof(ELF)/2);
        break;
      case 0:
        printArray(ZWOELF, sizeof(ZWOELF)/2);
        break;
    }
  } else {

    switch(hour) {
      case 1:
        printArray(ZWEI, sizeof(ZWEI)/2);
        break;
      case 2:
        printArray(DREI, sizeof(DREI)/2);
        break;
      case 3:
        printArray(VIER, sizeof(VIER)/2);
        break;
      case 4:
        printArray(FUENF, sizeof(FUENF)/2);
        break;
      case 5:
        printArray(SECHS, sizeof(SECHS)/2);
        break;
      case 6:
        printArray(SIEBEN, sizeof(SIEBEN)/2);
        break;
      case 7:
        printArray(ACHT, sizeof(ACHT)/2);
        break;
      case 8:
        printArray(NEUN, sizeof(NEUN)/2);
        break;
      case 9:
        printArray(ZEHN, sizeof(ZEHN)/2);
        break;
      case 10:
        printArray(ELF, sizeof(ELF)/2);
        break;
      case 11:
        printArray(ZWOELF, sizeof(ZWOELF)/2);
        break;
      case 12:
        if (minute >= 5) {
          printArray(EINS, sizeof(EINS)/2);
        } else {
          printArray(EIN, sizeof(EIN)/2);
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