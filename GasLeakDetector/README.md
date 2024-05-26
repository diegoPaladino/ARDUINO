# GasLeakDetector

## Introduction
The GasLeakDetector is a simple yet effective project designed to detect gas leaks using two gas sensors connected to an Arduino. This project aims to enhance the safety of smart houses by providing early warnings of potential gas leaks.

## Materials Needed
- 1 x Arduino Uno
- 2 x MQ-2 Gas Sensors
- 1 x LED
- 1 x Breadboard
- Jumper Wires

## Project Purpose
The purpose of the GasLeakDetector project is to monitor the levels of gas in the environment and alert the smart house system in case of a leak. It is designed for households that utilize smart technology to enhance safety and automation. This project can be beneficial to anyone who wants to ensure their home is safe from gas leaks.

## Pros and Cons
### Pros
- Simple to build and use
- Provides early detection of gas leaks
- Integrates with smart house systems
### Cons
- Requires calibration of gas sensors
- Limited to detecting gases that the sensors are sensitive to

## General Instructions
1. **Setup**: 
   - Connect the MQ-2 gas sensors to analog pins A0 and A1 on the Arduino.
   - Connect the LED to digital pin 13 with an appropriate current-limiting resistor.
   - Connect the ground and power pins appropriately.
2. **Upload Code**: 
   - Open the `GasLeakDetector.ino` file in the Arduino IDE.
   - Connect the Arduino to your computer.
   - Upload the code to the Arduino.
3. **Monitor**: 
   - Open the Serial Monitor in the Arduino IDE to view sensor readings.
   - The LED will turn on if a gas leak is detected.
4. **Integration**: 
   - Integrate the output with your smart house system for automated responses.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
