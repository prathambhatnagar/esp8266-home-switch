#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char* ssid ="Galaxy";
const char* password ="bhanu128";

ESP8266WebServer server(80);

void setup(){
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  delay(1000);
  Serial.print("Connecting to ");
  Serial.println(WiFi.SSID());
  Serial.println("Connecting");
  

    while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(1000);
  }

  if(WiFi.status() == WL_CONNECTED){
    Serial.print("Connected to " );
    Serial.println(WiFi.SSID() );
    Serial.print("IP Address :\t");
    Serial.println(WiFi.localIP());
  }

  if(MDNS.begin("Esp8266")){
    Serial.println("mDNS Responder Started");
  }
  else{
    Serial.println(" Error mDNS Responder!"); 
  }

  server.on("/",handleRoot);
  server.on("/ram",greet);
  
  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP Server Started");
  
}

void loop(){
  server.handleClient();
}

void handleRoot(){
  server.send(200,"text/plain","Hello from ESP");
}

void handleNotFound(){
  server.send(404,"text/plain","404 : Requiest Not Found");
}

void greet(){
  server.send(200,"text/plain","JAI SHREE RAM");
}