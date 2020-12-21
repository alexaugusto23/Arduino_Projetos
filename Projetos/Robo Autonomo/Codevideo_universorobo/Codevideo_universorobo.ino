//Incluindo biblioteca Ultrasonic.h
#include "Ultrasonic.h"

//Criando objeto ultrasonic e definindo as portas digitais
//do Trigger - 9 - e Echo - 10
Ultrasonic SensorUltrassonico1(9, 10);

long Microsegundos = 0;// Variável para armazenar o valor do tempo da reflexão do som refletido pelo objeto fornecido pela biblioteca do sensor
float DistanciaemCM = 0;// Variável para armazenar o valor da distância a ser convertido por uma função da própria bilbioteca do sensor

void setup() {

  Serial.begin(115200);// Inicia a comunicação seria com velocidade de 115200 bits por segundo

  delay(3000);// Tempo de espera para inicialização (para dar tempo de por o robô no chão)
}

void loop() {



  //Convertendo a distância em CM e lendo o sensor
  DistanciaemCM = SensorUltrassonico1(SensorUltrassonico1.timing(), Ultrasonic::CM);

  Serial.print(DistanciaemCM);
  Serial.println(" cm");


  if (DistanciaemCM <= 40) {// Se a distância lida pelo sensor for menor ou igual que 40 centimetros
    //Velocidade motor lado esquerdo
    analogWrite( VelocidadeMotorLadoEsquerdo, ValorVelocidadeMotorLadoEsquerdo);

    //Velocidade motor lado direito
    analogWrite( VelocidadeMotorLadoDireito, ValorVelocidadeMotorLadoDireito);

    // Motor lado esquerdo para trás
    digitalWrite(MotorLadoEsquerdo1, HIGH);
    digitalWrite(MotorLadoEsquerdo2, LOW);


    // Motor lado direito para trás
    digitalWrite(MotorLadoDireito1, HIGH);
    digitalWrite(MotorLadoDireito2, LOW);

    delay(700);// Tempo que ficará indo para trás


    // Motor lado esquerdo para frente
    digitalWrite(MotorLadoEsquerdo1, LOW);
    digitalWrite(MotorLadoEsquerdo2, HIGH);


    // Motor lado direito para trás
    digitalWrite(MotorLadoDireito1, HIGH);
    digitalWrite(MotorLadoDireito2, LOW);

    delay(200);// Tempo que ficará indo para o lado direito

  }


  else {// Se não, ou seja, se a distância for maior que 40 centimetros

    //Velocidade motor lado esquerdo
    analogWrite( VelocidadeMotorLadoEsquerdo, ValorVelocidadeMotorLadoEsquerdo);

    //Velocidade motor lado direito
    analogWrite( VelocidadeMotorLadoDireito, ValorVelocidadeMotorLadoDireito);

    // Motor lado esquerdo para frente
    digitalWrite(MotorLadoEsquerdo1, LOW);
    digitalWrite(MotorLadoEsquerdo2, HIGH);


    // Motor lado direito para frente
    digitalWrite(MotorLadoDireito1, LOW);
    digitalWrite(MotorLadoDireito2, HIGH);
  }

}





