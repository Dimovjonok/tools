/* 
 Clock.h 
 Version 00 : Edition 02 : Date 14/04/2019 
*/

#ifndef _CLOCK_H
#define _CLOCK_H

#ifdef _MODE_DEBUG
#define _MODE_DEBUG_CLOCK
#endif

#include "Platform.h"

class Clock
{
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