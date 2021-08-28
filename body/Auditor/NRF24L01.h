 /* 
 NRF24L01.h 
 Version 00 : Edition 03 : Date 14/06/2019
*/

#ifndef _NRF24L01_H
#define _NRF24L01_H

#ifdef _MODE_DEBUG
#define _MODE_DEBUG_NRF24L01
#endif

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>

typedef uint8_t AddressOfRegister;
typedef uint8_t MnemonicOfInstruction;
typedef uint8_t MnemonicOfBit;

const AddressOfRegister nRF24L01_Config = 0x00;

const MnemonicOfInstruction nRF24L01_ReadRegister = 0x00;
const MnemonicOfInstruction nRF24L01_WriteRegister = 0x20;

const MnemonicOfInstruction nRF24L01_DoNothing = 0xFF;


class NRF24L01 : public RF24
{
  public:
    NRF24L01(uint16_t cepin, uint16_t cspin);
  private:
  protected:
};

NRF24L01::NRF24L01(uint16_t cepin, uint16_t cspin):RF24(cepin,cspin){}

#endif