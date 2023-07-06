#include <IRsend.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <Arduino.h>
#include <IRremoteESP8266.h>


#include <IRac.h>

const char* ssid     = "MTN_4G_31FAC4"; // Your WiFi ssid
const char* password = "D21415A5";
const int ir_trnas = D4 ;  // The ESP GPIO pin to use that controls the IR LED.
IRsend irsend(ir_trnas);
String command = "stop";

WiFiServer server(5000);

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.print("Attempting to connect to SSID");
  WiFi.begin(ssid, password);
  // Attempt to connect to WiFi network:
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    // Connect to WPA/WPA2 network. Change this line if using open or WEP  network:
    // Wait 1 seconds for connection:
    delay(1000);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());   //You can get IP address assigned to ESP
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    while (client.connected()) {
      Serial.println("CONNECTED");
      if (client.available()) {
        String request = client.readStringUntil('\r');
        if (request.indexOf("/on") != -1) {
          Serial.println("Data Recieved");
          irsend.sendNEC(0x1090060A, 32);
          client.flush();
        }
      }
      else {
        Serial.println(" Client not available");
        }
    }
    client.stop();
    delay(1000);
  }
}
//  if (WiFi.status() == WL_CONNECTED) {
//    WiFiClient client;
//    HTTPClient http;
//    http.begin(client, "http://192.168.0.178:80/getstate?");   // HTTP
//
//    int httpCode = http.GET();
//    if (httpCode > 0) {
//      String payload = http.getString();
//      const char* payloadChar = payload.c_str();
//      command = String(payloadChar);
//      http.end();
//    }
//    if (command == "O") {
//      irsend.sendNEC(0xC90040A, 32);
//    }
//    delay(50);
//
//    if (command == "D") {
//      irsend.sendNEC(0x1C90060A, 32);
//    }
//    delay(50);
//
//    if (command == "c") {
//      irsend.sendNEC(0x9090060A, 32);
//    }
//    delay(50);
//
//    if (command == "d") {
//      irsend.sendNEC(0x5890060A, 32);
//    }
//    delay(50);
//
//    if (command == "F") {
//      irsend.sendNEC(0xD090060A, 32);
//    }
//    delay(50);
//
//    if (command == "h") {
//      irsend.sendNEC(0x3030060A, 32);
//    }
//    delay(50);
//
//    if (command == "A") {
//      irsend.sendNEC(0x1090060A, 32);
//    }
//    delay(50);
//
//    if (command == "f") {
//      irsend.sendNEC(0x1890060A, 32);
//    }
//    delay(50);
//
//    if (command == "u") {
//      irsend.sendNEC(0x1490060A, 32);
//    }
//    delay(50);
//
//    if (command == "w") {
//      irsend.sendNEC(0x1C90060A, 32);
//    }
//    delay(50);
//
//    if (command == "S") {
//      irsend.sendNEC(0x1090060A, 32);
//    }
//    delay(50);
//  }
//  delay(1000);
//}










//  if (Serial.available()) {
//    char receivedChar = Serial.read();
//    command = String(receivedChar);
