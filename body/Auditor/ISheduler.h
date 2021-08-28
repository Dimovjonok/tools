/* 
 ISheduler.h 
 Version 00 : Edition 03 : Date 27/05/2019
*/

#ifndef _ISHEDULER_H
#define _ISHEDULER_H

#ifdef _MODE_DEBUG
#define _MODE_DEBUG_ISHEDULER
#endif

#include "IActivity.h"
#include "Time.h"

class ISheduler
{
  public:
    virtual void Sheduler() = 0;
    virtual void Sheduler(TimeInMilli currentTime) = 0;
    virtual NumberOfAction ActionRepeatEveryTime(TimeInMilli period, void (*callback)(), CountOfRepeatAction countMax) = 0;
    virtual NumberOfAction ActionRepeatAlways(TimeInMilli period, void (*callback)()) = 0;
    virtual NumberOfAction ActionRepeatOnce(TimeInMilli period, void (*callback)()) = 0;
    virtual NumberOfAction ActionAdd(TypeOfAction type, TimeInMilli period, void (*callback)(), CountOfRepeatAction countMax) = 0;
    virtual NumberOfAction ActionAllocateSpace() = 0;    
};

#endif