#include <Wire.h>

const int sensorPin = A0; // Define the sensor pin

void setup() {
  Serial.begin(9600);
}

void updateLevel() {
  int sensorValue = analogRead(sensorPin);
  float voltage = sensorValue * (5.0 / 1023.0);
  Serial.print("Liquid Level Voltage: ");
  Serial.println(voltage);
}

void loop() {
  updateLevel();
  delay(1000); // Update every second
}
