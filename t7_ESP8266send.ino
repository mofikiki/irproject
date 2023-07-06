#include <i18n.h>
#include <IRac.h>
#include <IRmacros.h>
#include <IRrecv.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <IRtext.h>
#include <IRtimer.h>
#include <IRutils.h>
#include <ir_Airton.h>
#include <ir_Airwell.h>
#include <ir_Amcor.h>
#include <ir_Argo.h>
#include <ir_Bosch.h>
#include <ir_Carrier.h>
#include <ir_Coolix.h>
#include <ir_Corona.h>
#include <ir_Daikin.h>
#include <ir_Delonghi.h>
#include <ir_Ecoclim.h>
#include <ir_Electra.h>
#include <ir_Fujitsu.h>
#include <ir_Goodweather.h>
#include <ir_Gree.h>
#include <ir_Haier.h>
#include <ir_Hitachi.h>
#include <ir_Kelon.h>
#include <ir_Kelvinator.h>
#include <ir_LG.h>
#include <ir_Magiquest.h>
#include <ir_Midea.h>
#include <ir_Mirage.h>
#include <ir_Mitsubishi.h>
#include <ir_MitsubishiHeavy.h>
#include <ir_NEC.h>
#include <ir_Neoclima.h>
#include <ir_Panasonic.h>
#include <ir_Rhoss.h>
#include <ir_Samsung.h>
#include <ir_Sanyo.h>
#include <ir_Sharp.h>
#include <ir_Tcl.h>
#include <ir_Technibel.h>
#include <ir_Teco.h>
#include <ir_Toshiba.h>
#include <ir_Transcold.h>
#include <ir_Trotec.h>
#include <ir_Truma.h>
#include <ir_Vestel.h>
#include <ir_Voltas.h>
#include <ir_Whirlpool.h>

#include <Arduino.h>


#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>

#include <WiFiClient.h>

ESP8266WiFiMulti WiFiMulti;

#include <IRremote.h>

const int ir_trans = D1;
IRsend irsend;
String command;

void setup() {
  WiFi.begin("MTN_4G_31FAC4", "D21415A5");
  
  while ((WiFi.status() != WL_CONNECTED)) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
   Serial.println("Connected to WiFi!");
  
  Serial.begin(9600);
}

void loop() {

   // wait for WiFi connection

  if ((WiFi.status() == WL_CONNECTED)) {
    WiFiClient client;
    HTTPClient http;
    http.begin(client, "http://192.168.0.178:80/getstate?");   // HTTP
    // start connection and send HTTP header
    int httpCode = http.GET();
    // httpCode will be negative on error
    if (httpCode > 0) {
      // file found at server
      String payload
Gree(); = http.getString();
      socketstatus = payload;
      http.end();
    }
  }
  delay(1000);

  
}


void Gree() {

  if (Serial.available()) {
    char receivedChar = Serial.read();
    command = String(receivedChar);

    if (command == "O") {
      irsend.sendNEC(0xC90040A, 32);
    }
    delay(50);

    if (command == "D") {
      irsend.sendNEC(0x1C90060A, 32);
    }
    delay(50);

    if (command == "c") {
      irsend.sendNEC(0x9090060A, 32);
    }
    delay(50);

    if (command == "d") {
      irsend.sendNEC(0x5890060A, 32);
    }
    delay(50);

    if (command == "F") {
      irsend.sendNEC(0xD090060A, 32);
    }
    delay(50);

    if (command == "h") {
      irsend.sendNEC(0x3030060A, 32);
    }
    delay(50);

    if (command == "A") {
      irsend.sendNEC(0x1090060A, 32);
    }
    delay(50);

    if (command == "f") {
      irsend.sendNEC(0x1890060A, 32);
    }
    delay(50);

    if (command == "u") {
      irsend.sendNEC(0x1490060A, 32);
    }
    delay(50);

    if (command == "w") {
      irsend.sendNEC(0x1C90060A, 32);
    }
    delay(50);

    if (command == "S") {
      irsend.sendNEC(0x1090060A, 32);
    }
    delay(50);
  }
}
