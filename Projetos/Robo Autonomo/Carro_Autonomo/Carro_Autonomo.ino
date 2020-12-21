
// inclusão de bibliotecas. 
#include <NewPing.h>
#include <Servo.h>

//definindo os pinos  
#define trigPin A0 
#define echoPin A1
#define MAX_DISTANCE 500
NewPing sonar (trigPin, echoPin, MAX_DISTANCE);

Servo basepan; // Define o servo como base

int distancia_cm = 0;   //variável do valor da distância 

// Motor A
int enaVelocd = 10;
int in1d = 5;
int in2d = 6;

// Motor B
int in3e = 7;
int in4e = 8;
int enbVeloce = 9; 



void setup() {
// put your setup code here, to run once:

// inicializa a comunicação serial para mostrar dados 
Serial.begin (9600);

// Pinos conectados as portas do sensor sonico
pinMode(trigPin,OUTPUT) ;
pinMode(echoPin,INPUT) ;

// Pino conectados as portas da ponte H
pinMode(enaVelocd,OUTPUT) ;
pinMode(in1d,OUTPUT) ;
pinMode(in2d,OUTPUT) ;
pinMode(in3e,OUTPUT) ;
pinMode(in4e,OUTPUT) ;
pinMode(enbVeloce,OUTPUT) ;

// Velocidade do motor 

.setSpeed(190);  // Define a velocidade para os motores 1.A velocidade máxima é 255  
motor2.setSpeed(190); // Define a velocidade para os motores 2. A velocidade máxima é 255 

// Servo conectado a porta 3
basepan.attach (3);
basepan.write (90);


}

void loop() {
  // put your main code here, to run repeatedly:

basetilt.write (0);

delay (1000);
basepan.write (95); 
delay (1500);

delay (1000);
basepan.write (180); 
delay (1500);

delay (1000);
basepan.write (95); 
delay (1500);




}
