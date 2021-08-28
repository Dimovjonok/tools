/*
Dmitry Lebedev (DumDumbIch) dumdumbich@gmail.com
Create: 08.01.2020
Release: 
main module Assistant
*/

/* 
Основной цикл приложения - не меняется.
 */
 
#define _MODE_DEBUG
#define _MODE_DEBUG_TOSERIAL

#include "Staffer.h"

Staffer staffer;

// ATTANTION! Block only for debugging
// Testing: stage 1
// #include "HAL.h"



void setup() {
  staffer.Prepare();
  

// ATTANTION! Block only for debugging
// Testing: stage 1
  // HAL::configPinDO(37);
  // HAL::pinToHigh(37);
  // delay(2000);
  // HAL::pinToLow(37);
  // delay(2000);
  // HAL::pinToHigh(37);
  
  
}

void loop() {
  staffer.Sheduler();
  // staffer.Dispatcher();
  // staffer.Background();
  // staffer.Scavenger();
}