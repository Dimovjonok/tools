/*
Dmitry Lebedev (DumDumbIch) dumdumbich@gmail.com
Create: 08.01.2020
Release:
class Error
*/

/* 
Экземпляр класса Error может создаваться в процессе выполнения приложения и обрабатывается сборщиком мусора Scavenger, который выполняет определенные действия в зависимости от типа ошибки и делает запись в журнале (Log_Error).

Предусмотреть поле статуса - создано, прочитано, обработано, не обработано и т.п. - для сборщика мусора
 */
 
#ifndef _ERROR_H
#define _ERROR_H

#ifdef _MODE_DEBUG
#define _MODE_DEBUG_ERROR
#endif

class Error {
  public:
  private:
  protected:
};

#endif