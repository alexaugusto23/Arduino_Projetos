 
# define NUMREADINGS 25 // Aumente o número para melhorar a resolução dos dados

int senseLimit = 1023; // Aumente o número para diminuir a sensibilidade da antena ( até o máximo de 2013)
int probePin = 5; // Define o pino análogico 5 como o pino da antena
int val = 0; // Leitura do probePin

// Conexões dos pinos com o gráfico de barras de Led usando os resistores em série

int LED1 = 11;
int LED2 = 10;
int LED3 = 9;
int LED4 = 8;
int LED5 = 7;
int LED6 = 6;
int LED7 = 5;
int LED8 = 4;
int LED9 = 3;
int LED10 = 2;
 
int readings [NUMREADINGS]; // Leituras da entrada analógica
int index = 0; // Indíce da leitura atual
int total = 0; // Somatória das leituras
int average = 0; // Média final das leituras

void setup() {

  // Configura os pinos do gráfico de barras de LED como saídas

  pinMode (2, OUTPUT); 
  pinMode (3, OUTPUT);
  pinMode (4, OUTPUT); 
  pinMode (5, OUTPUT); 
  pinMode (6, OUTPUT); 
  pinMode (7, OUTPUT); 
  pinMode (8, OUTPUT); 
  pinMode (9, OUTPUT); 
  pinMode (10, OUTPUT);
  pinMode (11, OUTPUT);
  Serial.begin (9600); // Inicia a conexão serial com o IDE para depuração e outras finalidades 

for (int i = 0; i < NUMREADINGS; i++)
readings [i] = 0; // Inicializa todas as leituras com 0
}

void loop() {

  val = analogRead (probePin); // Faz uma leitura 
  if (val >= 1) { // Se a leitura não for zero, continue 
    val = constrain (val, 1, senseLimit); // Se a leitura for maior que o atual valor de senseLimit, atualize o valor de senseLimit com a leitura maior 
    val = map (val, 1, senseLimit, 1, 1023); // Mapeia o valor dentro do intervalo 1 a 1023 
    total -= readings[index]; // subtrai a última leitura
    readings [index] = val; // Lê do sensor
    total += readings [index]; // Adiciona leitura ao total
    index = (index + 1); // Avança para o próximo índice
    if (index >= NUMREADINGS) // Se foi atingido o final do conjunto
      index = 0; // Volta ao início
    average = total / NUMREADINGS; // Calcula a leitura  média 
 
  if ( average > 50) { // Se a leitura média for maior que 50    
    digitalWrite (LED1, HIGH); // Acenda o primeiro LED 
    }
    else {                       // Caso contrário
    digitalWrite (LED1, LOW); // Apague esse LED
    }
  
  if ( average > 150) { // Se a leitura média for maior que 50    
    digitalWrite (LED2, HIGH); // Acenda o primeiro LED 
    }
    else {                       // Caso contrário
    digitalWrite (LED2, LOW); // Apague esse LED
    }

  if ( average > 250) { // Se a leitura média for maior que 50    
    digitalWrite (LED3, HIGH); // Acenda o primeiro LED 
    }
    else {                       // Caso contrário
    digitalWrite (LED3, LOW); // Apague esse LED
    }

  if ( average > 350) { // Se a leitura média for maior que 50    
    digitalWrite (LED4, HIGH); // Acenda o primeiro LED 
    }
    else {                       // Caso contrário
    digitalWrite (LED4, LOW); // Apague esse LED
    }

  if ( average > 450) { // Se a leitura média for maior que 50    
    digitalWrite (LED5, HIGH); // Acenda o primeiro LED 
    }
    else {                       // Caso contrário
    digitalWrite (LED5, LOW); // Apague esse LED
    }

  
  if ( average > 550) { // Se a leitura média for maior que 50    
    digitalWrite (LED6, HIGH); // Acenda o primeiro LED 
    }
    else {                       // Caso contrário
    digitalWrite (LED6, LOW); // Apague esse LED
    }


  if ( average > 650) { // Se a leitura média for maior que 50    
    digitalWrite (LED7, HIGH); // Acenda o primeiro LED 
    }
    else {                       // Caso contrário
    digitalWrite (LED7, LOW); // Apague esse LED
    }
    
  if ( average > 750) { // Se a leitura média for maior que 50    
    digitalWrite (LED8, HIGH); // Acenda o primeiro LED 
    }
    else {                       // Caso contrário
    digitalWrite (LED8, LOW); // Apague esse LED
    }  

  if ( average > 850) { // Se a leitura média for maior que 50    
    digitalWrite (LED9, HIGH); // Acenda o primeiro LED 
    }
    else {                       // Caso contrário
    digitalWrite (LED9, LOW); // Apague esse LED
    }
  
  if ( average > 950) { // Se a leitura média for maior que 50    
    digitalWrite (LED10, HIGH); // Acenda o primeiro LED 
    }
    else {                       // Caso contrário
    digitalWrite (LED10, LOW); // Apague esse LED
    }
    
    Serial.println(val); // Usa a saída para ajudar na calibração
  
  }
}
