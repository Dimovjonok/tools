/*
Dmitry Lebedev (DumDumbIch) dumdumbich@gmail.com
Create: 08.01.2020
Release:
class Relay
*/

/* 
Реализовать метод toggle() - перключение реле в противоположной состояние

М.б. потребуются методы включения и выключения реле с задержкой, 
включение/выключение/переключение на время 
и периодическое включение/выключение
 */
 
#ifndef _RELAY_H
#define _RELAY_H

#ifdef _MODE_DEBUG
#define _MODE_DEBUG_RELAY
#endif

#include "Action.h"
#include "Pin.h"

class Relay : public Action {
  public:
    Relay();
    Relay(BoardPins idPin);
    Relay(BoardPins idPin, TimeInMilli time_on, TimeInMilli time_off);
    Relay(BoardPins idPin, TimeInMilli* time_on_ptr, TimeInMilli* time_off_ptr);
    void on();
    void off();
    void toggle();
  private:
    BoardPins idPin;
    Pin* pin;
    TimeInMilli time_on;
    TimeInMilli time_off;
    TimeInMilli* time_on_ptr;
    TimeInMilli* time_off_ptr;
    void initPin(BoardPins idPin);
    void initValues(TimeInMilli time_on, TimeInMilli time_off);
    void initPointers(TimeInMilli* time_on_ptr, TimeInMilli* time_off_ptr);
};


Relay::Relay():Action(){
  initValues(0,0);
  initPointers(nullptr, nullptr);  
}

Relay::Relay(BoardPins idPin):Action(){
  initPin(idPin);
  initValues(0,0);
  initPointers(nullptr, nullptr);
}

Relay::Relay(BoardPins idPin, TimeInMilli time_on, TimeInMilli time_off):Action(){
  initPin(idPin);
  initValues(time_on,time_off);
  initPointers(nullptr, nullptr);
}

Relay::Relay(BoardPins idPin, TimeInMilli* time_on_ptr, TimeInMilli* time_off_ptr):Action(){
  initPin(idPin);
  initValues(0,0);
  initPointers(time_on_ptr, time_off_ptr);
}

void Relay::initPin(BoardPins idPin){
  this->idPin = idPin;  
  pin = new Pin(idPin, DirectOfPin::Output);
}

void Relay::initValues(TimeInMilli time_on, TimeInMilli time_off){
  this->time_on = time_on;
  this->time_off = time_off;  
}

void Relay::initPointers(TimeInMilli* time_on_ptr, TimeInMilli* time_off_ptr){
  this->time_on_ptr = time_on_ptr;
  this->time_off_ptr = time_off_ptr;    
}

void Relay::on(){
  pin->putLevel(RELAY_On);
}

void Relay::off(){
  pin->putLevel(RELAY_Off);
}

void Relay::toggle(){
  pin->toggleLevel();
}

#endif