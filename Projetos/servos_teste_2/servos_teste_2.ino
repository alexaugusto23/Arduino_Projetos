#include <Servo.h>

Servo base;
Servo Altura;
Servo Angulo;
Servo Garra;

void setup() {
  // put your setup code here, to run once:

base.attach(3);
Altura.attach(4);
Angulo.attach(5);
Garra.attach(6);


}

void loop() {
  // put your main code here, to run repeatedly:

base.write(45);
Altura.write(45);
Angulo.write(45);
Garra.write(45);
delay(2000);

base.write(90);
Altura.write(-90);
Angulo.write(-90);
Garra.write(90);
delay(2000);

base.write(45);
Altura.write(45);
Angulo.write(45);
Garra.write(45);
delay(2000);


}
