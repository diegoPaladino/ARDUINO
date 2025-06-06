#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Change address if needed

void setup() {
  Wire.begin(21, 22);  // ESP32 SDA, SCL
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Teste LCD");
  lcd.setCursor(0, 1);
  lcd.print("Linha 2 OK!");
}

void loop() {
}
