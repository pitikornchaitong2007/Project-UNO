#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// ประกาศ lcd
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();        // เริ่มต้นจอ
  lcd.backlight();   // เปิดไฟพื้นหลัง

  // แสดง Hello World
  lcd.setCursor(0, 0);
  lcd.print("Hello World");
  lcd.setCursor(0, 1);
  lcd.print("LCD 16x2");

  delay(2000);       // แสดง 2 วินาที
  lcd.clear();
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Running...   ");

  static int count = 0;
  lcd.setCursor(0, 1);
  lcd.print("Count: ");
  lcd.print(count++);
  lcd.print("   ");

  delay(1000);
}
