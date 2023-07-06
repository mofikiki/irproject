
#include <IRremote.h> // >v3.0.0
                                           
#define PIN_RECV 3

void setup()  
{  
  Serial.begin(9600); //initialize serial connection to print on the Serial Monitor of the Arduino IDE
  IrReceiver.begin(PIN_RECV); // Initializes the IR receiver object
}  
                               
void loop()  
{  
  if (IrReceiver.decode()) {
    Serial.println("Received something...");    
    IrReceiver.printIRResultShort(&Serial); // Prints a summary of the received data
    Serial.println();
    IrReceiver.resume(); // Important, enables to receive the next IR signal
  }
  delay(1000);  
} 
