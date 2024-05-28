// WaterShortageDetector - A water shortage detection system using Arduino
// Author: diegoPaladino
// Date: 2024-05-28

#define WATER_SENSOR_PIN A0  // Analog pin for water level sensor
#define LED_PIN 13           // Digital pin for LED indicator

void setup() {
  pinMode(WATER_SENSOR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int waterLevel = analogRead(WATER_SENSOR_PIN);

  if (waterLevel < 500) { // Threshold for water shortage
    digitalWrite(LED_PIN, HIGH); // Turn on LED to indicate water shortage
    Serial.println("Water shortage detected!");
  } else {
    digitalWrite(LED_PIN, LOW); // Turn off LED when water is sufficient
    Serial.println("Water level is sufficient.");
  }

  delay(1000); // Wait for 1 second before next reading
}
