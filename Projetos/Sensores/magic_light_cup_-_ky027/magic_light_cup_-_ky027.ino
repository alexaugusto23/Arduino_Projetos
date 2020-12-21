const int led = 8;

int sensorValue;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode (led,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:


sensorValue = analogRead (A0);

if (sensorValue >= 500){

digitalWrite(led, HIGH);
}
else {
digitalWrite(led, LOW);  
}

Serial.println(sensorValue);
delay(10);





}
