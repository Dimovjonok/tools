/* 
 Worker.h 
 Version 00 : Edition 01 : Date 04/04/2019
*/

#ifndef _WORKER_H
#define _WORKER_H

#ifdef _MODE_DEBUG
#define _MODE_DEBUG_WORKER
#endif

class Worker
{
  public:
    uint16_t name;
    uint8_t craft;
    uint8_t body;
};

class Workplace
{
  public:
    uint8_t floor;
    uint8_t room;
    uint8_t place;
};

class StaffMember
{
  public:
    Worker who;
    Workplace where;
};

#endif