/*
Dmitry Lebedev (DumDumbIch) dumdumbich@gmail.com
Create: 08.01.2020
Release:
class Milieu
*/

/* 
Класс Milieu (окружающая обстановка, окружающая среда) описывает рабочее место работника и то, с чем ему приходится работать.
Класс предоставляет методы для класса Duty, который реализует исполнение работником его обязанностей.
 */
 
 
#ifndef _MILIEU_H
#define _MILIEU_H

#ifdef _MODE_DEBUG
#define _MODE_DEBUG_MILIEU
#endif

#include "Pump.h"

class Milieu {
  public:
    static bool Prepare();
    static bool Testing();
  private:
    static Pump* pumpWaterWell;
    
    Milieu();
    Milieu(const Milieu& milieu);
    const Milieu& operator=(const Milieu& milieu);  
};


static bool Milieu::Prepare(){
  pumpWaterWell = new Pump(37);
  return true; // It's gag - Replace with the real code  
}

static bool Milieu::Testing(){
  return true; // It's gag - Replace with the real code  
}

#endif