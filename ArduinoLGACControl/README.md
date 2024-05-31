# ArduinoLGACControl

## Introduction
This project aims to control an LG air conditioner using an Arduino. The system will turn on the AC when the ambient temperature reaches 30°C and turn it off when the temperature drops to 24°C.

## Materials Needed
- Arduino (any model)
- DHT11 Temperature and Humidity Sensor
- IR LED
- Resistor (220 ohms for IR LED)
- Jumper wires
- Breadboard

## Project Purpose
This project was created to provide a simple and modern temperature control system for an LG air conditioner. It is intended for users who want to automate their AC to maintain a specific temperature range without manual intervention.

## Pros and Cons

### Pros
- Automates temperature control for comfort.
- Simple to set up and use.
- Cost-effective solution using readily available components.

### Cons
- Limited to specific IR codes for LG AC models.
- Requires precise positioning of the IR LED towards the AC unit.

## General Guidelines

### Setup Instructions
1. Connect the DHT11 sensor to the Arduino:
   - VCC to 5V
   - GND to GND
   - Data pin to digital pin 2

2. Connect the IR LED to the Arduino:
   - Anode (longer leg) to digital pin 3 with a 220-ohm resistor
   - Cathode (shorter leg) to GND

3. Install the required libraries in the Arduino IDE:
   - IRremote by shirriff
   - DHT sensor library by Adafruit

4. Upload the provided code to your Arduino.

### Usage Instructions
- Place the setup in a position where the IR LED can directly face the AC unit.
- Power on the Arduino.
- The system will automatically monitor the temperature and send the appropriate IR signals to turn the AC on or off based on the defined temperature thresholds.

### Troubleshooting
- Ensure the DHT11 sensor is properly connected and the data pin is correct.
- Verify the IR LED is functioning and facing the AC unit.
- Check the IR codes for your specific LG AC model and update the code if necessary.

## License
This project is free and open-source. Feel free to use, modify, and distribute it as needed.
