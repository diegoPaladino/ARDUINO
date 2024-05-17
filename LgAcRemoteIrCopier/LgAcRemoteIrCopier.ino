#include <IRremote.h>

const int RECV_PIN = 11; // Pino conectado ao receptor IR
const int IR_LED_PIN = 3; // Pino conectado ao emissor IR

IRrecv irrecv(RECV_PIN);
IRsend irsend;
decode_results results;
unsigned long powerCode = 0; // Variável para armazenar o código de ligar/desligar

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Inicia o receptor
  pinMode(IR_LED_PIN, OUTPUT); // Define o pino do emissor IR como saída
  Serial.println("Press the power button on the remote to capture the code.");
}

void loop() {
  if (irrecv.decode(&results)) {
    powerCode = results.value; // Captura o código recebido
    Serial.print("Power code captured: 0x");
    Serial.println(powerCode, HEX);
    irrecv.resume(); // Recebe o próximo valor
  }

  if (powerCode != 0) {
    Serial.println("Sending the captured power code...");
    irsend.sendLG(powerCode, 32); // Envia o código capturado
    delay(5000); // Aguarda 5 segundos antes de enviar novamente
  }
}
