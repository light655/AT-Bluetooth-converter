# AT-Bluetooth-converter

This project uses a ESP32 micro-controller to convert AT keyboard protocol to bluetooth, planned to added support for other protocols (if I actually get those keyboards on hand). The [ESP32-BLE-Keyboard](https://github.com/T-vK/ESP32-BLE-Keyboard) library is used in this project.

This project is still under development, and still lacks some features: 
1. Due to Library restrictions, NumLock, CapsLock, and ScrollLock states cannot be sent from the computer to the converter. As a result, the lock lights will not work, but the keys will work as intented.
2. The print screen key cannot be pressed with other keys such as control, shift, etc.

Implementation example:
1. There are four wires in a typical AT keyboard: 5V, GND, DATA, CLK. In the script, CLK and DATA are connected to pins 22 and 23 repectively by default. You can choose other available pins on the ESP32, but the chosen pins must be able to output digital level.
2. AT keyboards runs on 5V; however, the ESP32 micro-controller runs on 3.3V. Therefore, it is needed to put a logic level converter between the keyboard and the micro-controller.![PXL_20210701_122449126](https://user-images.githubusercontent.com/18624951/138264443-556b5dd6-b05c-47cc-b66e-547f99947638.jpg)
3. It is recommended to add a battery to the project, as bluetooth keyboards are typically wireless. However, battery life is expected to be short because old AT keyboards draw lots of current. I use a 3500mAh Li-po battery, which gives my BTC-5339-R0 around 14 hours of battery life.
