

/**
   BasicHTTPClient.ino

    Created on: 24.05.2015

*/

#include <Arduino.h>


#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>

#include <WiFiClient.h>

ESP8266WiFiMulti WiFiMulti;


//int TRIG = D1;
//int ECHO = D2;
int ENA = D3;
int ENB = D8;
int IN1 = D4;
int IN2 = D5;
int IN3 = D6;
int IN4 = D7;
//float timeduration;
//float distance ;
//float distance_cm ;
String socketstatus = "S";


void setup() {

 //pimModeTRIG, OUTPUT);
  //pinMode(ECHO, INPUT);
  
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin(9600);
  // Serial.setDebugOutput(true);





  WiFi.begin("MTN_4G_31FAC4", "D21415A5");
  
  while ((WiFi.status() != WL_CONNECTED)) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
   Serial.println("Connected to WiFi!");
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
      String payload = http.getString();
      socketstatus = payload;
      http.end();
    }
  }
  delay(1000);
  if (socketstatus == "F") {
    forward(255);
  }

  if (socketstatus == "B") {
    reverse(255);
  }
  if (socketstatus == "R") {
    turn_right(255);
  }
  if (socketstatus == "L") {
    turn_left(255);
  }
  if (socketstatus == "S") {
    brake();
  }

//  if (get_distance()<=10){
//    brake();
//  }
}

//float get_distance() {
  //digitalWrite(TRIG, LOW);
  //digitalWrite(TRIG, HIGH);
  //delayMicroseconds(5);
  //timeduration = pulseIn(ECHO, HIGH);
  //distance = timeduration * 0.017;
  //return (distance);


void turn_right(int Speed) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, Speed / 2);
  analogWrite(ENB, Speed);
}

void turn_left(int Speed) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed / 2);
}

void brake() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

void forward(int Speed) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
}

void reverse(int Speed) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
}
