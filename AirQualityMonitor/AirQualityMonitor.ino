// AirQualityMonitor: An Arduino project for air quality monitoring

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Adafruit_CCS811.h>

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme; // BME280 sensor
Adafruit_CCS811 ccs; // CCS811 sensor

void setup() {
  Serial.begin(9600);
  while (!Serial) delay(10); // wait for serial port to open

  if (!bme.begin(0x76)) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }

  if (!ccs.begin()) {
    Serial.println("Could not find a valid CCS811 sensor, check wiring!");
    while (1);
  }

  // Wait for the sensors to stabilize
  delay(1000);
  
  // Calibration of CCS811 sensor
  while(!ccs.available()) {
    delay(100);
  }

  ccs.setEnvironmentalData(bme.readHumidity(), bme.readTemperature());
}

void loop() {
  if (!ccs.available()) {
    Serial.println("CCS811 sensor not available!");
    return;
  }

  float temp = bme.readTemperature();
  float hum = bme.readHumidity();
  float pres = bme.readPressure() / 100.0F;

  ccs.setEnvironmentalData(hum, temp);

  if (ccs.readData()) {
    Serial.print("CO2: ");
    Serial.print(ccs.geteCO2());
    Serial.print(" ppm, TVOC: ");
    Serial.print(ccs.getTVOC());
    Serial.print(" ppb");

    Serial.print(", Temp: ");
    Serial.print(temp);
    Serial.print(" °C, Hum: ");
    Serial.print(hum);
    Serial.print(" %, Pres: ");
    Serial.print(pres);
    Serial.println(" hPa");
  } else {
    Serial.println("ERROR!");
  }

  delay(2000);
}
//implement at house and work