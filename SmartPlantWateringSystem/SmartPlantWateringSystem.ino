#include <Servo.h>

// Define the pin numbers
const int moistureSensorPin = A0; // Soil moisture sensor connected to A0
const int waterPumpPin = 3;       // Relay module connected to digital pin 3

// Threshold for soil moisture level
const int drySoil = 300;

Servo myservo;  // create servo object to control a servo

void setup() {
  pinMode(moistureSensorPin, INPUT);
  pinMode(waterPumpPin, OUTPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600); // Start serial communication at 9600 baud rate
}

void loop() {
  int soilMoistureValue = analogRead(moistureSensorPin); // Read the value from the moisture sensor
  Serial.print("Soil Moisture = ");
  Serial.println(soilMoistureValue); // Print the soil moisture value to the serial monitor

  if (soilMoistureValue < drySoil) {
    digitalWrite(waterPumpPin, HIGH); // Turn on water pump
    delay(1000); // Keep the pump on for 1 second
    digitalWrite(waterPumpPin, LOW); // Turn off water pump
  } else {
    digitalWrite(waterPumpPin, LOW); // Ensure the pump is off
  }

  delay(2000); // Wait for 2 seconds before reading again
}
