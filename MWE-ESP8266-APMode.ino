#include <ESP8266WiFi.h>

const char *ssid = "MESH-CLICK-AP";
const char *password = "PrendsTesClics";

IPAddress local_IP(192,168,4,22);
IPAddress gateway(192,168,4,9);
IPAddress subnet(255,255,255,0);
//IPAddress local_IP(10,101,252,252);
//IPAddress gateway(10, 101, 80, 1);
//IPAddress subnet(255,0,0,0);

void setup()
{
  Serial.begin(115200);
  Serial.println();

  Serial.print("Setting soft-AP configuration ... ");
  Serial.println(WiFi.softAPConfig(local_IP, gateway, subnet) ? "Ready" : "Failed!");

  Serial.print("Setting soft-AP ... ");
  Serial.println(WiFi.softAP(ssid,password) ? "Ready" : "Failed!");
  //WiFi.softAP(ssid);
  //WiFi.softAP(ssid, password, channel, hidden, max_connection)
  
  Serial.print("Soft-AP IP address = ");
  Serial.println(WiFi.softAPIP());
}

void loop() {
  Serial.print("[Server Connected] ");
  Serial.println(WiFi.softAPIP());

  delay(2500);
}