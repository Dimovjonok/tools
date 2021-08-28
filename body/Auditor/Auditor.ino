/* 
 Auditor.ino 
 Version 00 : Edition 01 : Date 08/06/2019
 Version 00 : Edition 02 : Date 14/06/2019
*/

//#define _MODE_DEBUG
//#define _MODE_DEBUG_TOSERIAL

#include "Auditor.h"
#include "NRF24L01.h"
//#include "Status.h"
enum class StatusOfLocker: uint8_t {
  Undefined = 0,
  Free,
  Busy
};


Auditor auditor;

NRF24L01 radio(49,53);
uint8_t pipe;

struct TestData
{
  uint8_t ID;
  StatusOfLocker status;
};

TestData testData;

void setup() {

  testData.ID = 0;
  testData.status = StatusOfLocker::Undefined;
  
  auditor.Prepare();
  Serial.begin(115200);
  Serial1.begin(115200);
  Serial1.println("I'm will be back...");
  
  radio.begin();
  Serial1.print("Connected ");
  if (radio.isPVariant()) {
    Serial1.print("nRF24L01+");
  } else {
    Serial1.print("unknown module");
  }
  Serial1.print("\r\n");

  radio.setChannel(27);
  radio.setDataRate(RF24_1MBPS);
  radio.setPALevel(RF24_PA_MAX);
  //radio.openWritingPipe(0xAABBCCDD11LL);
  radio.openReadingPipe(1,0xAABBCCDD11LL);
  radio.openReadingPipe(2,0xAABBCCDD22LL);
  radio.openReadingPipe(3,0xAABBCCDD33LL);
  radio.openReadingPipe(4,0xAABBCCDD96LL);
  radio.openReadingPipe(5,0xAABBCCDDFFLL);
  radio.startListening();
  
}

void loop() {
  auditor.Sheduler();
  auditor.Dispatcher();
  auditor.Scavenger();
  delay(50);
  if (radio.available(&pipe)){
    Serial1.println();    
    Serial1.print("Test data received from ");
    switch (pipe){
      case 1: {
          Serial1.print("first");        
          break;
      }
      case 2: {
          Serial1.print("second");        
          break;
      }
      default: {
          Serial1.print("unknown");        
          break;
      }    
    }

    Serial1.print(" pipe\r\n");
    Serial1.println();
    delay(50);
    
    radio.read(&testData, sizeof(testData));    
    Serial1.print("Locker number of ");
    Serial1.print(testData.ID);
    Serial1.print(" is ");
    switch (testData.status){
      case StatusOfLocker::Undefined: {
          Serial1.print("UNDEFINED");        
          break;
      }
      case StatusOfLocker::Free: {
          Serial1.print("FREE");        
          break;
      }
      case StatusOfLocker::Busy: {
          Serial1.print("BUSY");        
          break;
      }
      default: {
          Serial1.print("UNKNOWN");        
          break;
      }    
      Serial1.println();
    }
    delay(50);
    Serial1.println();
  }
}