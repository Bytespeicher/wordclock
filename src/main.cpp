
#include "main.h"

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
  delay(1000);
  //strip.fill(0, 11, strip.Color(255,255,255));
  for(int i = 0; i<NUMPIXELS;i++) {
    delay(50);
    strip.setPixelColor(i-1, strip.Color(0,0,0));
    strip.setPixelColor(i,  strip.Color(255,0,0));
  strip.show();
  }
  
  Serial.print("Time: ");
  Serial.print(rtc.getTimeStr());
  Serial.print("\r\n");
}

void updateDisplay(uint8_t pixels[], uint32_t color, bool fade) {
  for (int idx=0; idx<NUMPIXELS; ++idx)
  {
    
  }
}