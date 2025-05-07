# ESP32 Dragon Marauder

**A covert Pwnagotchi-style ESP32 cybertool** with Wi-Fi Deauth, Bluetooth scanning, radar-based human detection, real-time camera streaming, OLED emoji feedback, OTA firmware updates, and a web interface — all hidden behind a cute animated dragon face.

---

## Features

- Wi-Fi Deauthentication Attacks
- Bluetooth Sniffer & Tracker
- Real-time Human Detection (FMCW radar)
- OV7670 Camera Stream + Target Overlay
- Animated OLED Emoji Face
- Web UI with Separate Pages
- OTA Firmware Upload
- Audio Feedback (Toggleable)
- Test Mode (Simulated events)
- SPIFFS Web UI + Settings Storage

---

## Hardware

| Component              | Model                                |
|------------------------|--------------------------------------|
| Microcontroller        | ESP32-WROOM-32                       |
| Display                | 0.96" OLED (SSD1306, I2C)            |
| Camera Module          | OV7670 (w/o FIFO)                    |
| Radar Module           | FMCW Human Detection Radar (24GHz)   |
| Audio                  | Passive buzzer or piezo speaker      |
| Power Source           | Vape Pen Battery (~3.7V Li-Ion)      |

---

## Wiring Diagram

```plaintext
ESP32-WROOM-32    ->    Peripheral
----------------         ----------------------
3V3                ->    OLED VCC, Camera VCC, Radar VCC
GND                ->    OLED GND, Camera GND, Radar GND
GPIO 21 (I2C SDA)  ->    OLED SDA
GPIO 22 (I2C SCL)  ->    OLED SCL
GPIO 14            ->    Radar OUT (digital trigger)
GPIO 4             ->    OV7670 D7
GPIO 5             ->    OV7670 D6
...                ->    (Other OV7670 pins per software I2S mapping)
GPIO 27            ->    Passive buzzert
GPIO 12            ->    Camera clock (XCLK)

*** Coming Soon animated dragon faces interface, test mode and settings window.
***** Also I want to add a training interface and battle interface 
