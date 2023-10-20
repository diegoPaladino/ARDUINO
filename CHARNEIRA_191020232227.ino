/* Programa Gerador de Caracter Especial no LCD
   Blog Eletrogate - https://blog.eletrogate.com/guia-completo-do-display-lcd-arduino/
   Arduino Nano - LCD 16/2 azul - IDE 1.8.5
   Gustavo Murta   12/abril/2018
   Biblioteca LiquidCrystal https://github.com/arduino-libraries/LiquidCrystal
*/

#include <LiquidCrystal.h>        // usando a biblioteca LiquidCrystal

const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7; // definicao dos pinos do Display
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);                // configurando os pinos


byte customChar[8] =              // Matriz do caracter especial 
{
  0b00000,
  0b11011,
  0b11011,
  0b00100,
  0b00100,
  0b10001,
  0b01110,
  0b00000
};

void setup()                             // ate 8 caracteres especiais podem ser criados
{
  lcd.clear();                           // limpa a tela
  lcd.createChar(1, customChar);         // criando o caracter especial 1
  lcd.begin(16, 2);                      // definindo o LCD - 16 colunas e 2 linhas
  lcd.write((byte)1);                    // imprimindo o carcter especial 1
 }

void loop()
{
}
