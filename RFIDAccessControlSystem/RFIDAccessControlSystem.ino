#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
#define ACCESS_GRANTED_PIN 7
#define ACCESS_DENIED_PIN 6

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  pinMode(ACCESS_GRANTED_PIN, OUTPUT);
  pinMode(ACCESS_DENIED_PIN, OUTPUT);
  Serial.println("Aproxime o cartão RFID ao leitor...");
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  Serial.print("UID do cartão: ");
  String cardUID = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    cardUID += String(mfrc522.uid.uidByte[i], HEX);
  }
  Serial.println(cardUID);

  if (isAuthorized(cardUID)) {
    grantAccess();
  } else {
    denyAccess();
  }

  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();
}

bool isAuthorized(String uid) {
  String authorizedUIDs[] = {"a1b2c3d4", "e5f6g7h8"};
  for (String authorizedUID : authorizedUIDs) {
    if (uid.equalsIgnoreCase(authorizedUID)) {
      return true;
    }
  }
  return false;
}

void grantAccess() {
  Serial.println("Acesso concedido!");
  digitalWrite(ACCESS_GRANTED_PIN, HIGH);
  delay(2000);
  digitalWrite(ACCESS_GRANTED_PIN, LOW);
}

void denyAccess() {
  Serial.println("Acesso negado!");
  digitalWrite(ACCESS_DENIED_PIN, HIGH);
  delay(2000);
  digitalWrite(ACCESS_DENIED_PIN, LOW);
}