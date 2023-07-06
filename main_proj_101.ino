#include <IRremoteESP8266.h>
#include <IRsend.h>

const int IR_LED_PIN = 4;
IRsend irsend(IR_LED_PIN);

void setup() {
  Serial.begin(115200);
  delay(2000); // Wait for serial to connect
}

void loop() {
  // Define your IR code here
  uint16_t irCode[] = {0xAAAA, 0xBBBB, 0xCCCC, 0xDDDD, 0xEEEE};
  int irCodeLength = sizeof(irCode) / sizeof(irCode[0]);

  // Send the IR code
  irsend.sendRaw(irCode, irCodeLength, 38); // 38kHz carrier frequency

  // Print the IR code to serial for debugging
  for (int i = 0; i < irCodeLength; i++) {
    Serial.print(irCode[i], HEX);
    Serial.print(" ");
  }
  Serial.println("");

  delay(1000); // Wait before sending the next IR code
}
