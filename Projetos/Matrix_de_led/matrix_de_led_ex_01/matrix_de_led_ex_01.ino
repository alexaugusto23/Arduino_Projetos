//CI MAX7219
//pin 01 DIN     ->> uno-pin 12
//pin 12 LOAD CS ->> uno-pin 11
//pin 13 CLK     ->> uno-pin 10

#include "LedControl.h"

#define DIN 12
#define CS 11
#define CLK 10

LedControl matrix_led = LedControl(DIN,CLK,CS,1);


void setup() 
{
      Serial.begin(9600); 
      matrix_led.shutdown(0,false); 
      matrix_led.setIntensity(0,10); 
      matrix_led.clearDisplay(0);
}

void loop() 
{
   //linhas(); 
   //delay(1000);
   piscaled();
   delay(500);
   palavra();
   
}



//--Médotos

void palavra()
{
  byte A[8] = 
  {
    B00011000,
    B00100100,
    B01000010,
    B01000010,
    B01111110,
    B01000010,
    B01000010,
    B01000010
   };
  
  byte L[8] = 
  {
    B00000010,
    B00000110,
    B00000110,
    B00000110,
    B00000110,
    B00000110,
    B00111110,
    B01111110
   };
  
  byte E[8] = 
  {
    B01111110,
    B00000010,
    B00000010,
    B00111110,
    B00111110,
    B00000010,
    B00000010,
    B01111110
   };

  byte X[8] = 
  {
    B01000010,
    B00100100,
    B00011000,
    B00011000,
    B00011000,
    B00011000,
    B00100100,
    B01000010
   };
   

    //setRow(int addr, int row, byte value); 
    for(int contador =0; contador < 8; contador++ )
        {
          matrix_led.setColumn(0,contador,A[contador]);
          Serial.print("setRow_for_direita:");
          Serial.println(contador);
          delay(200);
        }
    delay(500);
    Serial.println();
    matrix_led.clearDisplay(0);

    //setRow(int addr, int row, byte value); 
    for(int contador =0; contador < 8; contador++ )
        {
          matrix_led.setColumn(0,contador,L[contador]);
          Serial.print("setRow_for_direita:");
          Serial.println(contador);
          delay(200);
        }
    delay(500);
    Serial.println();
    matrix_led.clearDisplay(0);


    //setRow(int addr, int row, byte value); 
    for(int contador =0; contador < 8; contador++ )
        {
          matrix_led.setColumn(0,contador,E[contador]);
          Serial.print("setRow_for_direita:");
          Serial.println(contador);
          delay(200);
        }
    delay(500);
    Serial.println();
    matrix_led.clearDisplay(0);

        //setRow(int addr, int row, byte value); 
    for(int contador =0; contador < 8; contador++ )
        {
          matrix_led.setColumn(0,contador,X[contador]);
          Serial.print("setRow_for_direita:");
          Serial.println(contador);
          delay(200);
        }
    delay(500);
    Serial.println();
    matrix_led.clearDisplay(0);



  
}

void piscaled()
{
   matrix_led.setLed(0,4,3,true);
   matrix_led.setLed(0,3,3,true);
   matrix_led.setLed(0,4,4,true);
   matrix_led.setLed(0,3,4,true);
   delay(250);  
   
   matrix_led.setLed(0,4,3,false);
   matrix_led.setLed(0,3,3,false);
   matrix_led.setLed(0,4,4,false);
   matrix_led.setLed(0,3,4,false);
   delay(250);
   
   matrix_led.setLed(0,4,3,true);
   matrix_led.setLed(0,3,3,true);
   matrix_led.setLed(0,4,4,true);
   matrix_led.setLed(0,3,4,true);
   delay(250); 
    
   matrix_led.setLed(0,4,3,false);
   matrix_led.setLed(0,3,3,false);
   matrix_led.setLed(0,4,4,false);
   matrix_led.setLed(0,3,4,false);
   delay(250);
}


void linhas ()
{
    //setRow(int addr, int row, byte value); 
    for(int contador =7; contador >= 0; contador-- )
        {
          matrix_led.setRow(0,contador,B11111111);
          Serial.print("setRow_for_direita:");
          Serial.println(contador);
          delay(200);
        }
    Serial.println();
    matrix_led.clearDisplay(0);
    
    for(int contador =0; contador < 8; contador++ )
        {
          matrix_led.setRow(0,contador,B11111111);
          Serial.print("setRow_for_esquerda:");
          Serial.println(contador);
          delay(200);
        }
    Serial.println();
    matrix_led.clearDisplay(0);
    
    //setColumn(int addr, int col, byte value); 
    for(int contador =0; contador < 8; contador++ )
        {
          matrix_led.setColumn(0,contador,B11111111);
          Serial.print("setColumn_for_topofim:");
          Serial.println(contador);
          delay(200);
        }
    Serial.println();
    matrix_led.clearDisplay(0);
    
    for(int contador =7; contador >= 0; contador-- )
        {
          matrix_led.setColumn(0,contador,B11111111);
          Serial.print("setColumn_for_fimtopo:");
          Serial.println(contador);
          delay(200);
        }
    Serial.println();
    matrix_led.clearDisplay(0);
}

  //matrix_led.clearDisplay(0);
  /*
  for(int i = 0; i < 8 ; i++)
  {
    matrix_led.setLed(0,i,i,true);
    delay(100);
  }

    
  //matrix_led.clearDisplay(0);
  //delay(1000);
  //matrix_led.setLed(0,7,7,true);
    
    byte A[8] ={
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000
    };

------Palavras chaves da biblioteca-------------
shutdown  KEYWORD2
setScanLimit  KEYWORD2
setIntensity  KEYWORD2
clearDisplay  KEYWORD2
setLed    KEYWORD2
setRow    KEYWORD2
setColumn KEYWORD2
setDigit  KEYWORD2
setChar   KEYWORD2
# Constants (LITERAL1)
  */
