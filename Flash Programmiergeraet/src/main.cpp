#include <Arduino.h>
#include "flash.hpp"

void setup()
{
    Serial.begin(57600);
    delay(2);

    pinMode(_WE, OUTPUT);
    digitalWrite(_WE, HIGH);

    pinMode(_OE, OUTPUT);
    digitalWrite(_OE, HIGH);

    pinMode(_CE, OUTPUT);
    digitalWrite(_CE, LOW);

    pinMode(D0, OUTPUT);
    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);
    pinMode(D3, OUTPUT);
    pinMode(D4, OUTPUT);
    pinMode(D5, OUTPUT);
    pinMode(D6, OUTPUT);
    pinMode(D7, OUTPUT);

    digitalWrite(D0, LOW);
    digitalWrite(D1, LOW);
    digitalWrite(D2, LOW);
    digitalWrite(D3, LOW);
    digitalWrite(D4, LOW);
    digitalWrite(D5, LOW);
    digitalWrite(D6, LOW);
    digitalWrite(D7, LOW);

    pinMode(ADR0, OUTPUT);
    pinMode(ADR1, OUTPUT);
    pinMode(ADR2, OUTPUT);
    pinMode(ADR3, OUTPUT);
    pinMode(ADR4, OUTPUT);
    pinMode(ADR5, OUTPUT);
    pinMode(ADR6, OUTPUT);
    pinMode(ADR7, OUTPUT);
    pinMode(ADR8, OUTPUT);
    pinMode(ADR9, OUTPUT);
    pinMode(ADR10, OUTPUT);
    pinMode(ADR11, OUTPUT);
    pinMode(ADR12, OUTPUT);
    pinMode(ADR13, OUTPUT);
    pinMode(ADR14, OUTPUT);
    pinMode(ADR15, OUTPUT);
    pinMode(ADR16, OUTPUT);
    pinMode(ADR17, OUTPUT);
    pinMode(ADR18, OUTPUT);

    delay(100);

    digitalWrite(ADR0, LOW);
    digitalWrite(ADR1, LOW);
    digitalWrite(ADR2, LOW);
    digitalWrite(ADR3, LOW);
    digitalWrite(ADR4, LOW);
    digitalWrite(ADR5, LOW);
    digitalWrite(ADR6, LOW);
    digitalWrite(ADR7, LOW);
    digitalWrite(ADR8, LOW);
    digitalWrite(ADR9, LOW);
    digitalWrite(ADR10, LOW);
    digitalWrite(ADR11, LOW);
    digitalWrite(ADR12, LOW);
    digitalWrite(ADR13, LOW);
    digitalWrite(ADR14, LOW);
    digitalWrite(ADR15, LOW);
    digitalWrite(ADR16, LOW);
    digitalWrite(ADR17, LOW);
    digitalWrite(ADR18, LOW);
    delay(100);

    //chipErase();


    //for (long i = 0; i < 32768; i++)
    //{
    //    programByte(i,0xea);
    //    Serial.println(i);
    //}

    setReadMode(0);
    Serial.println(digitalReadByte(),HEX);
    setReadMode(0xea);
    Serial.println(digitalReadByte(),HEX);
    setReadMode(0x8000);
    Serial.println(digitalReadByte(),HEX);
    setReadMode(0xffff);
    Serial.println(digitalReadByte(),HEX);
    
}

void loop()
{  

}
