/*
Dmitry Lebedev (DumDumbIch) dumdumbich@gmail.com
Create: 08.01.2020
Release:
class Event
*/

/* 
Экземпляр класса Event может создаваться в процессе выполнения приложения и обрабатывается диспетчером Dispatcher, который выполняет определенные действия в зависимости от типа события и делает запись в журнале (Log_Event). Необработанные события передаются сборщику мусора, который очищает очередь событий и делает запись в журнале (Log_Error)

Предусмотреть поле статуса - создано, прочитано, обработано, не обработано и т.п. - для сборщика мусора
 */

#ifndef _EVENT_H
#define _EVENT_H

#ifdef _MODE_DEBUG
#define _MODE_DEBUG_EVENT
#endif

class Event {
  public:
  private:
  protected:
};

#endif