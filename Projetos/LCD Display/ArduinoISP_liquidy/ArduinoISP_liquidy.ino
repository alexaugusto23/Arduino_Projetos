#include <LiquidCrystal.h>

//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(2, 3, 4, 10, 11, 12, 13);

void setup()
{
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.write("claudia&Alex");
  lcd.setCursor(0,1);
  lcd.write("Te Amo");
  
}

void loop()

{
}
