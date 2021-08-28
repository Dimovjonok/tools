/* 
 IActivity.h 
 Version 00 : Edition 02 : Date 27/05/2019
*/

#ifndef _IACTIVITY_H
#define _IACTIVITY_H

#ifdef _MODE_DEBUG
#define _MODE_DEBUG_IACTIVITY
#endif

const uint8_t Action_MaxNumber PROGMEM = 10;
const uint8_t Action_NotAssigned PROGMEM = -1;
const uint8_t Action_NotAvailable PROGMEM = -2;

enum class TypeOfAction: uint8_t {
  Empty = 0,
  EveryTime
};

typedef int CountOfRepeatAction;
typedef uint8_t NumberOfAction;
typedef void (*Actor)();

class IActivity
{
  public:

};

#endif