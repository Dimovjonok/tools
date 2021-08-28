/*
Dmitry Lebedev (DumDumbIch) dumdumbich@gmail.com
Create: 08.01.2020
Release:
interface IError
*/

/* 
Нужен для работы сборщика мусора Scavenger
Реализуется в классах, которые могут создавать и обрабатывать ошибки
 */

#ifndef _IERROR_H
#define _IERROR_H

#ifdef _MODE_DEBUG
#define _MODE_DEBUG_IERROR
#endif

class IError {
  public:
    virtual void ErrorHandler() = 0;
  private:
  protected:
};

#endif