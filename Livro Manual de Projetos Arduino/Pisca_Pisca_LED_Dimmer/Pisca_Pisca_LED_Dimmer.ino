

int potPin = A0; // Pino de entrada analógica conectado ao potenciômetro
int potValue = 0; // Valor que será lido do potenciometa 
int led = 9; // Pino 9 (conectado ao LED) é compatível com PWM executa uma única vez no ínicio do programa

void setup() {

  pinMode(led,OUTPUT); // Configura o pino 9 led como saída
}
void loop() {
  potValue = analogRead (potPin); // Lê p valor do potenciômetro do pino A0  
  analogWrite (led, potValue/4); //envia o valor do potenciômetro para o LED para controlar o brilho com PWM
  delay(10);
}





