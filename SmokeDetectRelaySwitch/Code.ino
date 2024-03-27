#define SMOKE_SENSOR A0 // Analog pin connected to the smoke sensor
#define RELAY_PIN 7     // Digital pin connected to the relay module

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(SMOKE_SENSOR, INPUT);
  Serial.begin(9600); // Start serial communication
}

void loop() {
  int smokeLevel = analogRead(SMOKE_SENSOR);
  Serial.print("Smoke level: ");
  Serial.println(smokeLevel);

  if (smokeLevel > 400) { // Threshold value to activate the relay
    digitalWrite(RELAY_PIN, HIGH); // Turns on the relay
    Serial.println("Relay activated!");
  } else {
    digitalWrite(RELAY_PIN, LOW); // Turns off the relay
  }

  delay(1000); // Delay for stability
}
