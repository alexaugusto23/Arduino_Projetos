#include <LiquidCrystal.h>

//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(2,3,);

void setup()
{
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 4);
  lcd.setCursor(0,0);
  lcd.write("Ola ");
  
  
  
}

void loop()

{
}
