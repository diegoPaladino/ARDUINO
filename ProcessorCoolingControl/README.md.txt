# ProcessorCoolingControl

## Introduction
ProcessorCoolingControl is an Arduino-based project designed to regulate the cooling of a computer processor. It activates a cooler when the processor's temperature exceeds a certain threshold.

## Materials Needed
- Arduino board (e.g., Arduino Uno)
- Relay module
- Temperature sensor (compatible with the processor)
- Liquid Crystal I2C LCD display
- Jumper wires

## Project Purpose
This project aims to provide an automated cooling solution for computer processors. It is particularly useful in scenarios where the processor is prone to overheating, such as during intensive computing tasks. The target audience includes tech enthusiasts, PC builders, and those interested in DIY computer maintenance and optimization.

## Pros and Cons
### Pros
- Automated cooling based on real-time temperature.
- Customizable temperature threshold.
- Real-time temperature display on an LCD.

### Cons
- Requires manual setup and calibration.
- Depends on the accuracy of the external temperature sensor.

## General Guidelines
### Setup and Installation
1. Connect the temperature sensor to the processor.
2. Attach the relay module to the Arduino.
3. Connect the LCD display via the I2C module.
4. Upload the provided Arduino sketch to the board.
5. Calibrate the temperature threshold as needed.

### Operation
The system reads the processor's temperature every 5000 milliseconds. If the temperature exceeds 80 degrees Celsius, it activates the cooler via the relay.

### Troubleshooting
Ensure all connections are secure and the temperature sensor is accurately placed. If the LCD does not display, check the I2C connection.

## License
This project is open-source and available for personal and educational use. Redistribution and modification are allowed with proper attribution.
