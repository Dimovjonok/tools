/*
Dmitry Lebedev (DumDumbIch) dumdumbich@gmail.com
Create: 08.01.2020
Release:
class Clock
*/

#ifndef _CLOCK_H
#define _CLOCK_H

#ifdef _MODE_DEBUG
#define _MODE_DEBUG_CLOCK
#endif

#include "HAL.h"

class Clock {
  friend class Time;
  private:    
    Clock();
    static unsigned long GetMilli();
    static unsigned long GetMicro();
    static void DelayMicro(unsigned int delay);
    Clock(const Clock& clock);
    const Clock& operator=(const Clock& clock);
};

unsigned long Clock::GetMilli(){
  return millis();
}

unsigned long Clock::GetMicro(){
  return micros();
}

void Clock::DelayMicro(unsigned int delay){
  delayMicroseconds(delay);
}

Clock::Clock(){}
Clock::Clock(const Clock& clock){}
const Clock& Clock::operator=(const Clock& clock){}

#endif