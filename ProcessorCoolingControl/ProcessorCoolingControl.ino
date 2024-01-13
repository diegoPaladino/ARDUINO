// ProcessorCoolingControl
// Controls a cooler based on the processor's temperature

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD display setup
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Relay pin
const int relayPin = 8;

// Temperature thresholds
const int tempThreshold = 80;

void setup() {
  // Initialize the LCD
  lcd.init();
  lcd.backlight();

  // Set relay pin as output
  pinMode(relayPin, OUTPUT);

  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    // Read the temperature from the serial monitor
    int coreTemp = Serial.parseInt();

    // Display temperature on LCD
    lcd.clear();
    lcd.print("Core Temp: ");
    lcd.print(coreTemp);
    lcd.print(" C");

    // Control the relay based on temperature
    if (coreTemp >= tempThreshold) {
      digitalWrite(relayPin, HIGH); // Turn on the cooler
    } else {
      digitalWrite(relayPin, LOW); // Turn off the cooler
    }
  }
  delay(5000); // Wait for 5000 milliseconds
}

