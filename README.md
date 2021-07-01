# AT-Bluetooth-converter

This project uses a ESP32 micro-controller to convert AT keyboard protocol to bluetooth, planned to added support for other protocols (if I actually get those keyboards on hand). The [ESP32-BLE-Keyboard](ESP32-BLE-Keyboard) library is used in this project.

This project is still under development, and still lacks some feature. 
1. Due to Library restrictions, NumLock, CapsLock, and ScrollLock states cannot be sent from the computer to the converter. As a result, the lock lights will not work, but the keys will work as intented.
2. Since PrintScreen and Pause keys have longer scan codes, I omitted those two keys in this version.
