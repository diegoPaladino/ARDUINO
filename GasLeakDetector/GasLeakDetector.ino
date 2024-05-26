// GasLeakDetector.ino
// Version: 1.0
// Description: Detects gas leaks using two gas sensors connected to a smart house system
// Author: DiegoPaladino

const int gasSensor1Pin = A0; // Analog pin for gas sensor 1
const int gasSensor2Pin = A1; // Analog pin for gas sensor 2
const int ledPin = 13;        // Digital pin for LED indicator
const int threshold = 300;    // Threshold value for gas detection

void setup() {
  pinMode(gasSensor1Pin, INPUT);
  pinMode(gasSensor2Pin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  int sensorValue1 = analogRead(gasSensor1Pin);
  int sensorValue2 = analogRead(gasSensor2Pin);
  
  Serial.print("Sensor 1 Value: ");
  Serial.print(sensorValue1);
  Serial.print(" | Sensor 2 Value: ");
  Serial.println(sensorValue2);

  if (sensorValue1 > threshold || sensorValue2 > threshold) {
    digitalWrite(ledPin, HIGH); // Turn on LED if gas is detected
    Serial.println("Gas leak detected!");
  } else {
    digitalWrite(ledPin, LOW); // Turn off LED if no gas is detected
  }

  delay(1000); // Wait for 1 second before next reading
}
