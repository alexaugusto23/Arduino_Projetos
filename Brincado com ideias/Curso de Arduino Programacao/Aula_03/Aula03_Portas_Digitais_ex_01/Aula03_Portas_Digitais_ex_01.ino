
int estadoBotao;


void setup() {
  
pinMode(10,OUTPUT);
pinMode(9,OUTPUT);
pinMode(7,INPUT);


}

void loop() {
  
  estadoBotao = digitalRead(7);
  
  digitalWrite(10,estadoBotao); 
  digitalWrite(9,!estadoBotao);

}
