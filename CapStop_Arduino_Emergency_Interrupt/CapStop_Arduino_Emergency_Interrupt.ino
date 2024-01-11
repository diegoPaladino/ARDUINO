/*
  CapStop: Emergency Interrupt System
  Utiliza sensores capacitivos para interromper imediatamente a execução de códigos no Arduino.
*/

#include <CapacitiveSensor.h>

// Definir os pinos dos sensores capacitivos
CapacitiveSensor capSensor1 = CapacitiveSensor(4, 2); // Pinos 4 (send) e 2 (receive)
CapacitiveSensor capSensor2 = CapacitiveSensor(5, 3); // Pinos 5 (send) e 3 (receive)

void setup() {
  Serial.begin(9600);
  // Inicialização dos sensores
  capSensor1.set_CS_AutocaL_Millis(0xFFFFFFFF);
  capSensor2.set_CS_AutocaL_Millis(0xFFFFFFFF);
}

void loop() {
  long sensorValue1 = capSensor1.capacitiveSensor(30);
  long sensorValue2 = capSensor2.capacitiveSensor(30);

  // Verifica se algum sensor foi ativado
  if (sensorValue1 > 1000 || sensorValue2 > 1000) {
    emergencyInterrupt();
  }

  // Coloque aqui o restante do código que deseja executar
}

void emergencyInterrupt() {
  // Função para lidar com a interrupção de emergência
  Serial.println("Emergência Detectada! Programa Interrompido.");
  // Inserir código para lidar com a interrupção (e.g., desligar motores, parar processos)
  while(true) {} // Mantém o programa em um loop infinito para evitar mais execuções
}
