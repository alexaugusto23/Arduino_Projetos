#include <LiquidCrystal.h>

//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(2, 4, 10, 11, 12, 13);

void setup()
{
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
  
}

void loop()

{ 
  
  lcd.setCursor(0,0);
  lcd.print("Parabens");
  lcd.setCursor(0,1);
  lcd.leftToRight();
  delay(2000);
  lcd.print("AMOR 28 Anos!!!");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("Te Amooo Momo");
  
  
}
