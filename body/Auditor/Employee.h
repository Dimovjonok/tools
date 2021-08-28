/* 
 Employee.h 
 Version 00 : Edition 02 : Date 14/04/2019
*/

#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#ifdef _MODE_DEBUG
#define _MODE_DEBUG_EMPLOYEE
#endif

#include "Activity.h"
#include "ISheduler.h"

class Employee : public ISheduler
{
  public:
    Employee();
    void Prepare();
    void Sheduler();
    NumberOfAction ActionRepeatEveryTime(TimeInMilli period, void (*actor)(), CountOfRepeatAction countMax);
    NumberOfAction ActionRepeatAlways(TimeInMilli period, void (*actor)());
    NumberOfAction ActionRepeatOnce(TimeInMilli period, void (*actor)());
    void Dispatcher();
    void Scavenger();
    void Background();
  private:
    void Sheduler(TimeInMilli currentTime);
    NumberOfAction ActionAdd(TypeOfAction type, TimeInMilli period, void (*actor)(), CountOfRepeatAction countMax);
    NumberOfAction ActionAllocateSpace();    
    Activity action[Action_MaxNumber];
    TimeInMilli CurrentTime();
    Employee(const Employee& employee);
    const Employee& operator=(const Employee& employee);
};

void Employee::Prepare(){
}

void Employee::Sheduler(){
  Sheduler(CurrentTime());
}

void Employee::Sheduler(TimeInMilli currentTime){
  for (NumberOfAction i = 0; i < Action_MaxNumber; i++){
    if (action[i].type != TypeOfAction::Empty){
      action[i].Timing(currentTime);
    }
  }
}

void Employee::Dispatcher(){
}

void Employee::Scavenger(){
}

void Employee::Background(){
}

NumberOfAction Employee::ActionRepeatEveryTime(TimeInMilli period, void (*actor)(), CountOfRepeatAction countMax){
  return ActionAdd(TypeOfAction::EveryTime, period, actor, countMax);
}

NumberOfAction Employee::ActionRepeatAlways(TimeInMilli period, void (*actor)()){
  return ActionAdd(TypeOfAction::EveryTime, period, actor, -1);
}

NumberOfAction Employee::ActionRepeatOnce(TimeInMilli period, void (*actor)()){
  return ActionAdd(TypeOfAction::EveryTime, period, actor, 1);
}

NumberOfAction Employee::ActionAdd(TypeOfAction type, TimeInMilli period, void (*actor)(), CountOfRepeatAction countMax){
  NumberOfAction i = ActionAllocateSpace();
  if (i != -1){
    action[i].type = type;
    action[i].period = period;
    action[i].count = 0;
    action[i].countMax = countMax;
    action[i].previousTime = CurrentTime();
    action[i].actor = actor;
    return i;
  } else return -1;
}

NumberOfAction Employee::ActionAllocateSpace(){
  for (NumberOfAction i = 0; i < Action_MaxNumber; i++){
    if (action[i].type == TypeOfAction::Empty){
      return i;
    }
  }  
  return Action_NotAvailable;
}

TimeInMilli Employee::CurrentTime(){
  return Time::CurrentMilli();
}

Employee::Employee(){};
Employee::Employee(const Employee& employee){};
const Employee& Employee::operator=(const Employee& employee){};

#endif