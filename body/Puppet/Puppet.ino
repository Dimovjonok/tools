/*
Dmitry Lebedev (Dimovjonok) dmitrylebedev@mail.ru
Create: 28.08.2021
Release:
*/

#define _MODE_DEBUG

#include "Staffer.h"

Staffer staffer;

void setup() {
  staffer.Prepare();

}

void loop() {
  staffer.Sheduler();
}
