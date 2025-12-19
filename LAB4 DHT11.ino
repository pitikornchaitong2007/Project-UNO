#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// ===== LCD =====
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ===== DHT11 =====
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.backlight();

  dht.begin();

  lcd.setCursor(0, 0);
  lcd.print("LAB3 DHT11 LCD");
  lcd.setCursor(0, 1);
  lcd.print("Starting...");
  Serial.println("System Starting...");
  delay(2000);
  lcd.clear();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // Celsius

  if (isnan(h) || isnan(t)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("DHT Error");

    Serial.println("Failed to read from DHT sensor!");
    delay(1000);
    return;
  }

  // ===== LCD =====
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t, 1);
  lcd.print((char)223);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Hum : ");
  lcd.print(h, 0);
  lcd.print(" %");

  // ===== Serial =====
  Serial.print("Temperature: ");
  Serial.print(t, 1);
  Serial.print(" C\t");

  Serial.print("Humidity: ");
  Serial.print(h, 0);
  Serial.println(" %");

  delay(2000);
}
