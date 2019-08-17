
#include "main.h"
#include "definitions.h"

void setup()
{
  Serial.begin(9600);

  PCICR |= (1 << PCIE2) | (1 << PCIE1);
  PCMSK2 |= (1 << PCINT18) | (1 << PCINT19) | (1 << PCINT20) | (1 << PCINT21);

  sei();

  display = new Display();
  
  rtc = new DS3231(SDA,SCL);
  rtc->begin();
}

void updateTime() {
  Time time = rtc->getTime();

  if (offsetHour || offsetMinute ) {
    rtc->setTime(time.hour + offsetHour, time.min + offsetMinute, time.sec);
    offsetHour = 0;
    offsetMinute = 0;
  }

}

ISR(PCINT2_vect)
{
  volatile char hourResult = hourRotary.process();
  volatile char minuteResult = minuteRotary.process();

  if (hourResult || minuteResult)
  {
    //volatile Time tm = rtc->getTime();

    if (hourResult == DIR_CW)
    {
      offsetHour = 1;
      //setTime(tm.hour == 23 ? 0 : tm.hour + 1, tm.min, tm.sec);
    }
    else if (hourResult == DIR_CCW)
    {
      offsetHour = -1;
      //setTime(tm.hour == 1 ? 23 : tm.hour - 1, tm.min, tm.sec);
    }
    else if (minuteResult == DIR_CW)
    {
      offsetMinute = 1;
      //setTime(tm.hour, tm.min == 59 ? 0 : tm.min + 1, tm.sec);
    }
    else if (minuteResult == DIR_CCW)
    {
      offsetMinute = -1;
      //setTime(tm.hour, tm.min == 0 ? 59 : tm.min - 1, tm.sec);
    }
  }
}

void loop()
{
  Time time = rtc->getTime();

  display->setTime(time.hour, time.min);
  display->render(32);

  updateTime();
}