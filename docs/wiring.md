# Wiring — DS3231 + 16x2 I2C LCD to Arduino (Uno/Nano)


All devices use I²C (shared SDA/SCL)


- DS3231 VCC -> 5V
- DS3231 GND -> GND
- DS3231 SDA -> A4
- DS3231 SCL -> A5


- I2C LCD VCC -> 5V
- I2C LCD GND -> GND
- I2C LCD SDA -> A4
- I2C LCD SCL -> A5


If using Mega: SDA -> 20, SCL -> 21
If using Leonardo: use SDA/SCL pins near AREF


Tip: If the LCD is blank, run an I2C scanner sketch to find the address (likely 0x27 or 0x3F).
