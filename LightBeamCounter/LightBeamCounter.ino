#include <EEPROM.h>

// Pinos de conexão
const int laserPin = 8; // Pino do módulo laser KY-008
const int ledReceiverPin = 2; // Pino do LED receptor
const int eepromAddress = 0; // Endereço na EEPROM para armazenar a contagem

// Variáveis globais
int count = 0;
bool beamInterrupted = false;

void setup() {
    // Inicializa os pinos
    pinMode(laserPin, OUTPUT);
    pinMode(ledReceiverPin, INPUT);
    
    // Liga o laser
    digitalWrite(laserPin, HIGH);

    // Inicializa a comunicação serial para debug
    Serial.begin(9600);

    // Lê a contagem armazenada na EEPROM
    count = EEPROM.read(eepromAddress);
    Serial.print("Initial count from EEPROM: ");
    Serial.println(count);
}

void loop() {
    // Verifica o estado do receptor LED
    int sensorValue = digitalRead(ledReceiverPin);
    
    // Verifica se o feixe de luz foi interrompido
    if (sensorValue == LOW && !beamInterrupted) {
        beamInterrupted = true;
        count++;
        EEPROM.write(eepromAddress, count);
        Serial.print("Beam interrupted! Count: ");
        Serial.println(count);
    } 
    // Verifica se o feixe de luz foi restabelecido
    else if (sensorValue == HIGH && beamInterrupted) {
        beamInterrupted = false;
    }
    
    // Pequeno atraso para evitar leituras muito rápidas
    delay(100);
}
