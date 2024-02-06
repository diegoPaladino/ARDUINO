#include <Servo.h> 

Servo blindServo;  // cria objeto servo para controlar a persiana

int servoPin = 3;  // pino do servo
int openPosition = 0;  // posição totalmente aberta
int closePosition = 180;  // posição totalmente fechada
int currentPosition = closePosition;  // posição inicial

void setup() {
  blindServo.attach(servoPin);  // anexa o servo no pino
  blindServo.write(currentPosition);  // move para a posição inicial
}

void loop() {
  int command = Serial.read();  // lê o comando serial (A para abrir, F para fechar)

  if (command == 'A') {
    currentPosition = openPosition;
  } else if (command == 'F') {
    currentPosition = closePosition;
  }

  blindServo.write(currentPosition);  // move a persiana para a posição desejada
  delay(15);  // espera o servo alcançar a posição
}

// write a new code this. or upgrade it
