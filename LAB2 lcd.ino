#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// ประกาศ lcd ไว้ตรงนี้ ต้องอยู่นอก setup/loop
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();        // เริ่มต้นจอ
  lcd.backlight();   // เปิดไฟพื้นหลัง

  lcd.setCursor(0, 0);
  lcd.print("LCD TEST OK");

  lcd.setCursor(0, 1);
  lcd.print("I2C 16x2");
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Running...");

  static int count = 0;
  lcd.setCursor(0, 1);
  lcd.print("Count: ");
  lcd.print(count++);

  delay(1000);
}
