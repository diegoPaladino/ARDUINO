# LgAcRemoteIrCopier

## Introduction

LgAcRemoteIrCopier is an Arduino project designed to copy the power on/off IR signal from an LG air conditioner remote control and retransmit it. This project allows you to control your LG AC unit using an Arduino.

## Materials Needed

- Arduino (e.g., Arduino Uno)
- IR Receiver (e.g., TSOP1738)
- IR LED (Emissor IR)
- Protoboard and Jumper Wires
- Resistors (220Ω, if needed)
- LG Air Conditioner Remote Control

## Project Purpose

The purpose of this project is to capture the IR signal used by an LG air conditioner remote control to turn the unit on and off. This captured signal can then be retransmitted by the Arduino, effectively allowing you to control the AC unit with your Arduino.

## Pros and Cons

### Pros
- Simple setup and execution
- Cost-effective solution for remote control duplication
- Open-source and customizable

### Cons
- Limited to LG air conditioner remote controls
- Requires basic knowledge of Arduino and IR communication
- Limited range of the IR transmitter

## General Instructions

### Setup

1. **Hardware Connections:**
   - Connect the VCC of the IR receiver to the 5V pin on the Arduino.
   - Connect the GND of the IR receiver to the GND pin on the Arduino.
   - Connect the OUT pin of the IR receiver to pin 11 on the Arduino.
   - Connect the anode (long leg) of the IR LED to pin 3 on the Arduino through a 220Ω resistor.
   - Connect the cathode (short leg) of the IR LED to the GND pin on the Arduino.

2. **Install Libraries:**
   - In the Arduino IDE, go to Sketch > Include Library > Manage Libraries.
   - Search for "IRremote" and install the library by `shirriff`.

### Code

1. **Upload the Code:**
   - Upload the provided code to your Arduino.
   
2. **Capture the IR Signal:**
   - Open the Serial Monitor in the Arduino IDE.
   - Point the LG remote control at the IR receiver and press the power button.
   - The captured IR code will be displayed in the Serial Monitor.

3. **Transmit the IR Signal:**
   - The Arduino will automatically retransmit the captured IR signal every 5 seconds.

## License

This project is licensed under the MIT License. You are free to use, modify, and distribute this project as long as you include the original license in any distributed versions.
