/*
Dmitry Lebedev (DumDumbIch) dumdumbich@gmail.com
Create: 08.01.2020
Release:
class Staffer
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

// #include "Relays.h"

// Testing: stage 2
#include "Pin.h"

// Testing: stage 3
#include "Modem.h"


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
#ifdef _MODE_DEBUG_STAFFER
  Serial.begin(115200);
  Serial.println("Main setup()");
  
// Testing: stage 2
  // pin = new Pin(33, DirectOfPin::Output);
  // pin->levelToHigh();
  // delay(2000);
  // pin->toggleLevel();
  // delay(2000);
  // pin->toggleLevel();  
#endif

  Modem* modem = new Modem(portModem[0],pinModemPower[0],pinModemReset[0]);
  modem->init();
  modem->sendSMS("I'm droid Fedor");

  if (Duty::Prepare()){
#ifdef _MODE_DEBUG_STAFFER
    Serial.println("Duty::Prepare() - Ok");
#endif
    int dutyWaterSupply = staffer.ActionRepeatAlways(2000, Duty::WaterSupply);    
  }  
}
#endif