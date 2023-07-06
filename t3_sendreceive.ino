#include <IRremote.h>


//#include <IRremote.h>

const int IR_TRANSMIT_PIN = 3;

IRsend irsend;

void setup() {
  Serial.begin(9600);
}

void loop() {

  if(Serial.available()){
    
    char c = Serial.read();


    if (c == 'c'){
  irsend.sendNEC(0xFF30CF, 32);
        delay(500);

      
      }
    
    
    }
}
