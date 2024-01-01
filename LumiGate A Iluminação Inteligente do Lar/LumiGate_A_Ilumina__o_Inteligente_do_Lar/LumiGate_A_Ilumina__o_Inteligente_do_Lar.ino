#include <Arduino.h>

// Constantes e variáveis globais
const int sensorCorrentePin = A0;  // Substitua pelo pino conectado ao sensor de corrente
const int botaoPin = 2;            // Substitua pelo pino conectado ao botão
const int ledPin = 3;              // Substitua pelo pino conectado ao relé ou MOSFET da fita de LED

bool estadoLed = false;            // Estado atual do LED (ligado/desligado)

void setup() {
  pinMode(sensorCorrentePin, INPUT);
  pinMode(botaoPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  digitalWrite(ledPin, LOW);       // Inicia com a fita de LED desligada
}

void loop() {
  verificarMotorPortao();
  verificarBotao();
}

void verificarMotorPortao() {
  int valorSensor = analogRead(sensorCorrentePin);
  if (valorSensor > 500) {  // Ajuste esse valor conforme a calibração do seu sensor
    acenderLed();
  }
}

void verificarBotao() {
  if (digitalRead(botaoPin) == LOW) {  // Verifica se o botão foi pressionado
    estadoLed = !estadoLed;            // Alterna o estado do LED
    digitalWrite(ledPin, estadoLed);   // Atualiza o estado do LED
    delay(500);                        // Debounce para evitar leituras múltiplas
  }
}

void acenderLed() {
  if (!estadoLed) {                    // Verifica se o LED já está ligado
    digitalWrite(ledPin, HIGH);        // Liga o LED
    estadoLed = true;
  }
}
