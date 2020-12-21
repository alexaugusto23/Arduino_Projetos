/*
init  
begin 
clear 
home  
noDisplay 
display 
noBlink 
blink 
noCursor  
cursor  
scrollDisplayLeft 
scrollDisplayRight  
leftToRight 
rightToLeft 
shiftIncrement  
shiftDecrement  
noBacklight 
backlight 
autoscroll  
noAutoscroll  
createChar  
setCursor 
print 
blink_on 
blink_off 
cursor_on 
cursor_off  
setBacklight  
load_custom_character 
printstr 
 */



#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C LCD(0x3F, 20, 4);

void setup(){

    LCD.begin();
   
}
void loop(){
   
    LCD.setCursor (4,1);
    LCD.print(" Ola momo S2 ");
    LCD.setCursor (6,2);
    LCD.print(" Te amo ");
    delay(600);
    LCD.leftToRight();
    LCD.setBacklight (HIGH);
    LCD.clear();
    delay(1000);
      
       
  
  
} //end loop





