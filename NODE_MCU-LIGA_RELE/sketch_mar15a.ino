#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


 
 
char auth[] = "QhfjHNjjvi9OamDPQ1I3yBPD7_eKlb3p"; // Token recebido no email ao criar o dashboard no blynk
 
char ssid[] = "VIVO-A050"; // Nome da sua rede WiFi
char pass[] = "9KCVRJ3M4a"; // senha da sua rede WiFi
 
 
void setup() {

  //LED - indicando estar funcionando
  pinMode(2, OUTPUT);
  
  Blynk.begin(auth, ssid, pass); // Inicia conexão com a rede e ativa dashboard
  pinMode (D1,OUTPUT);
  digitalWrite(D1,LOW);

}
void loop() {
   Blynk.run();

   //Loop de funcionamento da LED
     digitalWrite(2, HIGH);
  delay(50);
  digitalWrite(2, LOW);
  delay(200);
}
