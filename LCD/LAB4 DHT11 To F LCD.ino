#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// ===== LCD (I2C ADDRESS 0x27) =====
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ===== DHT11 =====
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// ===== IO =====
#define ledR 12
#define ledB 13
#define SW1 2
#define SW2 3

#define potPin A0
#define LDRPin A1
#define LM35Pin A2

// ===== Function Prototype =====
void ledBlynk(int time);
void SW();
void readDHT();
void pot();
void ldr();
void LM35();

void setup() {
  Serial.begin(9600);

  // ===== LCD INIT =====
  Wire.begin();                 // << สำคัญ อย่าแกล้งลืม
  lcd.begin(16, 2);             // สำหรับ library ตัวนี้
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("I2C LCD 0x27");
  lcd.setCursor(0, 1);
  lcd.print("System Ready");
  Serial.println("LCD Ready @0x27");
  delay(2000);
  lcd.clear();

  // ===== DHT =====
  dht.begin();

  // ===== IO =====
  pinMode(ledB, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
}

void loop() {
  int time = 500;

  ledBlynk(time);
  SW();
  readDHT();
  pot();
  ldr();
  LM35();

  Serial.println("--------------------");
  delay(2000);
}

// ===== LED Blink =====
void ledBlynk(int time){
  digitalWrite(ledB, HIGH);
  digitalWrite(ledR, HIGH);
  delay(time);
  digitalWrite(ledB, LOW);
  digitalWrite(ledR, LOW);
  delay(time);
}

// ===== Switch =====
void SW(){
  if (digitalRead(SW1) == LOW) {
    digitalWrite(ledB, HIGH);
    digitalWrite(ledR, LOW);
  }
  else if (digitalRead(SW2) == LOW) {
    digitalWrite(ledB, LOW);
    digitalWrite(ledR, HIGH);
  }
  else {
    digitalWrite(ledB, LOW);
    digitalWrite(ledR, LOW);
  }
}

// ===== DHT11 =====
void readDHT(){
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("DHT ERROR");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("DHT ERROR");
    return;
  }

  // ===== Serial =====
  Serial.print("Temp: ");
  Serial.print(t, 1);
  Serial.print(" C  ");
  Serial.print("Hum: ");
  Serial.print(h, 0);
  Serial.println(" %");

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
  lcd.print("%");
}

// ===== Pot =====
void pot(){
  int adc = analogRead(potPin);
  float vdc = adc * (5.0 / 1023.0);

  Serial.print("POT ADC: ");
  Serial.print(adc);
  Serial.print(" V: ");
  Serial.println(vdc, 2);
}

// ===== LDR =====
void ldr(){
  int adc = analogRead(LDRPin);
  float vdc = adc * (5.0 / 1023.0);

  Serial.print("LDR ADC: ");
  Serial.print(adc);
  Serial.print(" V: ");
  Serial.println(vdc, 2);
}

// ===== LM35 =====
void LM35(){
  int adc = analogRead(LM35Pin);
  float tempC = (adc * 5.0 / 1023.0) * 100.0;

  Serial.print("LM35 ADC: ");
  Serial.print(adc);
  Serial.print(" Temp: ");
  Serial.print(tempC, 1);
  Serial.println(" C");
}
