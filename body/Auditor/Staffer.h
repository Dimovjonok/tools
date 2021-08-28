/* 
 Staffer.h 
 Version 00 : Edition 01 : Date 04/04/2019
*/

#ifndef _STUFFER_H
#define _STUFFER_H

#ifdef _MODE_DEBUG
#define _MODE_DEBUG_STUFFER
#endif

#include "Employee.h"

class Staffer : public Employee
{
  public:
    Staffer();
    ~Staffer();
  private:
  protected:
};

Staffer::Staffer():Employee(){}

Staffer::~Staffer(){}


#endif