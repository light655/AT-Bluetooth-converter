#include <BleConnectionStatus.h>
#include <BleKeyboard.h>
#include <KeyboardOutputCallbacks.h>
#include "keyMaps.h"

#define PS2_CLK 22
#define PS2_DATA 23

uint8_t thisKeyCode, pauseState = 0;
bool isPause = false, isPS = false, ext = false, release = false;
BleKeyboard myKB;

void setup() {
  myKB.begin();
  digitalWrite(PS2_CLK, LOW);
  digitalWrite(PS2_DATA, HIGH);
  pinMode(PS2_CLK, INPUT);  
  pinMode(PS2_DATA, INPUT);
}

void loop() {
  startPS2();
  thisKeyCode = 0x00;

  ignoreBit();
  for (int i = 0; i < 8; i++) {
    wait(1);
    thisKeyCode |= (digitalRead(PS2_DATA) << i);
    wait(0);
  }

  ignoreBit();
  ignoreBit();
  holdPS2();

  pauseCheck(thisKeyCode);
  if(pauseState) {
    if(pauseState == 8) pauseState = 0;
    goto loopEnd;
  }

  if(release) {
    releaseKey(thisKeyCode);
    ext = false;
    release = false;
  }
  else if(ext && thisKeyCode == 0xF0) {
    release = true;
    goto loopEnd;
  }
  else if(thisKeyCode == 0xE0 || thisKeyCode == 0xF0) {}
  else {
    pressKey(thisKeyCode);
    ext = false;
    release = false;
  } 
  
  ext = (thisKeyCode == 0xE0) ? true : false;
  release = (thisKeyCode == 0xF0) ? true : false;

  loopEnd:;
}

void holdPS2() {
  digitalWrite(PS2_CLK, LOW);
  pinMode(PS2_CLK, INPUT);
}

void startPS2() {
  digitalWrite(PS2_CLK, HIGH);
  pinMode(PS2_CLK, INPUT);
}

void ignoreBit() {
  wait(1);
  wait(0);
}

void wait(bool state) {
  while(digitalRead(PS2_CLK) == state);
}

void pauseCheck(uint8_t current) {
  if(pauseState) pauseState++;
  else if(current == 0xE1) pauseState++;
  else {}
}

void releaseKey(uint8_t current) {
  if(ext) myKB.release(extKeyMap[current]);
  else  myKB.release(keyMap[current]);
}

void pressKey(uint8_t current) {
  if(ext) {
    myKB.press(extKeyMap[current]);
  }
  else {
    myKB.press(keyMap[current]);
  }
}
