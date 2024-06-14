# LightBeamCounter

## Introduction
The LightBeamCounter is a project designed to count the number of times a light beam is interrupted. It uses the KY-008 laser module and an LED as the receiver. Each interruption of the beam increments a counter, which is stored in the EEPROM of an Arduino Nano, ensuring data persistence even after power loss.

## List of Necessary Materials
- Arduino Nano
- KY-008 Laser Module
- LED
- Resistor (appropriate value for LED)
- Breadboard and jumper wires
- USB cable for Arduino Nano

## Project Purpose
The purpose of this project is to create a reliable system to count the number of interruptions of a light beam. This can be used for various applications such as people counters, object detection systems, and more. The counter value is stored in the EEPROM of the Arduino Nano to ensure that the count persists even if the system is powered off.

## Pros and Cons
### Pros
- Simple and cost-effective
- Persistent count storage using EEPROM
- Easily customizable for various applications

### Cons
- Limited EEPROM write cycles
- Requires precise alignment of laser and LED

## General Guidelines
### Setup and Installation
1. Connect the KY-008 laser module to the Arduino Nano's pin 8.
2. Connect the LED and a suitable resistor to pin 2 of the Arduino Nano.
3. Power the Arduino Nano via USB and upload the provided code.
4. Ensure the laser and LED are aligned so that the LED can detect the laser beam.

### Operation
1. Once powered on, the laser will emit a beam towards the LED.
2. Each interruption of the beam will increment the count, which will be displayed via the Serial Monitor.
3. The count is stored in EEPROM, so it will be retained even if the Arduino is powered off.

### Troubleshooting
- Ensure proper alignment of the laser and LED.
- Verify the connections and ensure the LED and resistor are connected correctly.
- Use the Serial Monitor for debugging and to view the current count.

## License
This project is open-source and free to use. Feel free to modify and distribute it as needed.
