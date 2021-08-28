/* 
 IDispatcher.h 
 Version 00 : Edition 01 : Date 04/04/2019
*/

#ifndef _IDISPATCHER_H
#define _IDISPATCHER_H

#ifdef _MODE_DEBUG
#define _MODE_DEBUG_IDISPATCHER
#endif

class IDispatcher
{
  public:
    virtual void Dispatcher() = 0;
  private:
  protected:
};

#endif