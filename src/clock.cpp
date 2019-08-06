#include "clock.h"

RTClock::RTClock() {
  this->NTPch = new NTPtime("de.pool.ntp.org");

  this->ntpTicker.attach_ms(1000, [this](){ this->updateNTPTime(); });
  //this->timeTicker.attach_ms(1000, [this](){ this->updateTime(); })  
}

RTClock::~RTClock() {

}

void RTClock::updateNTPTime() {
  strDateTime dateTime = NTPch->getNTPtime(1.0, 1);

  if(dateTime.valid){
    this->NTPch->printDateTime(dateTime);
    
    this->hours = dateTime.hour;
    this->minutes = dateTime.minute;
    this->seconds = dateTime.second;
    
    //this->ntpTicker.interval(30000);
    
    if (!receivedTimeOnce) receivedTimeOnce = true;
  }
}

void RTClock::updateTime() {
  seconds++;

  if (seconds >= 60) {
    seconds = 0;
    minutes++;
  }

  if (minutes >= 60) {
    minutes = 0;
    hours++;
  }

  if (hours >= 24) {
    hours = 0;
  }
}