#include <Servo.h>
  
#define servoBase        3  // Porta Digital do Servo da Base
#define servoAlturaBraco 4  // Porta Digital do Servo da Altura do BraÃ§o
#define servoAnguloBraco 5  // Porta Digital do Servo do Ã‚ngulo do BraÃ§o
#define servoGarra       6  // Porta Digital do Servo da Garra

#define potBase         A0  // Porta AnalÃ³gica do Potenciometro para Controle da Base
#define potAlturaBraco  A1  // Porta AnalÃ³gica do Potenciometro para Controle da Altura do BraÃ§o
#define potAnguloBraco  A2  // Porta AnalÃ³gica do Potenciometro para Controle do Ã‚ngulo do BraÃ§o
#define potGarra        A3  // Porta AnalÃ³gica do Potenciometro para Controle da Garra.

#define botaoCongela     8  // Porta Digital do Botao Congela
#define botaoDescongela  9  // Porta Digital do Botao Descongela

//InstanciaÃ§Ã£o dos Objetos de Controle dos Servos
Servo base; 
Servo altura;
Servo angulo;
Servo garra;

//Variaveis para cÃ¡lculo dos angulos

int joyAX = A0;
int joyAY = A2;
int joyBX = A1;
int joyBY = A3;
int AX, AY, BX, BY;

//Variaveis para controle dos botÃµes
int estadoBotaoC, estadoBotaoD;
int estadoAntBotaoC = HIGH;
int estadoAntBotaoD = HIGH;
boolean congelado = false;

void setup(){
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);

  //Usa o LED do Arduino para informar estado de congelado
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
    
  //ConfiguraÃ§Ã£o das Portas dos Servos
  base.attach(3);
  altura.attach(4);
  angulo.attach(5);
  garra.attach(6); 
}


void loop() {

  if (!congelado) {

    AX = joyAX;
    AY = joyAY;
    BX = joyBX;
    BY = joyBY;
  
    AX = analogRead(joyAX);             //Leitura do Angulo do Potenciometro
    AX = map(analogRead(joyAX), 0, 1023, 900, 2100); //ConversÃ£o do valor do potenciometro (de 0 atÃ© 1024) para o angulo (de 0 atÃ© 180)
    base.write(AX);                         //Envio do angulo para o Servo 
    delay(15);
  
  
}

  //Se o botao de congelar foi apertado
  estadoBotaoC = digitalRead(8); 
  if (estadoBotaoC != estadoAntBotaoC) {
     congelado = true;
     digitalWrite(13, HIGH); //Informa o estado de congelado no LED interno do Arduino
  }
  estadoAntBotaoC = estadoBotaoC;

  //Se o botao de descongelar foi apertado
  estadoBotaoD = digitalRead(9); 
  if (estadoBotaoD != estadoAntBotaoD) {
     congelado = false;
     digitalWrite(13, LOW); //Informa o estado de congelado no LED interno do Arduino
  }
  estadoAntBotaoD = estadoBotaoD;

}

