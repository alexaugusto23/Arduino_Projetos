#include "Wire.h"
#include <LiquidCrystal.h>
 
#define DS1302_ADDRESS 0x68 // Modulo RTC no endereco 0x68
 
LiquidCrystal lcd(4,5,6,7,3); 
byte zero = 0x00; 
 
void setup(){
 Wire.begin(); 
 lcd.backlight(); //Inicia o visor LCD com a luz ligada
 lcd.begin (16,2); 
 Serial.begin(9600); //Inicia a porta serial
  
 //A linha de comando abaixo serve para que você possa confirar a hora e data do seu modulo RTC
 // SelecionaDataeHora(); 
}
 
void loop()
{
 // Le os valores (data e hora) do modulo DS1307
 Wire.beginTransmission(DS1307_ADDRESS);
 Wire.write(zero);
 Wire.endTransmission();
 Wire.requestFrom(DS1307_ADDRESS, 7);
 int segundos = ConverteparaDecimal(Wire.read());
 int minutos = ConverteparaDecimal(Wire.read());
 int horas = ConverteparaDecimal(Wire.read() & 0b111111);
 int diadasemana = ConverteparaDecimal(Wire.read()); 
 int diadomes = ConverteparaDecimal(Wire.read());
 int mes = ConverteparaDecimal(Wire.read());
 int ano = ConverteparaDecimal(Wire.read());
 
 // Mostra os dados no display
 lcd.setCursor(0,0);
 lcd.print(" ");
 // Acrescenta o 0 (zero) se a hora for menor do que 10
 if (horas <10)
 lcd.print("0");
 lcd.print(horas);
 lcd.print(":");
 // Acrescenta o 0 (zero) se minutos for menor do que 10
 if (minutos < 10)
 lcd.print("0");
 lcd.print(minutos);
 lcd.print(":");
 // Acrescenta o 0 (zero) se minutos for menor do que 10
 if (segundos < 10)
 lcd.print("0");
 lcd.print(segundos);
 lcd.setCursor(2,1);
 // Mostra o dia da semana
 switch(diadasemana)
 {
 case 0:lcd.print("Dom");
 break;
 case 1:lcd.print("Seg");
 break;
 case 2:lcd.print("Ter");
 break;
 case 3:lcd.print("Qua");
 break;
 case 4:lcd.print("Qui");
 break;
 case 5:lcd.print("Sex");
 break;
 case 6:lcd.print("Sab");
 }
 lcd.setCursor(6,1);
 // Acrescenta o 0 (zero) se dia do mes for menor do que 10
 if (diadomes < 10)
 lcd.print("0");
 lcd.print(diadomes);
 lcd.print("/");
 // Acrescenta o 0 (zero) se mes for menor do que 10
 if (mes < 10)
 lcd.print("0");
 lcd.print(mes);
 lcd.print("/");
 lcd.print(ano);
}
 
void SelecionaDataeHora() //Seta a data e a hora do DS1307
{
 byte segundos = 00; // Valores de 0 a 59
 byte minutos = 47; //Valores de 0 a 59
 byte horas = 1; //Valores de 0 a 23
 byte diadasemana = 0; //Valores de 0 a 6 - 0=Domingo, 1 = Segunda, etc.
 byte diadomes = 10; //Valores de 1 a 31
 byte mes = 9; //Valores de 1 a 12
 byte ano = 17; //Valores de 0 a 99
 Wire.beginTransmission(DS1307_ADDRESS);
 Wire.write(zero); //Stop no CI para que o mesmo possa receber os dados
 
 //As linhas abaixo escrevem no CI os valores de 
 //data e hora que foram colocados nas variaveis acima
 Wire.write(ConverteParaBCD(segundos));
 Wire.write(ConverteParaBCD(minutos));
 Wire.write(ConverteParaBCD(horas));
 Wire.write(ConverteParaBCD(diadasemana));
 Wire.write(ConverteParaBCD(diadomes));
 Wire.write(ConverteParaBCD(mes));
 Wire.write(ConverteParaBCD(ano));
 Wire.write(zero);
 Wire.endTransmission(); 
}
 
byte ConverteParaBCD(byte val)
{ 
 //Converte o número de decimal para BCD
 return ( (val/10*16) + (val%10) );
}
 
byte ConverteparaDecimal(byte val) 
{ 
 //Converte de BCD para decimal
 return ( (val/16*10) + (val%16) );
}
