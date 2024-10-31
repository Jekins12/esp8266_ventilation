#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>
#include <Servo.h>
#include "config.h"

Servo servo;

ESP8266WebServer server(80);

void setup() {

  Serial.begin(115200);
  // Connect to Wi-Fi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.println(WiFi.localIP().toString());
  // Define HTTP endpoints
  server.on("/discover", HTTP_GET, handleDiscover);
  server.on("/close", HTTP_GET, handleClose);
  server.on("/open", HTTP_GET, handleOpen);
  
  // Start server
  server.begin();
  Serial.println("HTTP server started");

  pinMode(led, OUTPUT);
  
}

void loop() {
  server.handleClient();
}

void handleDiscover() {
  StaticJsonDocument<200> doc;
  doc["name"] = "ESP8266 Ventilation";
  doc["ip_address"] = WiFi.localIP().toString(); // Add the IP address
  doc["mac_address"] = WiFi.macAddress(); // Add the MAC address
  JsonArray endpoints = doc.createNestedArray("endpoints");
  endpoints.add("/close");
  endpoints.add("/open");

  String response;
  serializeJson(doc, response);

  server.send(200, "application/json", response);
}

void handleClose() {
  digitalWrite(led, HIGH);
  servo.attach(servoPin);
  delay(10);
  servo.write(0);
  server.send(200, "text/plain", "Ventilation closed");
  delay(10);
  servo.detach();
}

void handleOpen() {
  digitalWrite(led, LOW);
  servo.attach(servoPin);
  delay(10);
  servo.write(180);
  server.send(200, "text/plain", "Ventilation opened");
  delay(10);
  servo.detach();
}
