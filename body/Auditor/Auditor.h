/* 
 Auditor.h 
 Version 00 : Edition 01 : Date 08/06/2019
*/

#ifndef _AUDITOR_H
#define _AUDITOR_H

#ifdef _MODE_DEBUG
//#define _MODE_DEBUG_AUDITOR
#endif

#include "Body.h"  // REMOVE !!!
#include "Staffer.h"


class Auditor : public Staffer
{
  public:
    Auditor();
    void Prepare();
  private:
  protected:
};


extern Auditor auditor;

Auditor::Auditor():Staffer(){}

void Auditor::Prepare(){

#ifdef _MODE_DEBUG_TOSERIAL
  Serial.begin(115200);
#endif

#ifdef _MODULE_BLUETOOTH
  Serial1.begin(115200);
#endif

#ifdef _MODE_DEBUG_AUDITOR
  Serial.println("Main setup()");
#endif

  // if (Indicator::Prepare()){
// #ifdef _MODE_DEBUG_LOCKER
    // Serial.println("Indicator::Prepare() - Ok");
// #endif
    // int actionIndicator = locker.ActionRepeatAlways(1000, Indicator::Action);
  // }
  // if (Status::Prepare()){
// #ifdef _MODE_DEBUG_LOCKER
    // Serial.println("Status::Prepare() - Ok");
// #endif
    // int actionDistance = locker.ActionRepeatAlways(500, Distance::Action);
    // int actionStatus = locker.ActionRepeatAlways(1000, Status::Action);
  // }
}

#endif