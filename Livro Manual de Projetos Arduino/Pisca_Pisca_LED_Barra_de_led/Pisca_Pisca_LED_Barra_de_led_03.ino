

  const int analogPin = A0; // Pino conectado ao potenciomentro
  const int ledCount = 9; // Número de Leds 
  int ledPins [] = {2,3,4,5,6,7,8,9,10}; // Pino conectados aos Leds



void setup() {
  for (int thisLed = 0; thisLed < ledCount; thisLed++) { 
  pinMode (ledPins[thisLed], OUTPUT); // Defini os pinos do led como saída
  }  
}
void loop() {

  int sensorReading = analogRead (analogPin); // Entrada analógica
  int ledLevel = map (sensorReading, 0, 1023, 0, ledCount); // Leitura dos leds e potenciômetro
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    if (thisLed < ledLevel) { // Acende os leds em sequência
      digitalWrite (ledPins[thisLed], HIGH);
    }
    else { // apaga os leds em sequência
      digitalWrite(ledPins[thisLed], LOW);
    }
    }
    }






