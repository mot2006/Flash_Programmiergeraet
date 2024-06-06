#include <flash.hpp>

void setReadMode(unsigned long addr)
{
    writeAddress(addr);

    pinMode(D0, INPUT);
    pinMode(D1, INPUT);
    pinMode(D2, INPUT);
    pinMode(D3, INPUT);
    pinMode(D4, INPUT);
    pinMode(D5, INPUT);
    pinMode(D6, INPUT);
    pinMode(D7, INPUT);
    delay(1);

    digitalWrite(_CE, LOW);
    digitalWrite(_OE, LOW);
    digitalWrite(_WE, HIGH);
    delay(1);
}

void setWriteMode()
{
    pinMode(D0, OUTPUT);
    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);
    pinMode(D3, OUTPUT);
    pinMode(D4, OUTPUT);
    pinMode(D5, OUTPUT);
    pinMode(D6, OUTPUT);
    pinMode(D7, OUTPUT);
    delay(1);
}

void writeAddress(unsigned long value)
{
    digitalWrite(ADR0, (value >> 0) & 0x01);
    digitalWrite(ADR1, (value >> 1) & 0x01);
    digitalWrite(ADR2, (value >> 2) & 0x01);
    digitalWrite(ADR3, (value >> 3) & 0x01);
    digitalWrite(ADR4, (value >> 4) & 0x01);
    digitalWrite(ADR5, (value >> 5) & 0x01);
    digitalWrite(ADR6, (value >> 6) & 0x01);
    digitalWrite(ADR7, (value >> 7) & 0x01);
    digitalWrite(ADR8, (value >> 8) & 0x01);
    digitalWrite(ADR9, (value >> 9) & 0x01);
    digitalWrite(ADR10, (value >> 10) & 0x01);
    digitalWrite(ADR11, (value >> 11) & 0x01);
    digitalWrite(ADR12, (value >> 12) & 0x01);
    digitalWrite(ADR13, (value >> 13) & 0x01);
    digitalWrite(ADR14, (value >> 14) & 0x01);
    digitalWrite(ADR15, (value >> 15) & 0x01);
    digitalWrite(ADR16, (value >> 16) & 0x01);
    digitalWrite(ADR17, (value >> 17) & 0x01);
    digitalWrite(ADR18, (value >> 18) & 0x01);
}

unsigned int digitalReadByte()
{
    unsigned int toReturn = 0x00;
    if (digitalRead(D0) == HIGH) {bitSet(toReturn, 0); } else { bitClear(toReturn, 0); }   
    if (digitalRead(D1) == HIGH) {bitSet(toReturn, 1); } else { bitClear(toReturn, 1); } 
    if (digitalRead(D2) == HIGH) {bitSet(toReturn, 2); } else { bitClear(toReturn, 2); } 
    if (digitalRead(D3) == HIGH) {bitSet(toReturn, 3); } else { bitClear(toReturn, 3); } 
    if (digitalRead(D4) == HIGH) {bitSet(toReturn, 4); } else { bitClear(toReturn, 4); } 
    if (digitalRead(D5) == HIGH) {bitSet(toReturn, 5); } else { bitClear(toReturn, 5); } 
    if (digitalRead(D6) == HIGH) {bitSet(toReturn, 6); } else { bitClear(toReturn, 6); } 
    if (digitalRead(D7) == HIGH) {bitSet(toReturn, 7); } else { bitClear(toReturn, 7); } 
    return toReturn;
}

void writeData(unsigned int value)
{
    digitalWrite(D0, (value >> 0) & 0x01);
    digitalWrite(D1, (value >> 1) & 0x01);
    digitalWrite(D2, (value >> 2) & 0x01);
    digitalWrite(D3, (value >> 3) & 0x01);
    digitalWrite(D4, (value >> 4) & 0x01);
    digitalWrite(D5, (value >> 5) & 0x01);
    digitalWrite(D6, (value >> 6) & 0x01);
    digitalWrite(D7, (value >> 7) & 0x01);
    delayMicroseconds(5); 
}

void softProtect()
{
    digitalWrite(_OE, HIGH);
    digitalWrite(_WE, HIGH);
    digitalWrite(_CE, LOW);

    long ADDR_1 = 0x5555;
    long ADDR_2 = 0x2AAA;
    long ADDR_3 = 0x5555;

    writeAddress(ADDR_1);
    writeData(0xAA);

    digitalWrite(_WE, LOW);
    digitalWrite(_WE, HIGH);

    writeAddress(ADDR_2);
    writeData(0x55);

    digitalWrite(_WE, LOW);
    digitalWrite(_WE, HIGH);
    
    writeAddress(ADDR_3);
    writeData(0xA0);
    
    digitalWrite(_WE, LOW);
    digitalWrite(_WE, HIGH);
}

void programByte(unsigned long address, unsigned int data)
{
    softProtect();
    writeAddress(address);
    writeData(data);
    digitalWrite(_WE, LOW);
    digitalWrite(_WE, HIGH);
}

byte getHwID(unsigned long id_type)
{
    long ADDR_1 = 0x5555;
    long ADDR_2 = 0x2AAA;
    long ADDR_3 = 0x5555;

    digitalWrite(_CE, LOW);
    digitalWrite(_OE, HIGH);
    digitalWrite(_WE, HIGH);

    writeAddress(ADDR_1);
    writeData(0xAA);

    digitalWrite(_WE, LOW);
    digitalWrite(_WE, HIGH);

    writeAddress(ADDR_2);
    writeData(0x55);

    digitalWrite(_WE, LOW);
    digitalWrite(_WE, HIGH);

    writeAddress(ADDR_3);
    writeData(0x90); 
    digitalWrite(_WE, LOW);
    digitalWrite(_WE, HIGH);
    delayMicroseconds(1);

    setReadMode(id_type);
    byte id = digitalReadByte();
    setWriteMode();

    writeAddress(ADDR_1);
    writeData(0xAA);

    digitalWrite(_WE, LOW);
    digitalWrite(_WE, HIGH);

    writeAddress(ADDR_2);
    writeData(0x55);

    digitalWrite(_WE, LOW);
    digitalWrite(_WE, HIGH);

    writeAddress(ADDR_3);
    writeData(0xF0); 
    digitalWrite(_WE, LOW);
    digitalWrite(_WE, HIGH);

    return id;
}

void chipErase()
{
    writeAddress(0);
    writeData(0);

    digitalWrite(_CE, LOW);
    digitalWrite(_OE, HIGH);
    digitalWrite(_WE, HIGH);

    long ADDR_1 = 0x5555;
    long ADDR_2 = 0x2AAA;
    long ADDR_3 = 0x5555;
    long ADDR_4 = 0x5555;
    long ADDR_5 = 0x2AAA;
    long ADDR_6 = 0x5555;

    byte DATA_1 = 0xAA;
    byte DATA_2 = 0x55;
    byte DATA_3 = 0x80;
    byte DATA_4 = 0xAA;
    byte DATA_5 = 0x55;
    byte DATA_6 = 0x10;

    writeAddress(ADDR_1);
    writeData(DATA_1);

    digitalWrite(_WE, LOW);
    digitalWrite(_WE, HIGH);

    writeAddress(ADDR_2);
    writeData(DATA_2);

    digitalWrite(_WE, LOW);
    digitalWrite(_WE, HIGH);

    writeAddress(ADDR_3);
    writeData(DATA_3);

    digitalWrite(_WE, LOW);
    digitalWrite(_WE, HIGH);

    writeAddress(ADDR_4);
    writeData(DATA_4);

    digitalWrite(_WE, LOW);
    digitalWrite(_WE, HIGH);

    writeAddress(ADDR_5);
    writeData(DATA_5);

    digitalWrite(_WE, LOW);
    digitalWrite(_WE, HIGH);

    writeAddress(ADDR_6);
    writeData(DATA_6);

    digitalWrite(_WE, LOW);
    digitalWrite(_WE, HIGH);

    delay(1000);
}

void sectorErase(long address)
{
    digitalWrite(_CE, LOW);
    digitalWrite(_OE, HIGH);
    digitalWrite(_WE, HIGH);

    long ADDR_1 = 0x5555;
    long ADDR_2 = 0x2AAA;
    long ADDR_3 = 0x5555;
    long ADDR_4 = 0x5555;
    long ADDR_5 = 0x2AAA;
    long ADDR_6 = address;

    byte DATA_1 = 0xAA;
    byte DATA_2 = 0x55;
    byte DATA_3 = 0x80;
    byte DATA_4 = 0xAA;
    byte DATA_5 = 0x55;
    byte DATA_6 = 0x30;

    writeAddress(ADDR_1);
    writeData(DATA_1);

    digitalWrite(_WE, LOW);
    digitalWrite(_WE, HIGH);

    writeAddress(ADDR_2);
    writeData(DATA_2);

    digitalWrite(_WE, LOW);
    digitalWrite(_WE, HIGH);

    writeAddress(ADDR_3);
    writeData(DATA_3);

    digitalWrite(_WE, LOW);
    digitalWrite(_WE, HIGH);

    writeAddress(ADDR_4);
    writeData(DATA_4);

    digitalWrite(_WE, LOW);
    digitalWrite(_WE, HIGH);

    writeAddress(ADDR_5);
    writeData(DATA_5);

    digitalWrite(_WE, LOW);
    digitalWrite(_WE, HIGH);

    writeAddress(ADDR_6);
    writeData(DATA_6);

    digitalWrite(_WE, LOW);
    digitalWrite(_WE, HIGH);

    delay(100);
}