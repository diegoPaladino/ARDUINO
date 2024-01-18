#include <DHT.h>

// DHT Sensor
#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

// MQ-135 Gas Sensor
const int MQ135_PIN = A0;

// Exhaust Fan
const int FAN_PIN = 3;

// Thresholds
const float HUMIDITY_THRESHOLD = 60.0; // percentage
const int GAS_THRESHOLD = 300; // change based on calibration

void setup() {
  pinMode(FAN_PIN, OUTPUT);
  digitalWrite(FAN_PIN, LOW);
  dht.begin();
  Serial.begin(9600);
}

void loop() {
  // Read humidity
  float humidity = dht.readHumidity();
  
  // Read gas sensor
  int gasValue = analogRead(MQ135_PIN);

  // Check if conditions are met to turn on the fan
  if (humidity > HUMIDITY_THRESHOLD || gasValue > GAS_THRESHOLD) {
    digitalWrite(FAN_PIN, HIGH);
  } else {
    digitalWrite(FAN_PIN, LOW);
  }

  // Print the readings for debugging
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Gas: ");
  Serial.println(gasValue);

  delay(1000); // Delay for stability
}
