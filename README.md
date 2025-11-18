# 💡 LDR-Based-Automatic-Darkness-Detection-Circuit-Simple-DIY
## 📄 Description
This project uses an LDR (Light Dependent Resistor) and a microcontroller STM32 to create an automatic light-control system. The LDR allows the microcontroller to measure ambient brightness. When the detected light level falls below a defined threshold, the microcontroller activates a relay to switch on a lamp. When sufficient light returns, the relay is turned off, switching the lamp off as well. The setup is ideal for learning about ADC reading, relay control, and basic automation.
The project is configured with **STM32CubeMX** and programmed using **low-level (LL) drivers** to read light intensity and automatically switch a lamp ON or OFF based on ambient brightness.

## ⚙️ Tools and Technologies

#### 1. Hardware components
- **Microcontroller**: STM32
- **Sensor**: Light sensor/ Photoresistor
- **Display**: I²C LCD 16x2
- **Programming**: STM32CubeMX/ LL drivers
- **Demo**: Simple demonstration video showcasing..

  ![Demo1](Demo_1_image.png)

#### 1.2 Hardware connections
- **DHT11** : 
  - VCC → 5V
  - DATA → Pin 7
  - GND → GND
- **BMP180** : 
  - VCC → 3.3V
  - SDA → A4 
  - SCL → A5
  - GND → GND
- **LED RGB (Common cathode)** : 
  - R → Pin 11
  - G → Pin 10
  - B → Pin 9
  - C → GND
- **LDR** : 
  - LDR + resistor in a voltage divider → common output connected to A0
  - One leg of the LDR → 5V
  - The other leg of the LDR → A0 + resistor (≈10kΩ) to GND

---
## 📖 Guide to Use
1. Clone this repository:
git clone https://github.com/Ghouilaanas/LDR-Based-Automatic-Darkness-Detection-Circuit-Simple-DIY.git
2. 📂 **Open the STM32CubeIDE project** corresponding to the desired traffic flow detection approach.
3. 🛠️ **Build and flash the firmware** for that approach onto the appropriate STM32 board.
4. 🔌 **Connect the sensors, microcontroller, and display** following the wiring diagram for the selected setup.
5. ⚡ **Power on the system** and **observe the real-time traffic flow readings** on the LCD.
