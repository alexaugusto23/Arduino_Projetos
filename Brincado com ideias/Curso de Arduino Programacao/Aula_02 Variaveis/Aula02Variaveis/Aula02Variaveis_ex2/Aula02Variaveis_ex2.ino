void setup() {

pinMode(10, OUTPUT);
pinMode(9, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

int intervaloPisca1;
intervaloPisca1 = 100;

int intervaloPisca2;
intervaloPisca2 = 2000;

digitalWrite(10,HIGH);
digitalWrite(9,LOW);
delay(intervaloPisca1);

digitalWrite(10,LOW);
digitalWrite(9,HIGH);
delay(intervaloPisca2);
}
