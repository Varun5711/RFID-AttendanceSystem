# 🎓 RFID Attendance System with LCD & Buzzer Feedback 📡

![Project Thumbnail](https://via.placeholder.com/800x400.png?text=RFID+Attendance+System+Project) *Add your project image here*

A smart attendance tracking system using RFID technology with visual (LCD) and audible (buzzer) feedback. Perfect for classrooms, offices, and events!

## 🚀 Features
- ✅ RFID-based user identification
- 🖥 16x2 I2C LCD display for user feedback
- 🔊 Audio confirmation with buzzer
- 📊 Automatic CSV logging to serial monitor
- 🔁 Toggle between IN/OUT status
- 💡 Simple single-user configuration (easily expandable)

## 📦 Hardware Components
| Component | Quantity | Link |
|-----------|----------|------|
| Arduino Uno | 1 | [Arduino Store](https://store.arduino.cc/) |
| RC522 RFID Reader | 1 | [RC522 Module](https://amzn.to/3xyz123) |
| I2C 16x2 LCD | 1 | [I2C LCD](https://amzn.to/3abc456) |
| Passive Buzzer | 1 | [Buzzer](https://amzn.to/3def789) |
| Jumper Wires | 15+ | [Jumper Pack](https://amzn.to/3ghi789) |
| Breadboard | 1 | [Breadboard](https://amzn.to/3jkl012) |

## 🔧 Installation
### Hardware Setup
![Circuit Diagram](https://via.placeholder.com/800x400.png?text=Circuit+Diagram) *Add your circuit diagram here*

1. Connect RFID Reader:
   - SDA → Pin 10
   - SCK → Pin 13
   - MOSI → Pin 11
   - MISO → Pin 12
   - RST → Pin 9
   - 3.3V → 3.3V
   - GND → GND

2. Connect I2C LCD:
   - SDA → A4
   - SCL → A5
   - VCC → 5V
   - GND → GND

3. Connect Buzzer:
   - Positive (+) → Pin 8
   - Negative (-) → GND

### Software Setup
1. Install required libraries:
   ```bash
   Arduino Library Manager > Install:
   - MFRC522 by Miguel Balboa
   - LiquidCrystal_I2C by Frank de Brabander

## ⚙️ Configuration
1. Find your RFID Tag UID:
   ```arduino
   void loop() {
     if (!mfrc522.PICC_IsNewCardPresent()) return;
     if (!mfrc522.PICC_ReadCardSerial()) return;
     
     Serial.print("UID: ");
     for (byte i = 0; i < mfrc522.uid.size; i++) {
       Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
       Serial.print(mfrc522.uid.uidByte[i], HEX);
     }
     Serial.println();
   }
   ```

2. Update the UID in code:
   ```arduino
   String varunUID = "7B37F21A"; // Replace with your UID
   ```

## 🎮 Usage
1. Power up the system
2. Scan RFID tag:
   - ✅ Valid tag: Welcome message + buzzer beep
   - ❌ Invalid tag: No response
3. View attendance records in Serial Monitor:
   ```
   DATE       TIME     NAME    DEPARTMENT  STATUS
   2023-08-20 14:30:00 Varun   CSE         IN
   2023-08-20 17:45:00 Varun   CSE         OUT
   ```

## 🚨 Troubleshooting
| Issue | Solution |
|-------|----------|
| LCD not displaying | Check I2C address with I2C scanner |
| RFID not detecting | Ensure 3.3V power supply |
| Buzzer not sounding | Check polarity connection |
| Serial data missing | Verify baud rate (9600) |

## 🌟 Extending the Project
- Add multiple user support
- Implement EEPROM data storage
- Add LED status indicators
- Integrate real-time clock (RTC)
- Create web interface using ESP8266

## 🤝 Contributing
Contributions welcome! Please follow our [contribution guidelines](CONTRIBUTING.md).

## 📄 License
Apache 2.0 License - See [LICENSE](LICENSE) for details.

---

**Made with ❤️ by [Varun Hotani]**  
*Need help?* ✉️ [varunhotani@icloud.com]
