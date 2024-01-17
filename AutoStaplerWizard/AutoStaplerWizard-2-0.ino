#include <Servo.h>

Servo staplerServo;
const int beamEmitterPin = 2;     // Emissor do feixe de luz
const int beamReceiverPin = A1;   // Receptor do feixe de luz
const int staplerPin = 9;         // Pino do servo motor
const int beamInterruptThreshold = 500; // Limiar para detecção de interrupção do feixe

void setup() {
  staplerServo.attach(staplerPin);
  pinMode(beamEmitterPin, OUTPUT);
  pinMode(beamReceiverPin, INPUT);
  digitalWrite(beamEmitterPin, HIGH);
}

void loop() {
  int beamStatus = analogRead(beamReceiverPin);

  if (beamStatus < beamInterruptThreshold) {
    activateStapler();
    delay(1000); // Evita múltiplos acionamentos
  }
}

void activateStapler() {
  staplerServo.write(180); // Posição para grampear
  delay(500);
  staplerServo.write(0);   // Retorna à posição inicial
}
