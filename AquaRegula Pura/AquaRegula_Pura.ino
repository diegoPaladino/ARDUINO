// Definições dos pinos
const int pinSensorNivel = 2;  // Pino conectado ao sensor de nível de água
const int pinValvula = 3;      // Pino conectado à válvula solenoide

void setup() {
  pinMode(pinSensorNivel, INPUT); // Define o pino do sensor como entrada
  pinMode(pinValvula, OUTPUT);    // Define o pino da válvula como saída
  digitalWrite(pinValvula, HIGH); // Inicia com a válvula fechada
}

void loop() {
  int nivelAgua = digitalRead(pinSensorNivel); // Lê o estado do sensor de nível de água

  // Se o sensor detectar água (supondo que LOW significa que a água atingiu o sensor)
  if (nivelAgua == LOW) {
    digitalWrite(pinValvula, HIGH); // Fecha a válvula
  } else {
    digitalWrite(pinValvula, LOW); // Abre a válvula
  }
  
  // Um pequeno atraso para evitar leituras ruidosas
  delay(2000);
}
#seeifrun
