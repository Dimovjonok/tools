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


const uint16_t My_Name PROGMEM =  0x0001;
const uint8_t My_Object PROGMEM = 34;
const uint8_t My_Floor PROGMEM = 1;
const uint8_t My_Room PROGMEM = 0xFF;

// typedef uint8_t ModeOfPin;
// typedef uint8_t TypeOfPin;
// typedef uint8_t PinsOfBoard;
typedef uint8_t PinMode;
typedef uint8_t PinType;
typedef uint8_t BoardPins;



typedef uint8_t NumberOfPin;
typedef uint8_t NumberOfModules;
typedef uint8_t NumberOfRelays;
typedef uint8_t IndexOfRelay;
typedef uint8_t NumberOfModems;


// Модули расширения и задействованные ресурсы базового модуля
// Электромагнитные реле

  const bool RELAY_On = false;
  const bool RELAY_Off = !RELAY_On;

  const NumberOfRelays RELAY_Number = 8;
  const IndexOfRelay Relay_Busy = 0;
  const IndexOfRelay Relay_Unknown = 1;
  const IndexOfRelay Relay_Free = 2;
#ifdef _ARDUINO_MEGA2560
  const BoardPins pinRelay[RELAY_Number] =  {37,35,33,31,29,27,25,23};
#endif

#ifdef _ARDUINO_MEGA2560
  // const long baud[] PROGMEM = {300L,1200L,2400L,4800L,9600L,14400L,19200L,28800L,38400L,57600L,115200L};
  // const uint8_t rate115k2 = 10;
  const NumberOfModems Modems_Cellular = 1;
  const BoardPins pinModemPower[Modems_Cellular] =  {0};
  const BoardPins pinModemReset[Modems_Cellular] =  {0};
  const HardwareSerial* portModem[Modems_Cellular] =  {&Serial2};

#endif

// Насос водяной скважины системы водоснабжения дома
  const BoardPins pinPumpWaterWell = 37;

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
