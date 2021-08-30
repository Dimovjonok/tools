/*
Dmitry Lebedev (Dimovjonok) dmitrylebedev@mail.ru
Create: 29.08.2021
Release:
*/

#ifndef _ICOMMAND_H
#define _ICOMMAND_H

#ifdef _MODE_DEBUG
#define _MODE_DEBUG_ICOMMAND
#endif

/*
Command - инициализация командного процессора
about - общая информация об устройстве (название, назначение, разработчик, версия ПО и т.п.)
*/

struct ICommand {
  virtual void about() = 0;
};

#endif
