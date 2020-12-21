

int led = 13;
int shock = A0;

int val = 0; 

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
pinMode(led,OUTPUT);
pinMode(shock, INPUT);
 digitalWrite(led, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:

 digitalWrite(led, LOW);
 
 val = digitalRead (shock);
 Serial.println(val);
 if (val == HIGH) {
  digitalWrite(led, LOW);
 }
 else {
  digitalWrite(led, HIGH);
 }

}


