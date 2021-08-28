/* 
 IScavenger.h 
 Version 00 : Edition 01 : Date 04/04/2019
*/

#ifndef _ISCAVENGER_H
#define _ISCAVENGER_H

#ifdef _MODE_DEBUG
#define _MODE_DEBUG_ISCAVENGER
#endif

class IScavenger
{
  public:
    virtual void Scavenger() = 0;
  private:
  protected:
};

#endif