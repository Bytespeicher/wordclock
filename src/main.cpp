
#include "main.h"
#include "definitions.h"

void setup()
{
  Serial.begin(9600);
  rtc.begin();

  PCICR |= (1 << PCIE2) | (1 << PCIE1);
  PCMSK2 |= (1 << PCINT18) | (1 << PCINT19) | (1 << PCINT20) | (1 << PCINT21);

  sei();

  display = new Display();
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

  display->setTime(time.hour, time.min);
  display->render(32);
}