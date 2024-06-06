#ifndef flash_hpp
#define flash_hpp
#include <Arduino.h>

#define SECTOR_SIZE   4096
#define SST_ID        0xBF
#define SST_39SF040   0xB7

#define _WE A8 
#define _OE A9 
#define _CE A10 

#define D0 22 
#define D1 23 
#define D2 24 
#define D3 25 
#define D4 26 
#define D5 27
#define D6 28 
#define D7 29

#define ADR0 30
#define ADR1 31 
#define ADR2 32 
#define ADR3 33 
#define ADR4 34 
#define ADR5 35
#define ADR6 36 
#define ADR7 37
#define ADR8 38 
#define ADR9 39 
#define ADR10 40 
#define ADR11 41 
#define ADR12 42 
#define ADR13 43
#define ADR14 44 
#define ADR15 45
#define ADR16 46 
#define ADR17 47
#define ADR18 A11

void writeAddress(unsigned long value);
void setReadMode(unsigned long addr);
void setWriteMode();
unsigned int digitalReadByte();
void writeData(unsigned int value);
void softProtect();
void programByte(unsigned long address, unsigned int data);
byte getHwID(unsigned long id_type);
void chipErase();
void sectorErase(long address);



#endif