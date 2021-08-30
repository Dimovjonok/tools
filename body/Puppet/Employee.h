/*
Dmitry Lebedev (Dimovjonok) dmitrylebedev@mail.ru
Create: 28.08.2021
Release:
*/

/*
Базовый класс для Staffer - реализация общего для всех приложений функционала
Данный класс не может использоваться как главные класс приложения (нельзя создать экземпляр этого класса).

Должен реализовывать следующие интерфейсы:
ISheduler
IDispatcher
IBackground
IScavenger

 */

#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#ifdef _MODE_DEBUG
#define _MODE_DEBUG_EMPLOYEE
#endif

#include "Action.h"
#include "ISheduler.h"

class Employee : public ISheduler {
  public:
    void Prepare();
    void Sheduler();
    void Dispatcher();
    void Scavenger();
    void Background();
    NumberOfAction ActionRepeatEveryTime(TimeInMilli period, void (*actor)(), CountOfRepeatAction countMax);
    NumberOfAction ActionRepeatAlways(TimeInMilli period, void (*actor)());
    NumberOfAction ActionRepeatOnce(TimeInMilli period, void (*actor)());
  protected:
    Employee();
  private:
    void Sheduler(TimeInMilli currentTime);
    NumberOfAction ActionAdd(TypeOfAction type, TimeInMilli period, void (*actor)(), CountOfRepeatAction countMax);
    NumberOfAction ActionAllocateSpace();
    Action action[ACTION_MaxNumber];
    TimeInMilli CurrentTime();
    Employee(const Employee& employee);
    const Employee& operator=(const Employee& employee);
};

void Employee::Prepare(){}

void Employee::Sheduler(){
  for (NumberOfAction i = 0; i < ACTION_MaxNumber; i++){
    if (action[i].type != TypeOfAction::Empty){
      action[i].Update();
    }
  }
}

void Employee::Sheduler(TimeInMilli currentTime) {
  for (NumberOfAction i = 0; i < ACTION_MaxNumber; i++){
    if (action[i].type != TypeOfAction::Empty){
      action[i].Update(currentTime);
    }
  }
}

void Employee::Dispatcher(){}

void Employee::Scavenger(){}

void Employee::Background(){}

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
  for (NumberOfAction i = 0; i < ACTION_MaxNumber; i++){
    if (action[i].type == TypeOfAction::Empty){
      return i;
    }
  }
  return ACTION_NotAvailable;
}

TimeInMilli Employee::CurrentTime(){
  return Time::CurrentMilli();
}

Employee::Employee(){};
Employee::Employee(const Employee& employee){};
const Employee& Employee::operator=(const Employee& employee){};

#endif
