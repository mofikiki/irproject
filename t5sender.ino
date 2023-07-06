#include <IRremote.h>

// Define switch pin

// Define a variable for the button state

const int ir_trans = 5;
// Create IR Send Object
IRsend irsend;
String command;




void setup()
{
  Serial.begin(9600);

}

void loop() {
  if (Serial.available()) {

    // on
    char O = Serial.read();
    if (command == 'O') {
      irsend.sendNEC(0xC90040A, 32);
    }
        delay(200);

    //off
    char D = Serial.read();
    if (command == 'D') {
      irsend.sendNEC(0x1C90060A, 32);
    }
        delay(200);

    //cool mode
    char c = Serial.read();
    if (command == 'c') {
      irsend.sendNEC(0x9090060A, 32);
    }
        delay(200);

    // dry mode
    char d = Serial.read();
    if (command == 'd') {
      irsend.sendNEC(0x5890060A, 32);
    }
        delay(200);

    //fan mode
    char F = Serial.read();
    if (command == 'F') {
      irsend.sendNEC(0xD090060A, 32);
    }
        delay(200);


    // this is the heat mode
    char h = Serial.read();
    if (command == 'h') {
      irsend.sendNEC(0x3030060A, 32);
    }
        delay(200);


    // this i the auto mode
    char A = Serial.read();
    if (command == 'A') {
      irsend.sendNEC(0x1090060A, 32);
    }
        delay(200);


    // increase fan by 1
    char f = Serial.read();
    if (command == 'f') {
      irsend.sendNEC(0x1890060A, 32);
    }
        delay(200);

    // increase fan by 2
    char u = Serial.read();
    if (command == 'u') {
      irsend.sendNEC(0x1490060A, 32);
    }
        delay(200);

    // increase fan by 3
    char w = Serial.read();
    if (command == 'w') {
      irsend.sendNEC(0x1C90060A, 32);
    }
        delay(200);

    // swing
    char S = Serial.read();
    if (command == 'S') {
      irsend.sendNEC(0x1090060A, 32);
    }


    delay(200);


  }

}
