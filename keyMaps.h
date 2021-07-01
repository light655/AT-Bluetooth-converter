#ifndef keyPress_h
#define KeyPress_h

#include "Arduino.h"
#include <BleConnectionStatus.h>
#include <BleKeyboard.h>
#include <KeyboardOutputCallbacks.h>

const uint8_t keyMap[256] = {
  0x00, 0xCA, 0x00, 0xC6, 0xC4, 0xC2, 0xC3, 0xCD, 
  0x00, 0xCB, 0xC9, 0xC7, 0xC5, 0xB3, 0x60, 0x00, 
  0x00, 0x82, 0x81, 0x00, 0x80, 0x71, 0x31, 0x00, 
  0x00, 0x00, 0x7A, 0x73, 0x61, 0x77, 0x32, 0x00, 
  0x00, 0x63, 0x78, 0x64, 0x65, 0x34, 0x33, 0x00, 
  0x00, 0x20, 0x76, 0x66, 0x74, 0x72, 0x35, 0x00, 
  0x00, 0x6E, 0x62, 0x68, 0x67, 0x79, 0x36, 0x00, 
  0x00, 0x00, 0x6D, 0x6A, 0x75, 0x37, 0x38, 0x00, 
  0x00, 0x2C, 0x6B, 0x69, 0x6F, 0x30, 0x39, 0x00, 
  0x00, 0x2E, 0x2F, 0x6C, 0x3B, 0x70, 0x2D, 0x00, 
  0x00, 0x00, 0x27, 0x00, 0x5B, 0x3D, 0x00, 0x00, 
  0xC1, 0x85, 0xB0, 0x5D, 0x00, 0x5C, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB2, 0x00, 
  0x00, 0xE1, 0x00, 0xE4, 0xE7, 0x00, 0x00, 0x00, 
  0xEA, 0xEB, 0xE2, 0xE5, 0xE6, 0xE8, 0xB1, 0xDB, 
  0xCC, 0xDF, 0xE3, 0xDE, 0xDD, 0xE9, 0xCF, 0x00, 
  0x00, 0x00, 0x00, 0xC8, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const uint8_t extKeyMap[256] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x86, 0x00, 0x00, 0x84, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x83, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x87, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xED, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xDC, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0xD5, 0x00, 0xD8, 0xD2, 0x00, 0x00, 0x83, 
  0xD1, 0xD4, 0xD9, 0x00, 0xD7, 0xDA, 0x00, 0x00, 
  0x00, 0x00, 0xD6, 0x00, 0x00, 0xD3, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

#endif keyPress_h