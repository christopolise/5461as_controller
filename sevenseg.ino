#include <Wire.h> // Enable this line if using Arduino Uno, Mega, etc.
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"
#include <time.h>

uint8_t segA = 8;
uint8_t segB = 12;
uint8_t segC = 4;
uint8_t segD = 2;
uint8_t segE = 13;
uint8_t segF = 9;
uint8_t segG = 5;
uint8_t segPt = 3;

uint8_t D1 = 6;
uint8_t D2 = 11;
uint8_t D3 = 10;
uint8_t D4 = 7;

uint8_t segments[8] = {segA, segB, segC, segD, segE, segF, segG, segPt};
uint8_t digits[4] = {D1, D2, D3, D4};

/*
1=e
2=d
3=pt
4=c
5=g
6=d1 (high turns it off)
7=d4 ""
8=a
9=f
10=d3 ""
11=d2 ""
12=b
*/

void printHex(String inp, bool decimalPoint=false, int decimalPos = 0, bool prependZeros = false);

Adafruit_7segment matrix = Adafruit_7segment();

void setup() {
#ifndef __AVR_ATtiny85__
  Serial.begin(9600);
  Serial.println("7 Segment Backpack Test");
#endif
  matrix.begin(0x70);
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
  pinMode(segPt, OUTPUT);

  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
}

void loop() {
  
  printHex("beef");
  // try to print a number thats too long
//  matrix.print(10000, DEC);
//  matrix.writeDisplay();
//  delay(500);

  // print a hex number
//  matrix.print(0xBEEF, HEX);
//  matrix.writeDisplay();
//  delay(500);

  // print a floating point 
  matrix.print(12.34);
  matrix.writeDisplay();
//  delay(500);
  
  // print with print/println
//  for (uint16_t counter = 0; counter < 9999; counter++) {
//    matrix.println(counter);
//    matrix.writeDisplay();
//    delay(10);
//  }

}

void reset()
{
  for(uint8_t i = 0; i < 4; i++)
    digitalWrite(digits[i], HIGH);


  for(uint8_t i = 0; i < sizeof(segments)/sizeof(segments[0]); i++)
    digitalWrite(segments[i], LOW);
  
}

void printError()
{
  reset();
  for(uint8_t i = 0; i < 4; i++)
    digitalWrite(digits[i], LOW);

  digitalWrite(segG, HIGH);
}

void printHex(String inp, bool decimalPoint=false, int decimalPos = 0, bool prependZeros = false)
{
  if(inp.length() > 4)
  {
    printError();
    return;
  }

  for(int i = inp.length(); i < 4; i++)
  {
    if(prependZeros)
    {
      inp = "0" + inp;
    }
    else
    {
      inp = "x" + inp;
    }
  }

  for(int i = 0, j = 3; i < 4, j >= 0; i++, j--)
  {
    reset();
    digitalWrite(digits[i], LOW);
    switch(inp[j])
    {
      case '0':
        pZero();
        break;
      case '1':
        pOne();
        break;
      case '2':
        pTwo();
        break;
      case '3':
        pThree();
        break;
      case '4':
        pFour();
        break;
      case '5':
        pFive();
        break;
      case '6':
        pSix();
        break;
      case '7':
        pSeven();
        break;
      case '8':
        pEight();
        break;
      case '9':
        pNine();
        break;
      case 'a':
        pA();
        break;
      case 'b':
        pB();
        break;
      case 'c':
        pC();
        break;
      case 'd':
        pD();
        break;
      case 'e':
        pE();
        break;
      case 'f':
        pF();
        break;
      case 'x':
        pX();
        break;
    }
    if(decimalPoint && decimalPos == j)
    {
      digitalWrite(segPt, HIGH);
    }
    if( i == 3 )
    {
      delayMicroseconds(2000);
    }
    else
    {
      delayMicroseconds(4000);
    }
  }
}

void pZero()
{
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, LOW);
}

void pOne()
{
  digitalWrite(segA, LOW);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, LOW);
}

void pTwo()
{
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, LOW);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, LOW);
  digitalWrite(segG, HIGH);
}

void pThree()
{
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, HIGH);
}

void pFour()
{
  digitalWrite(segA, LOW);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH); 
}

void pFive()
{
  digitalWrite(segA, HIGH);
  digitalWrite(segB, LOW);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, LOW);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
}

void pSix()
{
  digitalWrite(segA, HIGH);
  digitalWrite(segB, LOW);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
}

void pSeven()
{
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, LOW);
}

void pEight()
{
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
}

void pNine()
{
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, LOW);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
}

void pA()
{
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, LOW);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
}

void pB()
{
  digitalWrite(segA, LOW);
  digitalWrite(segB, LOW);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
}

void pC()
{
  digitalWrite(segA, HIGH);
  digitalWrite(segB, LOW);
  digitalWrite(segC, LOW);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, LOW);
}

void pD()
{
  digitalWrite(segA, LOW);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, LOW);
  digitalWrite(segG, HIGH);
}

void pE()
{
  digitalWrite(segA, HIGH);
  digitalWrite(segB, LOW);
  digitalWrite(segC, LOW);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
}

void pF()
{
  digitalWrite(segA, HIGH);
  digitalWrite(segB, LOW);
  digitalWrite(segC, LOW);
  digitalWrite(segD, LOW);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
}

void pX()
{
  digitalWrite(segA, LOW);
  digitalWrite(segB, LOW);
  digitalWrite(segC, LOW);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, LOW);
}
