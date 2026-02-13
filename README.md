# 💡 LDR-Based-Automatic-Darkness-Detection-Circuit-Simple-DIY
An automatic light-control system that uses a darkness-activated sensor built with an LDR and a microcontroller. When the ambient light level drops below a set threshold, the circuit turns on a lamp through a relay, and automatically switches it off again when the environment becomes bright.
## 📄 Description
This project implements an automatic darkness-detection system using an LDR and an STM32 microcontroller. The firmware is written using STM32CubeIDE without using HAL or STM32CubeMX graphical configuration.The digital LDR sensor provides a HIGH or LOW signal depending on the ambient light intensity. This signal is read through a GPIO input pin,, allowing the MCU to detect light or darkness conditions. When the light intensity falls below a defined threshold, the microcontroller activates a relay to turn ON a lamp; when brightness increases, it turns the lamp OFF. This setup demonstrates basic automation, and low-level embedded development on STM32. 
## ⚙️ Tools and Technologies

#### 1. Hardware components
- **Microcontroller**: STM32 Nucleo-L476RG
- **Sensor**: Digital LDR Light Sensor Module
- **Display**: I²C LCD 16x2
- **Programming**: Bare-Metal (Raw Registers) & CMSIS Register Access
- **Demo**: Simple demonstration video showcasing how the system automatically turns the lamp ON in darkness and OFF when light is detected.

  ![Demo](Demo_image.png)
  
   [▶️ Download Demo](Demo.mp4)

#### 1.2 Hardware connections
- **Relay Module** : 
  - VCC → 5V
  - IN → PC6 (Pin configured as GPIO_Output)
  - GND → GND
- **LDR** : 
  - LDR D0 → PC7 (Pin configured as GPIO_Input)
  - One leg of the LDR → 5V
  - The other leg of the LDR → GND

---
## 📖 Guide to Use
1. Clone this repository:
git clone https://github.com/Ghouilaanas/LDR-Based-Automatic-Darkness-Detection-Circuit-Simple-DIY.git
2. 📂 **Open the STM32CubeIDE project** included in the repository to view the STM32CubeMX configuration and the low-level (LL) ADC/relay control code.
3. 🛠️ **Build and flash the firmware** to your STM32 board using STM32CubeIDE.
4. 🔌 **Assemble the hardware setup** by connecting the LDR voltage divider, relay module, and lamp to the STM32 according to the wiring diagram.
5. ⚡ **Power on the system** and **observe** how the system automatically turns the lamp ON in darkness and OFF when light is detected.
