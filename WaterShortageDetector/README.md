# WaterShortageDetector

## Introduction
WaterShortageDetector is an Arduino-based system designed to detect the shortage of water from the public supply system. It provides a simple yet effective solution to monitor water availability and alert users in case of a shortage.

## List of Materials Needed
- Arduino board (e.g., Arduino Uno)
- Water level sensor (analog)
- LED
- Resistors (as needed)
- Breadboard and jumper wires
- USB cable for programming and power

## Purpose of the Project
The WaterShortageDetector project was created to help households and businesses monitor the availability of water supplied by public systems. By detecting water shortages early, users can take necessary actions to prevent inconvenience and manage their water usage more efficiently.

## Pros and Cons

### Pros
- Simple and cost-effective solution
- Easy to build and set up
- Provides real-time monitoring and alerts

### Cons
- Limited to detecting water levels only
- Requires periodic maintenance and calibration
- Dependent on the quality and accuracy of the water level sensor

## General Guidelines

### Setup Instructions
1. **Hardware Setup:**
   - Connect the water level sensor to the analog pin `A0` of the Arduino.
   - Connect the LED to the digital pin `13` of the Arduino through a suitable resistor.
   - Ensure all connections are secure on the breadboard.

2. **Software Setup:**
   - Install the Arduino IDE from [Arduino website](https://www.arduino.cc/en/software).
   - Copy the provided Arduino code into the IDE.
   - Connect the Arduino to your computer using a USB cable.
   - Select the appropriate board and port in the Arduino IDE.
   - Upload the code to the Arduino.

3. **Operation:**
   - Once the setup is complete, the system will start monitoring the water level.
   - The LED will light up and a message will be printed on the Serial Monitor when a water shortage is detected.
   - Ensure the Serial Monitor is set to a baud rate of `9600`.

### Troubleshooting
- Ensure all connections are correct and secure.
- Check the sensor and LED for proper functioning.
- Verify that the Arduino board is correctly recognized by the IDE.

## License
This project is licensed under the MIT License. You are free to use, modify, and distribute this project as per the terms of the license. For more details, refer to the LICENSE file.

---

**MIT License**

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
