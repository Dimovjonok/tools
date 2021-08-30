/*
Dmitry Lebedev (Dimovjonok) dmitrylebedev@mail.ru
Create: 29.08.2021
Release:
*/

#ifndef _COMMAND_H
#define _COMMAND_H

#ifdef _MODE_DEBUG
#define _MODE_DEBUG_COMMAND
#endif

#include "ICommand.h"

struct Command : ICommand {
  void about() override;
};


void Command::about() {
  Serial.println("sketch $ ");
}

#endif
