#include <DHT.h>

// Definições dos pinos
const int sensorUmidadePin = A0;  // Pino conectado ao sensor de umidade do solo
const int relePin = 7;            // Pino conectado à válvula solenoide/rele

// Definições para o sensor DHT
#define DHTPIN 2     // Pino conectado ao sensor DHT
#define DHTTYPE DHT22   // DHT 22 (AM2302)
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(relePin, OUTPUT);
  pinMode(sensorUmidadePin, INPUT);
  dht.begin();
}

void loop() {
  // Ler a umidade do solo
  int umidadeSolo = analogRead(sensorUmidadePin);

  // Ler a temperatura e umidade do ar
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Calcular o ponto de orvalho
  float pontoOrvalho = calcularPontoOrvalho(h, t);

  // Condições para iniciar a irrigação
  if (umidadeSolo < 300 && pontoOrvalho < 18) {
    digitalWrite(relePin, HIGH); // Liga a válvula/bomba
    Serial.println("Irrigação iniciada!");
  } else {
    digitalWrite(relePin, LOW);  // Desliga a válvula/bomba
    Serial.println("Irrigação parada.");
  }

  // Aguardar um pouco antes de ler novamente
  delay(10000);
}

// Função para calcular o ponto de orvalho
float calcularPontoOrvalho(float h, float t) {
  float a = 17.27;
  float b = 237.7;
  float alpha = ((a * t) / (b + t)) + log(h / 100);
  return (b * alpha) / (a - alpha);
}
