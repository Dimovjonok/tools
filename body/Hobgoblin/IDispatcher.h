/*
Dmitry Lebedev (DumDumbIch) dumdumbich@gmail.com
Create: 08.01.2020
Release:
interface IDispatcher
*/

/* 
Реализуется в основном классе приложения Employee

Диспетчер - часть основного цикла приложения: реакция на внешние события 
(отслеживание изменений состояния цифровых и аналоговых входов, внешние прерывания, сообщения от внешних устройств, события внутри системы)
Диспетчер проверяет очереди событий всех служб и формирует общую очередь событий - ставит это событие в очередь на обработку (публикует - publish), формирует очередь адресных сообщений (кому-то конкретному) и передает эти события обработчикам соответсвующих служб, затем формирует очеред широковещательных сообщений и передает очередь событий на обработку подписчикам (subscribe - т.е. тем службам, которые знают о возможности возникновения конкретного события и могут выполнить некоторые действия в случае его возникновения). Факт выполнения обработки адресных событий контролирует диспетчер, широковещательных - сборщик мусора.
 */
 
#ifndef _IDISPATCHER_H
#define _IDISPATCHER_H

#ifdef _MODE_DEBUG
#define _MODE_DEBUG_IDISPATCHER
#endif

class IDispatcher {
  public:
    virtual void Dispatcher() = 0;
  private:
  protected:
};

#endif