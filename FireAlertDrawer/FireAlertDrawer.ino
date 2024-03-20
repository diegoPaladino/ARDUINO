// FireAlertDrawer.ino
#include <NewPing.h>

#define SOUND_SENSOR_PIN A0
#define SOUND_THRESHOLD 400
#define BUZZER_PIN 9
#define BUZZER_FREQUENCY 4000 // Frequência incômoda para o ouvido humano
#define BUZZER_DURATION 1000

void setup() {
  pinMode(SOUND_SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(SOUND_SENSOR_PIN);
  if (sensorValue > SOUND_THRESHOLD) {
    tone(BUZZER_PIN, BUZZER_FREQUENCY, BUZZER_DURATION);
  }
  delay(100);
}
##make some frequencies
