// clock.ino
void setup() {
Serial.begin(115200);
Wire.begin();
lcd.init();
lcd.backlight();


if (!rtc.begin()) {
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("No RTC found");
while (1) {
// halt
}
}


if (rtc.lostPower()) {
Serial.println("RTC lost power, set time by sending: YYYY MM DD hh mm ss");
lcd.setCursor(0,0);
lcd.print("RTC lost power");
} else {
lcd.setCursor(0,0);
lcd.print("Arduino Clock");
}
}


void loop() {
DateTime now = rtc.now();


char line1[17];
char line2[17];


snprintf(line1, sizeof(line1), "%02d:%02d:%02d", now.hour(), now.minute(), now.second());
snprintf(line2, sizeof(line2), "%04d-%02d-%02d", now.year(), now.month(), now.day());


lcd.setCursor(0,0);
lcd.print(" ");
lcd.setCursor(0,0);
lcd.print(line1);


lcd.setCursor(0,1);
lcd.print(" ");
lcd.setCursor(0,1);
lcd.print(line2);


delay(250);


if (Serial.available()) {
String in = Serial.readStringUntil('\n');
in.trim();
if (in.length() > 0) {
int Y, M, D, h, m, s;
if (sscanf(in.c_str(), "%d %d %d %d %d %d", &Y, &M, &D, &h, &m, &s) == 6) {
rtc.adjust(DateTime(Y, M, D, h, m, s));
Serial.println("RTC updated.");
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Time updated");
delay(1000);
} else {
Serial.println("Bad format. Use: YYYY MM DD hh mm ss");
}
}
}
}
