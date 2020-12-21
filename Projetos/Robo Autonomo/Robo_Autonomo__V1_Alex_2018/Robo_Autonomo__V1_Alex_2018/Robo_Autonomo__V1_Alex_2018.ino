
/*
  ----------------  Robo_Autonomo__V1_Alex_2018  ----------------

   =================  Configuração do motor:  ================= 
                         motor             IN1         IN2
                       Horario           5V  HIGH    GND LOW
                       Anti Horario      GND LOW     5V  HIGH
                       Ponto morto       GND LOW     GND LOW
                       Freio             5V  HIGH    5V  HIGH

   =================  Configuração dos motores:  =================                       
                       Motor  1D e 2E     Sentido dos motores           Sentido da rotação de cada motor
                       Para Frente        M1D E 2E HIGH HIGH            5V  HIGH    GND LOW
                       Para Trás          M1D E 2E HIGH HIGH            GND LOW     5V  HIGH   
                       Parado             M1D E 2E LOW  LOW             GND LOW     GND LOW 
                       Freio              M1D E 2E LOW  LOW             5V  HIGH    5V  HIGH
                       Para Direita       M1D E 2E HIGH LOW             5V  HIGH    GND LOW
                       Para Esquerda      M1D E 2E LOW  HIGH            5V  HIGH    GND LOW
                                              
*/

#include <Servo.h>
#include <Ultrasonic.h>

//Criando objeto ultrasonic e definindo as portas digitais do demais dispositivos
// Porta digital 12 Trigger 
// Porta digital 11 Echo
Ultrasonic Sensorrobo(12, 11);

#define M1E IN1 5  // MOTOR2 ESQUERDO 
#define M1E IN2 4  // MOTOR2 ESQUERDO

#define M2D IN3 7 // MOTOR1 DIREITO
#define M2D IN4 6 // MOTOR1 DIREITO

#define Vle 10
#define Vld 9

#define buzzer A2 
#define laser 2

#define pin 3



Servo servorobo;




// =================  Velocidade dos motores:  ================= 

int VLE = 120;
int VLD = 80;


void setup() 
{

  Serial.begin (9600);    
  servorobo.attach(pin);

}

void loop() 

{
long Dist;
dist = Sensorrobo.Ranging(CM);
Serial.print(Dist); 
Serial.println ("Distancia em Centimetros = ");
delay (100);


}
