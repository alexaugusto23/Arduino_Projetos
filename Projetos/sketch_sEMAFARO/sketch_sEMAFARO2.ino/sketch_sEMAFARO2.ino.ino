
// 04 Semáforo interativo

int carRed = 4; // estabelece o semáforo para carros

int carYellow = 3;

int carGreen = 2;

int pedRed = 12; // estabelece o semáforo para pedestres

int pedGreen = 11;

int button = 8; // pino do botão

int crossTime = 5000; // tempo para que os pedestres atravessem

unsigned long changeTime; // tempo desde que o botão foi pressionado

void setup() {

pinMode(4, OUTPUT);  // carRed

pinMode(3, OUTPUT); // carYellow

pinMode(2, OUTPUT); // carGreen

pinMode(12, OUTPUT); // pedRed

pinMode(11, OUTPUT); // pedGreen

pinMode(8, INPUT); // botão no pino 8

// acende a luz verde

digitalWrite(2, HIGH);

digitalWrite(12, HIGH);

}

void loop() {

int state = digitalRead(8);

/* verifica se o botão foi pressionado e se transcorreram 5 segundos desde a última vez que

isso ocorreu */

if (state == HIGH && (millis() - changeTime) > 5000) {

delay(1000);

// Chama a função para alterar as luzes

changeLights();

}

}

void changeLights() {

digitalWrite(2, LOW); // apaga o verde

digitalWrite(3, HIGH); // acende o amarelo

delay(2000); // espera 2 segundos

digitalWrite(3, LOW); // apaga o amarelo

digitalWrite(4, HIGH); // acende o vermelho

delay(1000); // espera 1 segundo, por segurança

digitalWrite(12, LOW); // apaga o vermelho dos pedestres

digitalWrite(11, HIGH); // acende o verde dos pedestres

delay(crossTime); // espera por um intervalo de tempo predefinido

// pisca o verde dos pedestres

for (int x=0; x<10; x++) {

digitalWrite(12, LOW); // pedgreen

delay(250);

digitalWrite(12, HIGH); // pedgreen
digitalWrite(11, LOW); // pedgreen
delay(250);

}

// acende o vermelho dos pedestres

digitalWrite(12, HIGH); //pedred
digitalWrite(11, LOW); //pedred

delay(500);

digitalWrite(3, LOW); // acende o amarelo

digitalWrite(4, LOW); // apaga o vermelho

delay(1000);

digitalWrite(2, HIGH); // acende o verde

digitalWrite(3, LOW); // apaga o amarelo

// registra o tempo desde a última alteração no semáforo

changeTime = millis();

// depois retorna para o loop principal do programa

}

