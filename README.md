# Clock Using Arduino Uno / Nano

This repository contains a complete and well-documented digital clock built using an Arduino Uno or Arduino Nano, a DS3231 high-accuracy real-time clock (RTC) module, and a 16×2 I2C LCD display. The project is designed to be simple, reliable, beginner-friendly, and fully open-source. All wiring diagrams, firmware, explanations, troubleshooting steps, and repository structure are included.

---

## 🌟 Overview

This project demonstrates how to build a standalone hardware clock that keeps accurate time using the DS3231 RTC chip and displays it on a 16×2 LCD module via I²C.  
The DS3231 is extremely accurate due to its built-in temperature-compensated crystal oscillator (TCXO), meaning your clock will maintain proper time with almost no drift.

The Arduino only updates the display and communicates with the RTC. Even if the Arduino loses power, the DS3231 continues keeping accurate time thanks to its CR2032 backup battery.

---

## 🧰 Hardware Requirements

You will need:

- **Arduino Uno or Arduino Nano** (both are fully supported)  
- **DS3231 RTC Module** (with CR2032 battery installed)  
- **16×2 I2C LCD Display** (PCF8574 I2C backpack)  
- Jumper wires  
- Breadboard (optional)  
- USB cable for uploading the program  

This project uses **I2C communication** to keep wiring extremely simple.

---

## 🔌 Wiring Diagram (Summary)

The full wiring guide is available in `docs/wiring.md`, but here is the quick version:

| Component        | VCC | GND | SDA | SCL |
|------------------|-----|------|------|------|
| DS3231 RTC       | 5V  | GND  | A4   | A5   |
| I2C 16x2 LCD     | 5V  | GND  | A4   | A5   |

Notes:
- On Arduino Uno/Nano: **A4 = SDA**, **A5 = SCL**
- On Arduino Mega: **SDA = 20**, **SCL = 21**
- If your LCD doesn’t display anything, adjust the contrast knob on the back.

---

## 📂 Repository Structure

