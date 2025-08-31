#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

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
    Serial.println("Connected !" );
    Serial.print("IP Address :\t");
    Serial.println(WiFi.localIP());
  }

}

void loop(){
  Serial.println("Hi From Esp8266");
  delay(1000);
}

