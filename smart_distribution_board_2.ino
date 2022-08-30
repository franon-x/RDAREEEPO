#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
//giving each relays a variable
int r1 = D1;
int r2 = D2;
int r3 = D3;
int r4 = D4;
int r5 = D5;

#ifndef STASSID
#define STASSID "Yung haryoh"
#define STAPSK  "12345679"
#endif

const char *ssid = STASSID;
const char *password = STAPSK;

ESP8266WebServer server(80);

const int led = 13;

void homepage() {
  char temp[400];

  snprintf(temp, 400,
    "<html>\
  <head>\
  </head>\
    <body>\
    <h1>HARYOH'S HOME</h1>\
    <a href =\"/onR1\"> <button>R1 ON</button></a>\
    <a href =\"/offR1\"> <button>R1 OFF</button> </a>\
    <br> <a href =\"/onR2\"> <button> R2 ON</button> </a>\
    <a href =\"/offR2\"> <button> R2 OFF</button> </a>\
    <br> <a href =\"/onR3\"> <button> R3 ON</button> </a>\
    <a href =\"/offR3\"> <button> R3 OFF</button> </a>\
    <br> <a href =\"/onR4\"> <button> R4 ON</button> </a>\
    <a href =\"/offR4\"> <button> R4 OFF</button> </a>\
    <br> <a href =\"/onR5\"> <button> R5 ON</button> </a>\
    <a href =\"/offR5\"> <button> R5 OFF</button> </a>\
  </body>\
</html>");
  server.send(200, "text/html", temp);
//  server.send(200, "text/plain", "I'm an awasome webServer!!!");

}

void handleNotFound() {
  digitalWrite(led, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";

  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }

  server.send(404, "text/plain", message);
  digitalWrite(led, 0);
}

void setup(void) {
  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);
  pinMode(r3,OUTPUT);
  pinMode(r4,OUTPUT);
  pinMode(r5,OUTPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

//  server.on("/", handleRoot);
//  server.on("/test.svg", drawGraph);
  server.on("/",homepage);
  server.on("/onR1",turnonr1);
  server.on("/offR1",turnoffr1);
  
  server.on("/onR2",turnonr2);
  server.on("/offR2",turnoffr2);
  
  server.on("/onR3",turnonr3);
  server.on("/offR3",turnoffr3);
  
  server.on("/onR4",turnonr4);
  server.on("/offR4",turnoffr4);
  
  server.on("/onR5",turnonr5);
  server.on("/offR5",turnoffr5);
  
  
  server.on("/inline", []() {
    server.send(200, "text/plain", "this works as well");
  });
  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
  MDNS.update();
}
void turnonr1 (){
  digitalWrite,LOW;
   homepage();
  
}
void turnoffr1 (){
  digitalWrite,HIGH;
   homepage();
  
}


void turnonr2 (){
  digitalWrite,LOW;
   homepage();
  
}
void turnoffr2 (){
  digitalWrite,HIGH;
   homepage();
  
}


void turnonr3 (){
  digitalWrite,LOW;
   homepage();
   
}
void turnoffr3 (){
  digitalWrite,HIGH;
   homepage();
  
}


void turnonr4 (){
  digitalWrite,LOW;
   homepage();
  
}
void turnoffr4 (){
  digitalWrite,HIGH;
   homepage();
  
}

void turnonr5 (){
  digitalWrite,LOW;
   homepage();
  
}
void turnoffr5 (){
  digitalWrite,HIGH;
   homepage();

}
