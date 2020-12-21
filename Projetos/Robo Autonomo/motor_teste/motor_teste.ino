
// Motor A
int enaVelocidadeAd = 10;
int in1d = 5;
int in2d = 6;

// Motor B
int in3e = 7;
int in4e = 8;
int enbVelocidadeBe = 9; 

//variavel auxiliar
int velocidade = 0;


void setup() {
  // put your setup code here, to run once:


// Pino conectados as portas da ponte H
pinMode(enaVelocidadeAd,OUTPUT) ;
pinMode(in1d,OUTPUT) ;
pinMode(in2d,OUTPUT) ;
pinMode(in3e,OUTPUT) ;
pinMode(in4e,OUTPUT) ;
pinMode(enbVelocidadeBe,OUTPUT) ;

}

void loop() {
  // put your main code here, to run repeatedly:

/*Exemplo de velocidades no motor A*/
 
//Sentido 2
digitalWrite(in1d,HIGH);
digitalWrite(in2d,LOW);
 
//Alta
analogWrite(enaVelocidadeAd,230);
 
//Intermediaria
analogWrite(enaVelocidadeAd,150);
 
//Baixa
analogWrite(enaVelocidadeAd,80);
 
/*Exemplo de variacao de velocidade no motor B*/
 
//Sentido 2
digitalWrite(in3e,HIGH);
digitalWrite(in4e,LOW);
 
//velocidade de 0 a 255
while (enbVelocidadeBe < 255){
analogWrite(enbVelocidadeBe,velocidade);
velocidade = velocidade + 10;
delay(50);
}
//velocidade de 255 a 0
while (enbVelocidadeBe > 0){
analogWrite(enbVelocidadeBe,velocidade);
velocidade = velocidade - 10;
delay(50);
}
}


