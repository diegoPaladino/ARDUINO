// Definições dos pinos
const int fimDeCursoPin = 2; // Pino para a chave fim de curso
const int relePin = 3;       // Pino para controlar o relé
const int sensorPresencaPin = 4; // Pino para o sensor de presença

// Variáveis de controle
bool luzAcesa = false;
unsigned long tempoLuzAcesa;
unsigned long tempoSemPresenca;

void setup() {
  pinMode(fimDeCursoPin, INPUT_PULLUP); // Configura como entrada com resistor interno de pull-up
  pinMode(relePin, OUTPUT);             // Configura como saída para o relé
  pinMode(sensorPresencaPin, INPUT);    // Configura como entrada para o sensor de presença
  digitalWrite(relePin, LOW);           // Inicia com o relé desligado
}

void loop() {
  // Verifica se a chave fim de curso foi acionada
  if (digitalRead(fimDeCursoPin) == LOW) {
    acenderLuzes();
  }

  // Se as luzes estiverem acesas, inicia o monitoramento de presença após 1 minuto
  if (luzAcesa && millis() - tempoLuzAcesa > 60000) {
    if (digitalRead(sensorPresencaPin) == HIGH) {
      // Se houver presença, reinicia a contagem do tempo sem presença
      tempoSemPresenca = millis();
    } else if (millis() - tempoSemPresenca > 120000) {
      // Se passarem 2 minutos sem detectar presença, apaga as luzes
      apagarLuzes();
    }
  }
}

void acenderLuzes() {
  if (!luzAcesa) {
    digitalWrite(relePin, HIGH); // Aciona o relé
    luzAcesa = true;
    tempoLuzAcesa = millis();    // Registra o momento que as luzes foram acesas
    tempoSemPresenca = millis(); // Inicia a contagem de tempo sem presença
  }
}

void apagarLuzes() {
  digitalWrite(relePin, LOW); // Desaciona o relé
  luzAcesa = false;
}
