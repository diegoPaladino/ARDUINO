// SmartGardenIrrigationSystem
// Automated garden irrigation system for small house

#include <DHT.h>

// Constants
#define DHTPIN 2          // Pin where the DHT sensor is connected
#define DHTTYPE DHT11     // DHT 11
#define SOIL_SENSOR_PIN A0 // Pin where the soil moisture sensor is connected
#define PUMP_PIN 3        // Pin where the relay module controlling the pump is connected
#define MOISTURE_THRESHOLD 300 // Threshold for soil moisture level

// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(SOIL_SENSOR_PIN, INPUT);
  pinMode(PUMP_PIN, OUTPUT);
  digitalWrite(PUMP_PIN, LOW); // Ensure pump is off initially
}

void loop() {
  int soilMoisture = analogRead(SOIL_SENSOR_PIN);
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  Serial.print("Soil Moisture: ");
  Serial.println(soilMoisture);
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" *C");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  if (soilMoisture < MOISTURE_THRESHOLD) {
    digitalWrite(PUMP_PIN, HIGH); // Turn the pump on
    Serial.println("Pump ON");
  } else {
    digitalWrite(PUMP_PIN, LOW); // Turn the pump off
    Serial.println("Pump OFF");
  }

  delay(2000); // Wait for 2 seconds before next reading
}
