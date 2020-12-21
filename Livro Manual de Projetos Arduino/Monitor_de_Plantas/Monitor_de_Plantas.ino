
  const int moistureAO = 0;
  int AO = 0; // Pino conectado ao AO no controlador
  int tmp = 0; // Valor do pino analógico
  int buzzPin = 11; // Pino conectado ao alarme sonoro piezoelétrico
  int LED = 13; // Pino conectado ao LED
    
void setup() {

  Serial.begin (9600); // Envia a leitura do Arduino para o IDE
  Serial.println ("Soil moisture sensor"); // Escreve a leitura registrada
  pinMode (moistureAO, INPUT); // 
  pinMode (buzzPin, OUTPUT); // Configura o pino como saída
  pinMode (LED, OUTPUT); // Configura o pino como saída    

}

void loop() {

  tmp = analogRead (moistureAO);
    if (tmp != AO){
    AO = tmp;
    Serial.println ("A = "); // Exibe o valor de resistência do sensor no IDE
    Serial.println (AO);
    }
  delay (1000); // Aguarda um segundo
    if (analogRead(0) > 1000) { // Se a leitura for maior que 900
    digitalWrite (buzzPin, HIGH); // O alarme sonoro soará
    digitalWrite (LED, HIGH); // O LED acenderá
    delay(1000); // Aguarda um segundo
    digitalWrite (buzzPin, LOW); // O alarme sonoro desliga
    digitalWrite (LED, HIGH);     
    }
    else {
    digitalWrite (buzzPin, LOW); // Se a leitura for menor que 900 o alrme e o led permanecerão desligados
    digitalWrite (LED,LOW); 
    }
}

