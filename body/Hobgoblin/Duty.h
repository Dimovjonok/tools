/*
Dmitry Lebedev (DumDumbIch) dumdumbich@gmail.com
Create: 11.01.2020
Release:
class Duty
*/

/* 
Данный класс реализует методы, которые обеспечивают исполнение работником его обязанностей. Методы данного класса используются при работе планировщика заданий (sheduler). Класс использует методы, предоставляемые классом Body, которые обеспечивают взаимодействие с физическим миром.
 */
 
 
#ifndef _DUTY_H
#define _DUTY_H

#ifdef _MODE_DEBUG
#define _MODE_DEBUG_DUTY
#endif

// Класс использует API, предоставляемый исключительно классом Milieu
#include "Milieu.h"

class Duty {
  public:
    static bool Prepare();
    static void WaterSupply();
  private:
    Duty();
    Duty(const Duty& duty);
    const Duty& operator=(const Duty& duty);  
};


static bool Duty::Prepare(){
  return true; // It's gag - Replace with the real code
}

static void Duty::WaterSupply(){
#ifdef _MODE_DEBUG_DUTY
    Serial.println("Duty::WaterSupply() - is performed");
#endif  
}

#endif