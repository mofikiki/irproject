#include <IRremote.h>

const int RECV_PIN = 3;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  //irrecv.blink13(true);
}

void loop(){
  if (irrecv.decode(&results)){
         digitalWrite(13,1);
         delay(1000);
        switch (results.decode_type){

          case JVC: Serial.println("JVC"); 
            Serial.println(results.value, HEX  );
            break ;
          default: ;
          }
        irrecv.resume();
 }
}
