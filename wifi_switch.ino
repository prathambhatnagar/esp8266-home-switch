#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char* ssid ="Galaxy";
const char* password ="bhanu128";

ESP8266WebServer server(80);

void setup(){
  bool toggle = false;
  pinMode(1,OUTPUT);

  WiFi.begin(ssid, password);

  // Serial.print("Connecting to "); Serial.println(WiFi.SSID());
  // Serial.print("Connecting");

  while(WiFi.status() != WL_CONNECTED){
    toggle = !toggle;
    digitalWrite(1,toggle);
    delay(100);

  }

  if(WiFi.status() == WL_CONNECTED){
    Serial.print("Connected to " );
    Serial.println(WiFi.SSID() );
    Serial.print("IP Address :\t");
    Serial.println(WiFi.localIP());
    digitalWrite(1,HIGH);
    
    }

  // if(MDNS.begin("Esp8266")){
  //   Serial.println("mDNS Responder Started");
  // }else{
  //   Serial.println(" Error mDNS Responder!");
  // }

  server.on("/",handleRoot);
  server.on("/ram",greet);
  server.on("/on",turnOn);
  server.on("/off",turnOff);
  server.on("/press",pressButton);
  server.on("/reset",hardRestart);
  server.on("/display",display);

  server.onNotFound(handleNotFound);

  server.begin();
  // Serial.println("HTTP Server Started");
  
}

void loop(){
  server.handleClient();
}

void handleRoot(){
  server.send(200,"text/plain","Hello from ESP");
}

void handleNotFound(){
  server.send(404,"text/plain","404 :Not Found");
}

void greet(){
  server.send(200,"text/html","<h1>JAI SHREE RAM</h1>");
  
}
void turnOff(){
  server.send(200,"text/plain","LED TURNED OFF");
  digitalWrite(1, HIGH);   
}

void turnOn(){
  server.send(200,"text/plain","LED TURNED ON");
  digitalWrite(1, LOW);   
}

void pressButton(){
  digitalWrite(1, LOW);    
  delay(200);    
  digitalWrite(1, HIGH);
  server.send(200,"text/plain","Button Pressed");
    
}
void hardRestart(){
  digitalWrite(1, LOW);
  delay(12000);
  digitalWrite(1, HIGH);
  server.send(200, "text/plain", "Performing Hard Restart");
}

void display(){
  server.send(200,"text/plain","Display ONE");
  delay(2000);
  server.send(200,"text/plain","Display TWO");
  
}
