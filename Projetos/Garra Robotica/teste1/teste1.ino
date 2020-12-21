#include <Servo.h>
  
#define servoBase        3  // Porta Digital do Servo da Base
#define servoAlturaBraco 4  // Porta Digital do Servo da Altura do Braço
#define servoAnguloBraco 5  // Porta Digital do Servo do Ângulo do Braço
#define servoGarra       6  // Porta Digital do Servo da Garra

#define potBase         A0  // Porta Analógica do Potenciometro para Controle da Base
#define potAlturaBraco  A1  // Porta Analógica do Potenciometro para Controle da Altura do Braço
#define potAnguloBraco  A2  // Porta Analógica do Potenciometro para Controle do Ângulo do Braço
#define potGarra        A3  // Porta Analógica do Potenciometro para Controle da Garra.

#define botaoCongela     8  // Porta Digital do Botao Congela
#define botaoDescongela  9  // Porta Digital do Botao Descongela

//Instanciação dos Objetos de Controle dos Servos
Servo base; 
Servo altura;
Servo angulo;
Servo garra;

//Variaveis para cálculo dos angulos
int valorPotBase;
int valorAngBase;
int valorPotAltura;
int valorAngAltura;
int valorPotAngulo;
int valorAngAngulo;
int valorPotGarra;
int valorAngGarra;

//Variaveis para controle dos botões
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
    
  //Configuração das Portas dos Servos
  base.attach(3);
  altura.attach(4);
  angulo.attach(5);
  garra.attach(6); 
}


void loop() {

  if (!congelado) {
    valorAngBase = analogRead(valorPotBase);                //Leitura do Angulo do Potenciometro
    valorAngBase = map(valorPotBase, 0, 1024, 0, 180); //Conversão do valor do potenciometro (de 0 até 1024) para o angulo (de 0 até 180)
    base.write(valorAngBase);                          //Envio do angulo para o Servo 
  
    valorAngAltura = analogRead(valorPotAltura);           //Leitura do Angulo do Potenciometro
    valorAngAltura = map(valorAngAltura, 0, 1024, 180, 0); //Conversão do valor do potenciometro (de 0 até 1024) para o angulo (de 0 até 180) 
    altura.write(valorAngAltura);                          //Envio do angulo para o Servo 
    
    valorAngAngulo = analogRead(valorPotAngulo);           //Leitura do Angulo do Potenciometro
    valorAngAngulo = map(valorAngAngulo, 0, 1024, 180, 0); //Conversão do valor do potenciometro (de 0 até 1024) para o angulo (de 0 até 180)
    angulo.write(valorAngAngulo);                          //Envio do angulo para o Servo 
    
    valorAngGarra = analogRead(valorPotGarra);               //Leitura do Angulo do Potenciometro
    valorAngGarra = map(valorAngGarra, 0, 1024, 0, 90); //Conversão do valor do potenciometro (de 0 até 1024) para o angulo (de 0 até 180)
    garra.write(valorAngGarra);                         //Envio do angulo para o Servo 
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
