#include <HX711.h>

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 3;
const int LOADCELL_SCK_PIN = 2;

HX711 scale;

void setup() {
  Serial.begin(9600);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
}

void loop() {
  if (scale.is_ready()) {
    long reading = scale.read();
    float force = reading * 0.0098; // Convert reading to Newtons (assuming calibration factor 0.0098)
    Serial.print("Force: ");
    Serial.print(force);
    Serial.println(" N");
  } else {
    Serial.println("HX711 not found.");
  }
  delay(500);
}
