/*
Dmitry Lebedev (Dimovjonok) dmitrylebedev@mail.ru
Create: 28.08.2021
Release:
*/

#ifndef _HAL_H
#define _HAL_H

#ifdef _MODE_DEBUG
#define _MODE_DEBUG_PLATFORM
#endif

#include <Arduino.h>
#include <avr/pgmspace.h>

// Базовый модуль
// #define _ARDUINO_PRO_MINI
#define _ARDUINO_MEGA2560
//#define _ARDUINO_DUE

#define ANALOG 0
#define DIGITAL 1

typedef uint8_t PinMode;
typedef uint8_t PinType;
typedef uint8_t BoardPins;


class HAL {
  public:

  // static long baud[] = {300L,1200L,2400L,4800L,9600L,14400L,19200L,28800L,38400L,57600L,115200L};

    static void configPinDI(BoardPins pin); // Used Arduino library
    static void configPinDO(BoardPins pin); // Used Arduino library
    static bool getPinLevel(BoardPins pin); // Used Arduino library
    static void setPinLevel(BoardPins pin, bool level); // Used Arduino library
    static void pinToHigh(BoardPins pin);
    static void pinToLow(BoardPins pin);
    // static void configPinAI(BoardPins pin);
    // static void configPinAO(BoardPins pin);
    // static void setPinValue(BoardPins pin);
    // static void getPinValue(BoardPins pin);
  private:
    static bool checkPinConfig(BoardPins pin, PinType type, PinMode mode); // !!! Method not released !!!
    HAL();
    HAL(const HAL& hal);
    const HAL& operator=(const HAL& hal);
};


void HAL::configPinDI(BoardPins pin){
  if (checkPinConfig(pin,DIGITAL,INPUT)) pinMode(pin, INPUT); // Used Arduino library
}

void HAL::configPinDO(BoardPins pin){
  if (checkPinConfig(pin,DIGITAL,OUTPUT)) pinMode(pin, OUTPUT); // Used Arduino library
}


bool HAL::getPinLevel(BoardPins pin){
  return digitalRead(pin); // Used Arduino library
}

void HAL::setPinLevel(BoardPins pin, bool level){
  digitalWrite(pin, level); // Used Arduino library
}

void HAL::pinToHigh(BoardPins pin){
  setPinLevel(pin, HIGH);
}

void HAL::pinToLow(BoardPins pin){
  setPinLevel(pin, LOW);
}


bool HAL::checkPinConfig(BoardPins pin, PinType type, PinMode mode){
  return true; // It's gag - Replace with the real code
}

#endif
