#include <RTClib.h>
#include <Adafruit_NeoPixel.h>

// Definições para a fita de LED
#define PIN_LED         6   // O pino onde a fita de LED está conectada
#define NUMPIXELS      30   // Número de LEDs na fita

// Definições para o RTC
#define RTC_I2C_ADDRESS 0x68

// Objetos do RTC e da fita de LED
RTC_DS3231 rtc;
Adafruit_NeoPixel pixels(NUMPIXELS, PIN_LED, NEO_GRB + NEO_KHZ800);

// Horário para iniciar a modulação da iluminação
const int startHour = 21;
const int startMinute = 21;

void setup() {
  Serial.begin(9600);

  // Inicializa a fita de LED
  pixels.begin();
  
  // Inicializa o módulo RTC
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
}

void loop() {
  DateTime now = rtc.now(); // Obter o horário atual

  // Verificar se é hora de iniciar a modulação da iluminação
  if (now.hour() == startHour && now.minute() >= startMinute) {
    modulateLighting(now);
  }

  delay(1000); // Espera um segundo antes de reiniciar o loop
}

void modulateLighting(DateTime currentTime) {
  // Cálculo de exemplo para ajust
// pesquisar niveis odeais de cores para 'ativar' sono no usuário 
