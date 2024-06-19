#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <Wire.h>
#include <RTClib.h>

// Configurações do WiFi
const char* ssid = "SEU_SSID";
const char* password = "SUA_SENHA";

// Configurações do servidor remoto
const char* serverName = "http://seu_servidor_remoto.com/relay";

// Pinos do Arduino
const int gateSensorPin = D1;  // Sensor do portão
const int relayPin = D2;       // Módulo relé

// RTC
RTC_DS3231 rtc;

void setup() {
  Serial.begin(115200);
  pinMode(gateSensorPin, INPUT);
  pinMode(relayPin, OUTPUT);

  // Conecta ao WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao WiFi...");
  }
  Serial.println("Conectado ao WiFi!");

  // Inicializa RTC
  if (!rtc.begin()) {
    Serial.println("Não foi possível inicializar o RTC");
    while (1);
  }

  // Verifica se o RTC está funcionando
  if (rtc.lostPower()) {
    Serial.println("RTC perdeu a energia, configurando a data e hora...");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop() {
  DateTime now = rtc.now();
  
  // Checa se é noite (ajuste os valores conforme necessário)
  bool isNight = now.hour() >= 18 || now.hour() < 6;
  
  // Checa se o portão está aberto
  bool gateOpened = digitalRead(gateSensorPin) == HIGH;

  if (isNight && gateOpened) {
    sendRelaySignal();
    delay(10000); // Evita enviar múltiplos sinais rapidamente
  }

  delay(1000); // Ajuste o tempo de loop conforme necessário
}

void sendRelaySignal() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverName);
    int httpResponseCode = http.GET();

    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    } else {
      Serial.print("Erro no envio da solicitação HTTP: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  } else {
    Serial.println("WiFi desconectado");
  }
}
