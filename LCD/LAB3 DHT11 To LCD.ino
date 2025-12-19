#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD I2C
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ขา LM35
const int tempPin = A0;

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("LCD TEST OK");
  lcd.setCursor(0, 1);
  lcd.print("Temp System");

  delay(2000);
  lcd.clear();
}

void loop() {
  // อ่านค่าอุณหภูมิ
  int sensorValue = analogRead(tempPin);
  float voltage = sensorValue * (5.0 / 1023.0);
  float temperature = voltage * 100.0; // LM35 = 10mV/°C

  static int count = 0;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature, 1);
  lcd.print((char)223); // สัญลักษณ์ °
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Count: ");
  lcd.print(count++);

  delay(1000);
}
