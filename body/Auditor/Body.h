/* 
 Body.h: Porter Proto_01
 Version 00 : Edition 01 : Date 08/06/2019
*/

#ifndef _BODY_H
#define _BODY_H

#ifdef _MODE_DEBUG
#define _MODE_DEBUG_BODY
#endif

#include "Platform.h"

typedef uint8_t NumberOfModules;

// Модуль Bluetooth для организации обмена информацией
// с компьютером, планшетом, смартфоном

#define MODULE_BLUETOOTH

// Радиомодуль для организации среды обмена информацией

#include "NRF24L01.h"
#define _RADIO_nRF24L01
  const NumberOfModules Modules_Radio = 1;

#ifdef _ARDUINO_PRO_MINI
  const PinsOfPlatform pinCE[Modules_Radio] = {4};
  const PinsOfPlatform pinSS[Modules_Radio] = {10};
#endif

#ifdef _ARDUINO_MEGA2560
  const PinsOfPlatform pinCE[Modules_Radio] = {49};
  const PinsOfPlatform pinSS[Modules_Radio] = {53};
#endif

#endif