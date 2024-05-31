#include <IRremote.h>
#include <DHT.h>

#define DHTPIN 2     // Pin where the DHT sensor is connected
#define DHTTYPE DHT11  // DHT 11 
#define IR_LED_PIN 3  // Pin where the IR LED is connected
#define TEMP_HIGH 30  // Temperature to turn on the AC
#define TEMP_LOW 24   // Temperature to turn off the AC

DHT dht(DHTPIN, DHTTYPE);
IRsend irsend;

void setup() {
  Serial.begin(9600);
  dht.begin();
  irsend.begin();
}

void loop() {
  float temperature = dht.readTemperature();
  Serial.print("Temperature: ");
  Serial.println(temperature);

  if (isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  if (temperature >= TEMP_HIGH) {
    turnOnAC();
  } else if (temperature <= TEMP_LOW) {
    turnOffAC();
  }

  delay(60000); // Check temperature every minute
}

void turnOnAC() {
  // Replace with actual IR code for turning on your specific LG AC
  unsigned int irSignal[] = {9000, 4500, 560, 1680, 560, 1680, 560, 560, 560, 1680, 560, 560, 560, 560, 560, 560, 560, 1680, 560, 560, 560, 1680, 560, 560, 560, 560, 560, 1680, 560, 1680, 560, 560, 560, 1680, 560, 1680, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 1680, 560, 1680, 560, 1680, 560, 560, 560, 560, 560, 560, 560, 1680, 560, 1680, 560, 1680, 560};
  irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), 38);
  Serial.println("AC turned ON");
}

void turnOffAC() {
  // Replace with actual IR code for turning off your specific LG AC
  unsigned int irSignal[] = {9000, 4500, 560, 1680, 560, 1680, 560, 560, 560, 1680, 560, 560, 560, 560, 560, 560, 560, 1680, 560, 560, 560, 1680, 560, 560, 560, 560, 560, 1680, 560, 1680, 560, 560, 560, 1680, 560, 1680, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 1680, 560, 1680, 560, 1680, 560, 560, 560, 560, 560, 560, 560, 1680, 560, 1680, 560, 1680, 560};
  irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), 38);
  Serial.println("AC turned OFF");
}
