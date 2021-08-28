/*
Dmitry Lebedev (DumDumbIch) dumdumbich@gmail.com
Create: 08.01.2020
Release:
class Time
*/

#ifndef _TIME_H
#define _TIME_H

#ifdef _MODE_DEBUG
#define _MODE_DEBUG_TIME
#endif

#include "Clock.h"

typedef unsigned long TimeInMilli;
typedef unsigned long TimeInMicro;

class Time {
  public:
    static TimeInMilli CurrentMilli();
    static TimeInMicro CurrentMicro();
    static void DelayMicro(TimeInMicro delay);
  private:
    Time();
    Time(const Time& time);
    const Time& operator=(const Time& time);
};

TimeInMilli Time::CurrentMilli(){
  return Clock::GetMilli();
}

TimeInMicro Time::CurrentMicro(){
  return Clock::GetMicro();
}

static void Time::DelayMicro(TimeInMicro delay){
  Clock::DelayMicro(delay);
}

Time::Time(){}
Time::Time(const Time& time){}
const Time& Time::operator=(const Time& time){}

#endif