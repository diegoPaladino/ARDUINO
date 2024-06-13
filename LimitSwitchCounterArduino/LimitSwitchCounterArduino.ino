#include <EEPROM.h>

const int limitSwitchPin = 2;  // Pin connected to limit switch
volatile int counter = 0;

void setup() {
  Serial.begin(9600);
  pinMode(limitSwitchPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(limitSwitchPin), countLimitSwitch, FALLING);

  // Load counter value from EEPROM
  counter = EEPROM.read(0);
}

void loop() {
  // Print the counter value every second
  Serial.print("Limit switch activated ");
  Serial.print(counter);
  Serial.println(" times");
  delay(1000);
}

void countLimitSwitch() {
  counter++;
  // Save counter value to EEPROM
  EEPROM.write(0, counter);
}
