#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SS_PIN 10
#define RST_PIN 9
#define BUZZER_PIN 8

MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);

String varunUID = "7B37F21A";
bool isIn = false;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  pinMode(BUZZER_PIN, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Scan your card");
  Serial.println("CLEARSHEET");
  Serial.println("LABEL,Date,Time,Name,Department,Status");
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;

  String scannedUID = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    byte b = mfrc522.uid.uidByte[i];
    if (b < 0x10) scannedUID += "0";
    scannedUID += String(b, HEX);
  }
  scannedUID.toUpperCase();
  mfrc522.PICC_HaltA();

  if (scannedUID == varunUID) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(200);
    digitalWrite(BUZZER_PIN, LOW);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Welcome Varun");

    if (!isIn) {
      lcd.setCursor(0, 1);
      lcd.print("Entered");
      Serial.println("DATA,DATE,TIME,Varun,CSE,IN");
      isIn = true;
    } else {
      lcd.setCursor(0, 1);
      lcd.print("Exited");
      Serial.println("DATA,DATE,TIME,Varun,CSE,OUT");
      isIn = false;
    }

    delay(2000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Scan your card");
  }
}
