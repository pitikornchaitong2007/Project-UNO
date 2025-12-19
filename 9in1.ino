#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11

#define ledR 12
#define ledB 13
#define SW1 2 
#define SW2 3

#define potPin A0  
#define LDRPin A1
#define LM35Pin A2

DHT dht(DHTPIN, DHTTYPE);

// ===== Function Prototype =====
void ledBlynk(int time);
void SW();
void readDHT();
void pot();
void ldr();
void LM35();

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(ledB, OUTPUT);
  pinMode(ledR, OUTPUT);

  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
}

void loop() {
  int time = 1000;

  ledBlynk(time); // งาน1
  SW();           // งาน2
  readDHT();      // งาน3
  pot();          // งาน4
  ldr();          // งาน5
  LM35();         // งาน6

  Serial.println();
  delay(500);
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

// ===== SW =====
void SW(){
  int b1 = digitalRead(SW1);
  int b2 = digitalRead(SW2);

  if (b1 == LOW) {
    digitalWrite(ledB, HIGH);
    digitalWrite(ledR, LOW);
  }
  else if (b2 == LOW) {
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
  float c = dht.readTemperature();

  if (isnan(h) || isnan(c)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Hum: ");
  Serial.print(h, 2);
  Serial.print(" %\t");

  Serial.print("Tem: ");
  Serial.print(c, 2);
  Serial.println(" C");
}

// ===== Pot =====
void pot(){
  int adcValue = analogRead(potPin);
  float vdcValue = adcValue * (5.0 / 1023.0);

  Serial.print("ADCpot: ");
  Serial.print(adcValue);
  Serial.print("  VDCpot: ");
  Serial.println(vdcValue, 2);
}

// ===== LDR =====
void ldr(){
  int LDRadcValue = analogRead(LDRPin);
  float LDRvdcValue = LDRadcValue * (5.0 / 1023.0);

  Serial.print("ADCLDR: ");
  Serial.print(LDRadcValue);
  Serial.print("  VDCLDR: ");
  Serial.println(LDRvdcValue, 2);
}

// ===== LM35 =====
void LM35(){
  int adcTemp = analogRead(LM35Pin);
  float voltage = adcTemp * (5.0 / 1023.0);
  float tempC = voltage * 100.0;   // LM35 = 10mV / 1°C

  Serial.print("ADCLM35: ");
  Serial.print(adcTemp);

  Serial.print("  TempC: ");
  Serial.print(tempC, 1);
  Serial.println(" C");
}