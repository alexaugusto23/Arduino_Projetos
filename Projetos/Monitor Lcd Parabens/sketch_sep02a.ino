#include <LiquidCrystal.h>

//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(2, 3, 4, 10, 11, 12, 13);

void setup()
{
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
  
}

void loop()

{ 
  
  lcd.setCursor(0,0);
  lcd.print("Ola Alex");
  lcd.setCursor(0,1);
  delay(2000);

  lcd.setCursor(0,0);
  lcd.print("Ola Alex");
  
  lcd.setCursor(0,1);
  lcd.print("1");
  delay(2000);
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Ola Alex");
  
  lcd.setCursor(0,1);
  lcd.print("2");
  delay(2000);
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Ola Alex");
  
  lcd.setCursor(0,1);
  lcd.print("3");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,1);

  
  
}
