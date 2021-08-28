/* 
 Pin.h 
 Version 00 : Edition 03 : Date 26/05/2019
*/

#ifndef _PIN_H
#define _PIN_H

#ifdef _MODE_DEBUG
#define _MODE_DEBUG_PIN
#endif

#include "Platform.h"

enum class TypeOfPin: uint8_t {
  Undefined = 0,
  Digital,
  Analog,
  PWD
};

enum class DirectOfPin: uint8_t {
  Undefined = 0,
  Input,
  Output
};

class Pin
{
  public:
    Pin();
    Pin(NumberOfPin id);
    Pin(NumberOfPin id, DirectOfPin direct);
    Pin(NumberOfPin id, TypeOfPin type);
    Pin(NumberOfPin id, TypeOfPin type, DirectOfPin direct);    
    void High();
    void Low();
    bool Get();
    void Put(bool level);
  private:
    NumberOfPin id;
    TypeOfPin type;
    DirectOfPin direct;
    uint8_t mcuPort;
    uint8_t mcuLine;
    NumberOfPin getID();
    void setID(NumberOfPin id);
    TypeOfPin getType();
    void setType(TypeOfPin type);
    DirectOfPin getDirect();
    void setDirect(DirectOfPin direct);
    void init();
    void configDigital(NumberOfPin id, DirectOfPin direct);
  protected:
};


Pin::Pin(){
  setType(TypeOfPin::Undefined);
  setDirect(DirectOfPin::Undefined);  
}

Pin::Pin(NumberOfPin id){
  setID(id);
  setType(TypeOfPin::Digital);
  setDirect(DirectOfPin::Input);
  init();
}

Pin::Pin(NumberOfPin id, DirectOfPin direct){
  setID(id);
  setType(TypeOfPin::Digital);
  setDirect(direct);
  init();  
}

Pin::Pin(NumberOfPin id, TypeOfPin type){
  setID(id);
  setType(type);
  setDirect(DirectOfPin::Input);
  init();  
}

Pin::Pin(NumberOfPin id, TypeOfPin type, DirectOfPin direct){
  setID(id);
  setType(type);
  setDirect(direct);
  init();  
}

void Pin::High(){
  Put(HIGH);
}

void Pin::Low(){
  Put(LOW);
}

bool Pin::Get(){
  if (type == TypeOfPin::Digital && direct == DirectOfPin::Input)
    return digitalRead(id); // Leaving the Arduino library       
}

void Pin::Put(bool level){
  if (type == TypeOfPin::Digital && direct == DirectOfPin::Output)
    digitalWrite(id,level); // Leaving the Arduino library     
}

NumberOfPin Pin::getID(){
  return id;
}

void Pin::setID(NumberOfPin id){
  this->id = id;
}

TypeOfPin Pin::getType(){
  return type;
}

void Pin::setType(TypeOfPin type){
  this->type = type;
}

DirectOfPin Pin::getDirect(){
  return direct;
}

void Pin::setDirect(DirectOfPin direct){
  this->direct = direct;
}

void Pin::init(){
  switch (type){
    case TypeOfPin::Undefined:{
      break;
    }
    
    case TypeOfPin::Digital:{
      configDigital(id, direct);
      break;
    }
    
    case TypeOfPin::Analog:{
      break;
    }
  }
}

void Pin::configDigital(NumberOfPin id, DirectOfPin direct){
  switch (direct){
    case DirectOfPin::Undefined:{
      break;
    }
    
    case DirectOfPin::Input:{
      pinMode(id, INPUT); // Leaving the Arduino library
      break;
    }
    
    case DirectOfPin::Output:{
      pinMode(id, OUTPUT); // Leaving the Arduino library
      break;
    }
  }  
}

#endif