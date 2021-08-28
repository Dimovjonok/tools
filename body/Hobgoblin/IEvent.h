/*
Dmitry Lebedev (DumDumbIch) dumdumbich@gmail.com
Create: 08.01.2020
Release:
interface IEvent
*/

/* 
Нужен для работы диспетчера событий Dispatcher
Реализуется в классах, которые могут создавать и обрабатывать события
 */
 
#ifndef _IEVENT_H
#define _IEVENT_H

#ifdef _MODE_DEBUG
#define _MODE_DEBUG_IEVENT
#endif

class IEvent {
  public:
    virtual void EventHandler() = 0;
  private:
  protected:
};

#endif