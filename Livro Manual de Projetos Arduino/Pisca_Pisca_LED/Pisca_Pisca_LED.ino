

const int buttonPin = 2; // Pino conectado ao botão de pressão
const int ledPin = 13; // Pino conectado ao Led
int buttonState = 0; // Atribui um valor ao botão de pressão

void setup() {

  pinMode(ledPin,OUTPUT); // Configura o pino led como saída
  pinMode(buttonPin,INPUT); // Configura o pino botão de pressão como entrada
}
void loop() {
  buttonState=digitalRead(buttonPin); // lê a entrada do pino 2
  if (buttonState == HIGH)
  { // Se o botão de pressão estiver pressionado, e configurado como HIGH
  digitalWrite(ledPin, HIGH); // Acende o LED
  }
  else {
  digitalWrite(ledPin, LOW); // Caso contrário apaga o LED
  }
}
    
  }
  
  
  }
