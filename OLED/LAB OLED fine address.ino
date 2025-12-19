// LAB 
// 
#include "Wire.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SH1106.h"

#define OLED_RESET -1                       // ไม่มีสาย reset ต่อกับ MCU กำหนดให้ reset pin เป็น “ไม่มีขา”
Adafruit_SH1106 display(OLED_RESET);
 
void setup() {
    display.begin(SH1106_SWITCHCAPVCC, 0x3C); // โหมดจ่ายไฟให้กับจอ (ใช้ internal charge pump) 0x3C → คือ I2C address ของจอ
   
    display.clearDisplay();     //ลบข้อมูลทั้งหมดใน buffer ของจอ (เคลียร์หน้าจอเป็นสีดำ/ว่าง)  ยังไม่แสดงจริงจนกว่าจะสั่ง display.display();

    display.setTextColor(WHITE);            //กำหนดสีของตัวอักษรให้เป็น WHITE (สีขาว)

    display.setTextSize(1);
    display.setCursor(0, 5);                //(0,0) คือมุมซ้ายบนของจอ
    display.println(" WELCOME to Teccom");

    display.println();

    display.setTextSize(2);
    display.println(" LAB1 OLED");

    display.setTextSize(2);
    display.println("");

    display.setTextSize(1);
    display.println("...OLED 1.3 TESTER...");
    display.display();
}
 
void loop() {
}
