#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Substitua com suas informações de rede e Blynk
const char* ssid = "SEU_SSID";
const char* password = "SUA_SENHA";
const char* auth = "SEU_TOKEN_BLYNK";

// Pino do sensor de alarme
const int alarmPin = 2;

void setup() {
  pinMode(alarmPin, INPUT_PULLUP);
  Serial.begin(9600);
  connectToWiFi();
  Blynk.begin(auth, ssid, password);
}

void loop() {
  Blynk.run();
  checkAlarmStatus();
}

void connectToWiFi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi");
}

void checkAlarmStatus() {
  if (digitalRead(alarmPin) == LOW) {
    Serial.println("Alarm Triggered!");
    Blynk.notify("Alarme da casa disparado!");
  }
}
