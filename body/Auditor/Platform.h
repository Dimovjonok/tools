/* 
 Platform.h 
 Version 00 : Edition 03 : Date 26/05/2019
*/

#ifndef _PLATFORM_H
#define _PLATFORM_H

#ifdef _MODE_DEBUG
#define _MODE_DEBUG_PLATFORM
#endif

#include <Arduino.h>
#include <avr/pgmspace.h>

// Базовый модуль
//#define _ARDUINO_PRO_MINI
#define _ARDUINO_MEGA2560
//#define _ARDUINO_DUE
/* 
*/

typedef uint8_t NumberOfPin;
typedef uint8_t PinsOfPlatform;
typedef uint8_t ModeOfPin;
//typedef uint8_t TypeOfPin;

const uint8_t PA = 0;
const uint8_t PB = 1;
const uint8_t PC = 2;
const uint8_t PD = 3;
const uint8_t PE = 4;
const uint8_t PF = 5;
const uint8_t PG = 6;
const uint8_t PH = 7;
const uint8_t PJ = 8;
const uint8_t PK = 9;
const uint8_t PL = 10;

const uint8_t P0 = 0;
const uint8_t P1 = 1;
const uint8_t P2 = 2;
const uint8_t P3 = 3;
const uint8_t P4 = 4;
const uint8_t P5 = 5;
const uint8_t P6 = 6;
const uint8_t P7 = 7;

#ifdef _ARDUINO_PRO_MINI
  const uint8_t digitalIO = 20;
  const uint8_t avrPort[digitalIO] = {PD,PD,PD,PD,PD,PD,PD,PD,PB,PB,PB,PB,PB,PB,PC,PC,PC,PC,PC,PC};
  const uint8_t avrLine[digitalIO] = {P0,P1,P2,P3,P4,P5,P6,P7,P0,P1,P2,P3,P4,P5,P0,P1,P2,P3,P4,P5};
#endif

#ifdef _ARDUINO_MEGA2560
  const uint8_t digitalIO = 70;
//  const uint8_t avrPort[digitalIO] = {PD,PD,PD,PD,PD,PD,PD,PD,PB,PB,PB,PB,PB,PB,PC,PC,PC,PC,PC,PC};
//  const uint8_t avrLine[digitalIO] = {P0,P1,P2,P3,P4,P5,P6,P7,P0,P1,P2,P3,P4,P5,P0,P1,P2,P3,P4,P5};
#endif

#define ANALOG 0
#define DIGITAL 1

class Platform
{
  public:
    // static void PinModeDigitalIn(PinsOfChip pin);
    // static void PinModeDigitalOut(PinsOfChip pin);
    // static void PinLevelSetHigh(PinsOfChip pin);
    // static void PinLevelSetLow(PinsOfChip pin);
    // static bool PinLevelGet(PinsOfChip pin);
    // static void PinLevelPut(PinsOfChip pin, bool level);
//    static void PinAnalogIn(PinsOfChip pin);
//    static void PinAnalogOut(PinsOfChip pin);
//    static void PinValueSet(PinsOfChip pin);
//    static void PinValueGet(PinsOfChip pin);    
  private:
    // static bool PinCheckConfig(PinsOfChip pin, TypeOfPin type, ModeOfPin mode);
  protected:
};


// void Platform::PinModeDigitalIn(PinsOfChip pin){
  // if (PinCheckConfig(pin,DIGITAL,INPUT)) pinMode(pin, INPUT);
// }

// void Platform::PinModeDigitalOut(PinsOfChip pin){
  // if (PinCheckConfig(pin,DIGITAL,OUTPUT)) pinMode(pin, OUTPUT);
// }

// void Platform::PinLevelSetHigh(PinsOfChip pin){
  // digitalWrite(pin, HIGH);
// }

// void Platform::PinLevelSetLow(PinsOfChip pin){
  // digitalWrite(pin, LOW);
// }

// bool Platform::PinLevelGet(PinsOfChip pin){
  // return digitalRead(pin);
// }

// void Platform::PinLevelPut(PinsOfChip pin, bool level){
  // digitalWrite(pin, level);
// }

// bool Platform::PinCheckConfig(PinsOfChip pin, TypeOfPin type, ModeOfPin mode){
  // return true; // It's gag - Replace with the real code
// }

#endif