#include <Servo.h>

//Controle dos Servos

Servo base; 
Servo esc; 
Servo dir; 
Servo garra; 

// Definição dos POTENCIOMETROS como Porta Analogicas. 
const int joyAX  = A1 ;  
const int joyAY  = A0 ;        
const int joyBX  = A3 ;           
const int joyBY  = A2 ;  

// Definição dos BOTOES como variaveis. 
const int botaoCongela    = 8;  // Congela
const int botaoDescongela = 9; // Descongela

//Variaveis para calculo dos angulos

int AX,AY,BX,BY;

//Variaveis para controle dos botÃµes
int estadoBotaoA, estadoBotaoB;
int estadoAntBotaoA = HIGH;
int estadoAntBotaoB = HIGH;
boolean congelado = false;

void setup(){

  Serial.begin(9600);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);

  //Usa o LED do Arduino para informar estado de congelado
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
    
  //ConfiguraÃ§Ã£o das Portas dos Servos
  base.attach (3);
  esc.attach  (4);
  dir.attach  (5);
  garra.attach(6);

   
}

void loop() {

  if (!congelado) {

    AX = joyAX; // base
    AY = joyAY; // esc
    BX = joyBX; // dir
    BY = joyBY; // garra

    
    // BASE
    AX = analogRead(joyAX);             //Leitura do Angulo do Potenciometro
    AX = map(analogRead(joyAX), 0, 1023, 0, 180); //ConversÃ£o do valor do potenciometro (de 0 atÃ© 1024) para o angulo (de 0 até 180)
    delay(200);
    base.write(AX);                         //Envio do angulo para o Servo 
    Serial.println(joyAX);


    
    // ESC    
    AY = analogRead(joyAY);             //Leitura do Angulo do Potenciometro
    AY = map(analogRead(joyAY), 0, 1023, 0, 180); //ConversÃ£o do valor do potenciometro (de 0 atÃ© 1024) para o angulo (de 0 até 180)
    delay(220);
    esc.write(AY);                         //Envio do angulo para o Servo 
    Serial.println(joyAY);


    
    // DIR    
    BX = analogRead(joyBX);             //Leitura do Angulo do Potenciometro
    BX = map(analogRead(joyBX), 0, 1023, 0, 180); //ConversÃ£o do valor do potenciometro (de 0 atÃ© 1024) para o angulo (de 0 até 180)
    delay(200);
    dir.write(BX);                         //Envio do angulo para o Servo 
    Serial.println(joyBX);


    // GARRA   
    BY = analogRead(joyBY);             //Leitura do Angulo do Potenciometro
    BY = map(analogRead(joyBY), 0, 1023, 0, 180); //ConversÃ£o do valor do potenciometro (de 0 atÃ© 1024) para o angulo (de 0 até 180)
    delay(200);
    garra.write(BY);                         //Envio do angulo para o Servo 
    Serial.println(joyBY);
  
}



//_____________________________________________________________________________________________________________________

  //Se o botao de congelar foi apertado  
  estadoBotaoA = digitalRead(8); 
  if (estadoBotaoA != estadoAntBotaoA) {
     congelado = true;
     digitalWrite(13, HIGH); //Informa o estado de congelado no LED interno do Arduino
  }
  estadoAntBotaoA = estadoBotaoA;

//_____________________________________________________________________________________________________________________

  //Se o botao de descongelar foi apertado
  estadoBotaoB = digitalRead(9); 
  if (estadoBotaoB != estadoAntBotaoB) {
     congelado = false;
     digitalWrite(13, LOW); //Informa o estado de congelado no LED interno do Arduino
  }
  estadoAntBotaoB = estadoBotaoB;

}
