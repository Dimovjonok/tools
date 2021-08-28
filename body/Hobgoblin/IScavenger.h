/*
Dmitry Lebedev (DumDumbIch) dumdumbich@gmail.com
Create: 08.01.2020
Release:
interface IScavenger
*/

/* 
Реализуется в основном классе приложения Employee

Сборщик мусора - часть основного цикла приложения
По завершении обработки очередь событий передается сборщику мусора (Scavenger), который анализирует очередь на предмет наличия не обработанных "безхозных" событий, выдает соответствующую диагностику или делает запись в журнале, а затем полностью очищает очередь событий (либо только от обработанных событий - есть риск заполнения очереди и потери событий - необходимо периодически полностью очищать очередь и выдавать соответствующую диагностику - реализация этого варианта пока не предусматривается).
 */

#ifndef _ISCAVENGER_H
#define _ISCAVENGER_H

#ifdef _MODE_DEBUG
#define _MODE_DEBUG_ISCAVENGER
#endif

class IScavenger {
  public:
    virtual void Scavenger() = 0;
  private:
  protected:
};

#endif