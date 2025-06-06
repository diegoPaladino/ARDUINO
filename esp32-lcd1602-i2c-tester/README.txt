# ESP32 LCD1602 I2C Tester 📟

Test code to verify the functionality of a 16x2 LCD (1602) via I2C on an ESP32 board.

## 🔧 Hardware
- ESP32 (tested on 30-pin variant)
- LCD 16x2 with I2C backpack (PCF8574)
- Pull-up resistors (optional)

## 📌 Features
- Scans I2C address (0x27, 0x3F, etc.)
- Displays test message on both rows
- Compatible with ESP32 default I2C pins (GPIO 21 = SDA, GPIO 22 = SCL)

## 🔄 I2C Address Troubleshooting
Use I2C scanner sketch if LCD does not respond.

## 🚀 Getting Started
1. Connect LCD to ESP32:
   - VCC → 3.3V
   - GND → GND
   - SDA → GPIO 21
   - SCL → GPIO 22
2. Upload `lcd_tester.ino` using Arduino IDE
3. LCD should show:
Teste LCD
Linha 2 OK!

## ✅ Dependencies
- LiquidCrystal_I2C (ESP32-compatible fork)

## 🧪 Useful I2C Addresses
Common:
- 0x27
- 0x3F

---

MIT License • 2025
