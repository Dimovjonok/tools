/* 
Dmitry Lebedev (DumDumbIch) dumdumbich@gmail.com
Create: 26.01.2020
Release:
class Modem
*/

/* 
Класс Modem описывает модем типа Teleofis RX100-R4 (OEM).
Даннный модуль построен на основе чипа Telit GL868-DUAL.
Канал связи контроллер-модем - последовательный порт с TTL-уровнями.
В дальнейшем планируется реализовать набор функций непосредственно в модеме на языке Python.
Данный класс будет предоставлять API к набору функций реализованных непосредственно в модеме.
Это обеспечит разгрузку контроллера от необходимости отслеживать прием и декодирование сообщений.
К тому же язык Python (интерпретатор встроен непосредственно в модуль модема) предоставляет большой набор функций для работы со строками и регулярными выражениями.
 */
#ifndef _MODEM_H
#define _MODEM_H

#include "HAL.h"
// #include "Time.h"
#include "Action.h"
// #include "hayes.h"
// #include "gsm.h"
// #include "gprs.h"
// #include "telit.h"

const long rate[] = {300L,1200L,2400L,4800L,9600L,14400L,19200L,28800L,38400L,57600L,115200L};

class Modem : public Action
{
  public:
    Modem();
    Modem(HardwareSerial* port);
    Modem(HardwareSerial* port,BoardPins pinPower,BoardPins pinReset);
    String execute(String command, unsigned int timeout = 5000);
    bool isConnected(unsigned long timeout);
    void init();
    void sendSMS(String message);
  private:
    long current_rate;
    BoardPins pinPower;
    BoardPins pinReset;
    HardwareSerial* port;
};


bool Modem::isConnected(unsigned long timeout){
  unsigned long start = CurrentTime();
  do {
    if(execute(F("AT")).indexOf(F("OK")) > -1) return true;  
  } while ((CurrentTime() - start) < timeout);
  return false;
}

void Modem::init(){
  Serial.println("Modem::test()");
  for (int i = 0; i < sizeof(rate)/sizeof(long); i++){    
    Serial.print("Baudrate - ");
    Serial.println(rate[i]);
    port->begin(rate[i]);
    if (isConnected(1000)) {
      String message = "Modem connected on rate " + (String) rate[i];
      sendSMS(message);
      break;
    }
    port->end();
    Serial.println("Modem not found");
  }    
}

void Modem::sendSMS(String message){
  if(execute(F("AT")).indexOf(F("OK")) > -1) Serial.println("AT -> OK");
  if(execute(F("AT#SMSMODE=1")).indexOf(F("OK")) > -1) Serial.println("AT#SMSMODE=1 -> OK");
  if(execute(F("AT+CMGF=1")).indexOf(F("OK")) > -1) Serial.println("AT+CMGF=1 -> OK");
  port->print("AT#SMSMODE=1");
  Serial.println("AT#SMSMODE=1");
  port->println("AT+CMGF=1");
  Serial.println("AT+CMGF=1");
  delay(100);
  port->println("AT+CMGS=+79158212071");
  Serial.println("AT+CMGS=+79158212071");
  delay(100);
  port->print(message);
  Serial.println(message);
  port->print((char)0x1A);
  delay(100);
  Serial.println("SMS sended");  
}

String Modem::execute(String command, unsigned int timeout){
  uint8_t charNumber = 0;
  char response[150] = {0};
  unsigned long start = CurrentTime();  
  port->println(command);  
  do {
    if (port->available() != 0){
      response[charNumber] = port->read();
      charNumber++;
    }
    if (strstr(response,"OK") != NULL) break;
  } while ((CurrentTime() - start) < timeout);  
  response[charNumber] = '\0';
  return String(response);
}

Modem::Modem(){}

Modem::Modem(HardwareSerial* port){}

Modem::Modem(HardwareSerial* port,BoardPins pinPower,BoardPins pinReset){
  this->port = port;
}

#endif