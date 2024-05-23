# SmartGardenIrrigationSystem

## Introduction
The SmartGardenIrrigationSystem is an automated irrigation solution designed for small house gardens. This project aims to simplify the process of garden maintenance by automatically watering the garden based on soil moisture levels.

## Bill of Materials
- Arduino Uno
- DHT11 Temperature and Humidity Sensor
- Soil Moisture Sensor
- Relay Module
- Water Pump
- Jumper Wires
- Breadboard
- Power Supply

## Project Purpose
The purpose of this project is to create a cost-effective, easy-to-implement automated irrigation system for home gardeners. The system monitors soil moisture levels and activates the water pump as needed to ensure optimal soil moisture, contributing to healthier plants and efficient water usage.

## Pros and Cons
### Pros
- Automated irrigation reduces manual effort
- Ensures consistent soil moisture levels
- Cost-effective solution using readily available components
### Cons
- Requires basic knowledge of Arduino and electronics
- Limited to small gardens
- Sensor accuracy may vary with environmental conditions

## General Guidelines
### Setup Instructions
1. Connect the DHT11 sensor to the Arduino as follows:
   - VCC to 5V
   - GND to GND
   - Data to pin 2
2. Connect the soil moisture sensor to the Arduino:
   - VCC to 5V
   - GND to GND
   - Analog output to A0
3. Connect the relay module to the Arduino:
   - VCC to 5V
   - GND to GND
   - Signal to pin 3
4. Connect the water pump to the relay module.
5. Upload the provided Arduino code to the Arduino Uno.
6. Power the Arduino and ensure the system is operational.

### Usage Instructions
1. Ensure all connections are secure.
2. Power on the Arduino and observe the serial monitor for sensor readings.
3. The system will automatically activate the pump when soil moisture levels fall below the threshold.

### Troubleshooting
- Ensure all sensor connections are correct.
- Verify the power supply to the pump and relay module.
- Check the serial monitor for any error messages.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
