/*
Dmitry Lebedev (DumDumbIch) dumdumbich@gmail.com
Create: 08.01.2020
Release:
interface IAction
*/

/* 
Нужен для работы планировщика заданий Sheduler. Реализуется в классах, которые обеспечивают функциональность приложения, выполняя предопределенные действия.
!!! Т.к. обязанности вынесены в отдельный класс, возможно, интерфейс IAction не понадобится - пока оставлю его для тестирования.
 */

#ifndef _IACTION_H
#define _IACTION_H

#ifdef _MODE_DEBUG
#define _MODE_DEBUG_IACTION
#endif

class IAction {
  public:
    virtual bool Prepare() = 0;
    virtual void Perform() = 0;
    virtual void Complete() = 0;
};

#endif