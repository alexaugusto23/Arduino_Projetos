
#include <Servo.h>

Servo esc; 

 int joyX = 0;
 int joyY = 1;
 
 int joyVal;

void setup()
{
esc.attach(3);
esc.writeMicroseconds(1000);
Serial.begin(9600);
}

void loop()
{
 joyVal = analogRead(joyX);
 joyVal = map (joyVal, 0, 1023, 1000, 2000);
 esc.writeMicroseconds(joyVal);
 delay(50);

  joyVal = analogRead(joyY);
 joyVal = map (joyVal, 0, 1023, 1000, 2000);
 esc.writeMicroseconds(joyVal);
 delay(50);

}




