/*
Dmitry Lebedev (DumDumbIch) dumdumbich@gmail.com
Create: 08.01.2020
Release:
interface IBackground
*/

/* 
Реализуется в основном классе приложения Employee

Выполнение фоновых процессов - часть основного цикла приложения
но совершенно не помню, что здесь хотел реализовать - НАДО ЗАПИСЫВАТЬ ;-)
Видимо, расчитывал, что понадобится в процессе разработки функциональности приложения
Возможно, ведение рабочего журнала, обработка широковещательных событий...
 */

#ifndef _IBACKGROUND_H
#define _IBACKGROUND_H

#ifdef _MODE_DEBUG
#define _MODE_DEBUG_IBACKGROUND
#endif

class IBackground {
  public:
    virtual void Background() = 0;
  private:
  protected:
};

#endif