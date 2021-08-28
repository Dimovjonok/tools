/* 
 Activity.h 
 Version 00 : Edition 03 : Date 27/05/2019
*/

#ifndef _ACTIVITY_H
#define _ACTIVITY_H

#ifdef _MODE_DEBUG
#define _MODE_DEBUG_ACTIVITY
#endif

#include "Platform.h"
#include "Time.h"
#include "IActivity.h"

class Activity
{
  public:
    Activity();
    void Timing();
    void Timing(TimeInMilli currentTime); 
    Actor actor; //void (*callback)();
    TypeOfAction type;
    CountOfRepeatAction count;
    CountOfRepeatAction countMax;
    TimeInMilli period;
    TimeInMilli previousTime;
  private:
    TimeInMilli CurrentTime();
  protected:
    TimeInMicro CurrentMoment();    
};

Activity::Activity(){
  type = TypeOfAction::Empty;
}

void Activity::Timing(){
  Timing(CurrentTime());
}

void Activity::Timing(TimeInMilli currentTime){
  if (currentTime - previousTime >= period){
    switch (type){
      case TypeOfAction::EveryTime:{
        (*actor)();
        break;
      }
    }
    previousTime = currentTime;
    count++;
  }
  if (countMax > -1 && count >= countMax){
    type = TypeOfAction::Empty;    
  }
}

TimeInMilli Activity::CurrentTime(){
  return Time::CurrentMilli();
}

TimeInMicro Activity::CurrentMoment(){
  return Time::CurrentMicro();
}

#endif