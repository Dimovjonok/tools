/*
Dmitry Lebedev (Dimovjonok) dmitrylebedev@mail.ru
Create: 28.08.2021
Release:
*/

/*
Основной класс приложения - сотрудник, выполняющий конкретные обязанности
!!! Т.к. обязанности вынесены в отдельный класс, возможно, класс Staffer не понадобится - пока оставлю его для тестирования.
 */

#ifndef _STAFFER_H
#define _STAFFER_H

#ifdef _MODE_DEBUG
#define _MODE_DEBUG_STAFFER
#endif


#include "Employee.h"
#include "Duty.h"


class Staffer : public Employee {
  public:
    Staffer();
    void Prepare();
  private:
    // Testing: stage 2
    Pin* pin;
  protected:
};


extern Staffer staffer;

Staffer::Staffer():Employee(){}

void Staffer::Prepare(){

}
#endif
