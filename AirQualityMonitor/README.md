# AirQualityMonitor

## Introduction
The AirQualityMonitor project aims to provide a comprehensive solution for monitoring air quality using an Arduino and various sensors. This project measures CO2 levels, Total Volatile Organic Compounds (TVOCs), temperature, humidity, and pressure, giving a detailed overview of the air quality in the environment.

## Materials Needed
- Arduino Uno or any compatible board
- Adafruit BME280 sensor
- Adafruit CCS811 sensor
- Jumper wires
- Breadboard
- USB cable for Arduino

## Project Purpose
The purpose of this project is to create an easy-to-implement air quality monitoring system that can be used in homes, offices, and other indoor environments. By tracking air quality metrics, users can ensure a healthier living and working space. This project benefits:
- Homeowners looking to monitor indoor air quality.
- Office managers ensuring a safe working environment.
- Schools and educational institutions teaching environmental science.

## Pros and Cons

### Pros
- Comprehensive monitoring of various air quality parameters.
- Easy to set up and use with readily available components.
- Provides real-time data on air quality.

### Cons
- Requires calibration for accurate readings.
- Limited to indoor use unless properly enclosed.
- Dependent on the accuracy of sensors.

## General Instructions
1. **Setup**: Connect the BME280 and CCS811 sensors to the Arduino using jumper wires according to their respective pinouts.
2. **Library Installation**: Ensure you have the Adafruit BME280 and Adafruit CCS811 libraries installed in your Arduino IDE.
3. **Upload Code**: Upload the provided Arduino code to your board.
4. **Run the Project**: Open the Serial Monitor to view the air quality data being printed every 2 seconds.

### Installation and Use
1. Connect the sensors as follows:
    - BME280: VCC to 3.3V, GND to GND, SCL to A5, SDA to A4
    - CCS811: VCC to 3.3V, GND to GND, SCL to A5, SDA to A4
2. Open the Arduino IDE, load the provided code, and upload it to the Arduino board.
3. Open the Serial Monitor at a baud rate of 9600 to view the readings.

### Troubleshooting
- If the sensors are not detected, check the wiring and ensure the correct libraries are installed.
- If readings are inconsistent, allow the sensors some time to stabilize.

## License
This project is licensed under the MIT License. You are free to use, modify, and distribute this project as per the terms of the license.
