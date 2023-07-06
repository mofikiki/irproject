#include <IRremote.h>

const int ir_trans = 3;
IRsend irsend;
String command;

void setup() {
  Serial.begin(9600);
}

void loop() {
Gree();
}


void Gree() {

  if (Serial.available()) {
    char receivedChar = Serial.read();
    command = String(receivedChar);
// on 
    if (command == "O") {
      irsend.sendNEC(0x90040A, 32);
    }
    delay(50);
// off
    if (command == "D") {
      irsend.sendNEC(0x1090060A, 32);
    }
    delay(50);
//cool  mode
    if (command == "c") {
      irsend.sendNEC(0x9090060A, 32);
    }
    delay(50);
//  dry mode
    if (command == "d") {
      irsend.sendNEC(0x5890060A, 32);
    }
    delay(50);
// fan mode
    if (command == "F") {
      irsend.sendNEC(0xD090060A, 32);
    }
    delay(50);
// heat mode 
    if (command == "h") {
      irsend.sendNEC(0x3030060A, 32);
    }
    delay(50);
// auto mode
    if (command == "A") {
      irsend.sendNEC(0x1090060A, 32);
    }
    delay(50);
//fan 1
    if (command == "f") {
      irsend.sendNEC(0x1890060A, 32);
    }
    delay(50);
//fan 2
    if (command == "u") {
      irsend.sendNEC(0x1490060A, 32);
    }
    delay(50);
// fan 3
    if (command == "w") {
      irsend.sendNEC(0x1C90060A, 32);
    }
    delay(50);
//swing 
    if (command == "S") {
      irsend.sendNEC(0x1090060A, 32);
    }
    delay(50);
  }
}
