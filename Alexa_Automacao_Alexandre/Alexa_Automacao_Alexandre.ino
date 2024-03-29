/ Programa para receber comandos da Alexa, acionar reles, mostrar resultado no display e enviar por Whatsapp
// 21/01/2024 - Alexandre Costa/ChatGPT


#ifdef ARDUINO_ARCH_ESP32
#include <WiFi.h>
#else
#include <ESP8266WiFi.h>
#endif
#include <Espalexa.h>
#include <HTTPClient.h>
#include <UrlEncode.h>

#include <LiquidCrystal.h> // Biblioteca para o lcd
const int rs = 23, en = 22, d4 = 5, d5 = 18, d6 = 19, d7 = 21;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // Pinos do lcd
int inicio = 0;

#define pinLED 2
#define pinLuz2 4
#define pinLuz3 15
#define pinLuz4 16
#define pinLuz5 17

//PWM do ESP32
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;

//Controle Dimmer
uint8_t brilhoLED;
uint8_t brilhoLEDTarget;
#define timeChange 10
unsigned long lastChange;

// protótipos
boolean connectWifi();

// +código internacional do país + número de telefone
// Brasil +55, exemplo: 551188888888
String phoneNumber = "556284152222";
String apiKey = "6568461";

//funções de retorno
void firstLightChanged(uint8_t brightness);
void secondLightChanged(uint8_t brightness);
void thirdLightChanged(uint8_t brightness);
void fourthLightChanged(uint8_t brightness);
void fifthLightChanged(uint8_t brightness);

// Mude isso!!
const char* ssid = "Pctel";
const char* password = "1234567890abc";

boolean wifiConnected = false;

Espalexa espalexa;

EspalexaDevice* device3;  //isto é opcional

void sendMessage(String message) {

  // Dados para enviar com HTTP POST
  String url = "https://api.callmebot.com/whatsapp.php?phone=" + phoneNumber + "&text=" + urlEncode(message) + "&apikey=" + apiKey;
  Serial.println(url); // Imprime a URL na porta serial
  HTTPClient http; // Cria um objeto HTTPClient
  http.begin(url); // Inicia a conexão com a URL

  // Especifique o cabeçalho content-type
  http.addHeader("Content-Type", "application/x-www-form-urlencoded"); // Adiciona um cabeçalho ao pedido HTTP

  // Envie o pedido HTTP POST
  int httpResponseCode = http.POST(url); // Envia o pedido HTTP POST e armazena o código de resposta
  if (httpResponseCode == 200) { // Se o código de resposta for 200 (OK)
    Serial.println("Mensagem enviada com sucesso"); // Imprime uma mensagem de sucesso na porta serial
    Serial.println(" "); // Imprime uma linha em branco
  } else { // Se o código de resposta for diferente de 200
    Serial.println("Erro no envio da mensagem"); // Imprime uma mensagem de erro na porta serial
    Serial.print("HTTP response code: "); // Imprime o texto "HTTP response code: "
    Serial.println(httpResponseCode); // Imprime o código de resposta na porta serial
    Serial.println(" "); // Imprime uma linha em branco
  }

  // Liberte recursos
  http.end(); // Encerra a conexão HTTP
}

void setup() {
  pinMode(pinLED, OUTPUT); // Define o pino do LED como saída
  pinMode(pinLuz2, OUTPUT); // Define o pino da luz 2 como saída
  pinMode(pinLuz3, OUTPUT); // Define o pino da luz 3 como saída
  pinMode(pinLuz4, OUTPUT); // Define o pino da luz 4 como saída
  pinMode(pinLuz5, OUTPUT); // Define o pino da luz 5 como saída

  //PWM do ESP32
  ledcSetup(ledChannel, freq, resolution); // Configura o canal, a frequência e a resolução do PWM
  ledcAttachPin(pinLED, ledChannel); // Associa o pino do LED ao canal do PWM

  // Inicializa Serial
  Serial.begin(115200); // Inicia a comunicação serial com a velocidade de 115200 bps

  // Inicializa Display 16x2
  lcd.begin(16, 2); // Inicia o lcd com 16 colunas e 2 linhas
  lcd.print("Pctel Eletronica"); // Mostra uma mensagem inicial no lcd
  lcd.setCursor(0, 1); // Move o cursor para a segunda linha
  lcd.print("ESP32 com Alexa"); // Mostra uma mensagem inicial no lcd
  delay(2000);                   // espera dois segundos 

  // Inicializa conexão wifi
  wifiConnected = connectWifi(); // Chama a função connectWifi e armazena o resultado na variável wifiConnected

  if (wifiConnected) { // Se a conexão wifi foi bem sucedida

    // Defina seus dispositivos aqui.
    espalexa.addDevice("LED", firstLightChanged);           //definição mais simples, estado padrão desligado
    espalexa.addDevice("Rele 1", secondLightChanged);       //definição mais simples, estado padrão desligado
    espalexa.addDevice("Rele 2", thirdLightChanged);        //definição mais simples, estado padrão desligado
    espalexa.addDevice("Rele 3", fourthLightChanged);       //definição mais simples, estado padrão desligado
    espalexa.addDevice("Rele 4", fifthLightChanged);        //definição mais simples, estado padrão desligado
    
    // device3 = new EspalexaDevice("Cozinha", thirdLightChanged);   //você também pode criar os objetos Device você mesmo como aqui
    // espalexa.addDevice(device3);                                  //e depois adicioná-los
    // device3->setValue(128);                                       //isso permite que você, por exemplo, atualize seu valor de estado a qualquer momento!

    digitalWrite(pinLuz2, 1);
    digitalWrite(pinLuz3, 1);
    digitalWrite(pinLuz4, 1);
    digitalWrite(pinLuz5, 1);
    
    espalexa.begin();

  } else {
    while (1) {
      Serial.println("Não é possível conectar ao WiFi. Por favor, verifique os dados e reinicie o ESP.");
      delay(2500);
    }
  }
}

void loop() {
  espalexa.loop(); // chama a função loop do Espalexa para processar os comandos da Alexa

  if (brilhoLEDTarget != brilhoLED) { // se o brilho alvo for diferente do brilho atual

    if ((millis() - lastChange) >= timeChange) { // se o tempo desde a última mudança for maior ou igual ao tempo definido

      if (brilhoLED < brilhoLEDTarget) brilhoLED++; // aumenta o brilho em um passo
      if (brilhoLED > brilhoLEDTarget) brilhoLED--; // diminui o brilho em um passo

      ledcWrite(ledChannel, brilhoLED); // escreve o valor do brilho no canal do LED
      lastChange = millis(); // atualiza o tempo da última mudança
    }
  }

  delay(1); // espera um milissegundo
}


//nossas funções de retorno
void firstLightChanged(uint8_t brightness) {
  Serial.print("LED mudou para "); // imprime o estado do LED Bancada no serial
  lcd.clear(); // limpa o LCD
  lcd.print("LED: "); // imprime o nome do dispositivo na primeira linha do LCD

  //atualiza o brilho alvo do LED Bancada
  brilhoLEDTarget = brightness;

  //EXEMPLO
  if (brightness) {
    Serial.print("ON, brilho ");
    Serial.println(brightness); // imprime o brilho do LED Bancada no serial
    lcd.setCursor(6, 0); // posiciona o cursor na sétima coluna da primeira linha
    lcd.print(brightness); // imprime o brilho do LED Bancada no LCD
    sendMessage("LED ON"); // envia uma mensagem via WhatsApp para o número configurado

  } else {
    Serial.println("OFF"); // imprime o estado do LED Bancada no serial
    lcd.setCursor(6, 0); // posiciona o cursor na sétima coluna da primeira linha
    lcd.print("OFF"); // imprime o estado do LED Bancada no LCD
    sendMessage("LED OFF"); // envia uma mensagem via WhatsApp para o número configurado
  } 
}

void secondLightChanged(uint8_t brightness) {
  Serial.print("Rele 1: "); // imprime o estado do Rele 1 no serial
  lcd.clear(); // limpa o LCD
  lcd.print("Rele 1: "); // imprime o nome do dispositivo na primeira linha do LCD

  //liga ou desliga o Rele 1 de acordo com o brilho recebido
  digitalWrite(pinLuz2, !brightness);

  //EXEMPLO
  if (brightness) {
    Serial.print("ON"); // imprime o estado do Rele 1 no serial
    lcd.setCursor(9, 0); // posiciona o cursor na décima coluna da primeira linha
    lcd.print("ON"); // imprime o estado do Rele 1 no LCD
    sendMessage("Rele 1 ON"); // envia uma mensagem via WhatsApp para o número configurado
  } else {
    Serial.println("OFF"); // imprime o estado do Rele 1 no serial
    lcd.setCursor(9, 0); // posiciona o cursor na décima coluna da primeira linha
    lcd.print("OFF"); // imprime o estado do Rele 1 no LCD
    sendMessage("Rele 1 OFF"); // envia uma mensagem via WhatsApp para o número configurado
  }
}

void thirdLightChanged(uint8_t brightness) {
  Serial.print("Rele 2: "); // imprime o estado do Rele 2 no serial
  lcd.clear(); // limpa o LCD
  lcd.print("Rele 2: "); // imprime o nome do dispositivo na primeira linha do LCD

  //liga ou desliga o Rele 2 de acordo com o brilho recebido
  digitalWrite(pinLuz3, !brightness);

  //EXEMPLO
  if (brightness) {
    Serial.print("ON"); // imprime o estado do Rele 2 no serial
    lcd.setCursor(9, 0); // posiciona o cursor na décima coluna da primeira linha
    lcd.print("ON"); // imprime o estado do Rele 2 no LCD
    sendMessage("Rele 2 ON"); // envia uma mensagem via WhatsApp para o número configurado
  } else {
    Serial.println("OFF"); // imprime o estado do Rele 2 no serial
    lcd.setCursor(9, 0); // posiciona o cursor na décima coluna da primeira linha
    lcd.print("OFF"); // imprime o estado do Rele 2 no LCD
    sendMessage("Rele 2 OFF"); // envia uma mensagem via WhatsApp para o número configurado
  }
}

void fourthLightChanged(uint8_t brightness) {
  Serial.print("Rele 3: "); // imprime o estado do Rele 3 no serial
  lcd.clear(); // limpa o LCD
  lcd.print("Rele 3: "); // imprime o nome do dispositivo na primeira linha do LCD

  //liga ou desliga o Rele 3 de acordo com o brilho recebido
  digitalWrite(pinLuz4, !brightness);

  //EXEMPLO
  if (brightness) {
    Serial.print("ON"); // imprime o estado do Rele 3 no serial
    lcd.setCursor(9, 0); // posiciona o cursor na décima coluna da primeira linha
    lcd.print("ON"); // imprime o estado do Rele 3 no LCD
    sendMessage("Rele 3 ON"); // envia uma mensagem via WhatsApp para o número configurado
  } else {
    Serial.println("OFF"); // imprime o estado do Rele 3 no serial
    lcd.setCursor(9, 0); // posiciona o cursor na décima coluna da primeira linha
    lcd.print("OFF"); // imprime o estado do Rele 3 no LCD
    sendMessage("Rele 3 OFF"); // envia uma mensagem via WhatsApp para o número configurado
  }
}

void fifthLightChanged(uint8_t brightness) {
  Serial.print("Rele 4: "); // imprime o estado do Rele 4 no serial
  lcd.clear(); // limpa o LCD
  lcd.print("Rele 4: "); // imprime o nome do dispositivo na primeira linha do LCD

  //liga ou desliga o Rele 4 de acordo com o brilho recebido
  digitalWrite(pinLuz5, !brightness);

  //EXEMPLO
  if (brightness) {
    Serial.print("ON"); // imprime o estado do Rele 4 no serial
    lcd.setCursor(9, 0); // posiciona o cursor na décima coluna da primeira linha
    lcd.print("ON"); // imprime o estado do Rele 4 no LCD
    sendMessage("Rele 4 ON"); // envia uma mensagem via WhatsApp para o número configurado
  } else {
    Serial.println("OFF"); // imprime o estado do Rele 4 no serial
    lcd.setCursor(9, 0); // posiciona o cursor na décima coluna da primeira linha
    lcd.print("OFF"); // imprime o estado do Rele 4 no LCD
    sendMessage("Rele 4 OFF"); // envia uma mensagem via WhatsApp para o número configurado
  }
}

// conectar ao wifi - retorna verdadeiro se bem-sucedido ou falso se não
boolean connectWifi() {
  boolean state = true; // variável para armazenar o estado da conexão
  int i = 0; // contador de tentativas

  WiFi.mode(WIFI_STA); // configura o modo de estação wifi
  WiFi.begin(ssid, password); // inicia a conexão com o ssid e a senha fornecidos
  Serial.println("");
  Serial.println("Connecting to WiFi"); // imprime a mensagem de conexão no serial
  lcd.clear(); // limpa o LCD
  lcd.print("Connecting WiFi"); // imprime a mensagem de conexão na primeira linha do LCD

  // Aguarda pela conexão
  Serial.print("Connecting..."); // imprime os pontos no serial
  lcd.setCursor(0, 1); // posiciona o cursor no início da segunda linha
  //lcd.print("Connecting"); // imprime a mensagem de conexão na segunda linha do LCD (comentado porque não é necessário)
  while (WiFi.status() != WL_CONNECTED) { // enquanto não estiver conectado
    delay(500); // espera meio segundo
    Serial.print("."); // imprime um ponto no serial
    lcd.print("."); // imprime um ponto no LCD

    if (i > 20) { // se exceder o limite de tentativas
      state = false; // muda o estado para falso
      break; // sai do loop
    }
    i++; // incrementa o contador
  }

  Serial.println("");
  
  if (state) { // se o estado for verdadeiro
    Serial.print("Connected to "); // imprime a mensagem de sucesso no serial
    Serial.println(ssid); // imprime o nome da rede no serial
    lcd.clear(); // limpa o LCD
    lcd.print("WiFi: "); // imprime o nome do dispositivo na primeira linha do LCD
    lcd.print(ssid); // imprime o nome da rede no LCD

    Serial.print("IP address: "); // imprime o endereço IP no serial
    Serial.println(WiFi.localIP()); // imprime o endereço IP no serial
    lcd.setCursor(0, 1); // posiciona o cursor no início da segunda linha
    lcd.print(WiFi.localIP()); // imprime o endereço IP no LCD

  } else { // se o estado for falso
    Serial.println("Connection failed."); // imprime a mensagem de falha no serial
    lcd.clear(); // limpa o LCD
    lcd.print("Connection failed"); // imprime a mensagem de falha na primeira linha do LCD
  }
  return state; // retorna o estado da conexão
}
