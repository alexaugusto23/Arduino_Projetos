
    const int analogInPin = A0; // Pino de entrada analógica conectado ao potenciômetro
    int sensorValue = 0; // Valor lido do potenciômetro
    int timer = 0; // Valor do atraso
    
void setup() {

  // Define os pinos digitais 12 e 11 como saídas
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {

  // Inicia um loop para acender e apagar  os leds  com um atraso entre os estados

  sensorValue = analogRead(analogInPin); // Lê o valor do potenciômetro
  timer = map (sensorValue, 0, 1023, 10, 500); // atraso entre 10 e 500 ms
  digitalWrite (12, HIGH); // Led Acende
  delay (timer); // Atraso depende do valor do potenciômetro
  digitalWrite (12, LOW); // Led apaga
  delay (timer); 
  digitalWrite (12, HIGH);
  delay (timer);
  digitalWrite (12, LOW);

  digitalWrite (11, HIGH); // Led Acende
  delay (timer); // Atraso depende do valor do potenciômetro
  digitalWrite (11, LOW); // Led apaga
  delay (timer); 
  digitalWrite (11, HIGH);
  delay (timer);
  digitalWrite (11, LOW);
  
 }






