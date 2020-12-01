#include <SPI.h>
#include <WiFi.h>

char ssid[] = " ... ";     
char pass[] = " ... ";  
int status = WL_IDLE_STATUS;     // the Wifi radio's status

void setup() {

  Serial.begin(9600);

  while (status != WL_CONNECTED) {

    Serial.print("Attempting to connect to %s: ",ssid);

    status = WiFi.begin(ssid, pass);

    delay(10000); // 10s to connect

  }

  Serial.print("Connected to the network");

  printCurrentNet();

  printWifiData();

}

void loop() {

  delay(10000);

  printCurrentNet();
}

void printWifiData() {

  IPAddress ip = WiFi.localIP();

  Serial.print("IP Address: ");

  Serial.println(ip);

  Serial.println(ip);

  // printin MAC address:

  byte mac[6];

  WiFi.macAddress(mac);

  Serial.print("MAC address: ");

  Serial.print(mac[5], HEX);

  Serial.print(":");

  Serial.print(mac[4], HEX);

  Serial.print(":");

  Serial.print(mac[3], HEX);

  Serial.print(":");

  Serial.print(mac[2], HEX);

  Serial.print(":");

  Serial.print(mac[1], HEX);

  Serial.print(":");

  Serial.println(mac[0], HEX);

}

void printCurrentNet() {

  Serial.print("SSID: ");

  Serial.println(WiFi.SSID());

  // printing the MAC address of the router

  byte bssid[6];

  WiFi.BSSID(bssid);

  Serial.print("BSSID: ");

  Serial.print(bssid[5], HEX);

  Serial.print(":");

  Serial.print(bssid[4], HEX);

  Serial.print(":");

  Serial.print(bssid[3], HEX);

  Serial.print(":");

  Serial.print(bssid[2], HEX);

  Serial.print(":");

  Serial.print(bssid[1], HEX);

  Serial.print(":");

  Serial.println(bssid[0], HEX);

  // printing the encryption type:

  byte encryption = WiFi.encryptionType();

  Serial.print("Encryption Type:");

  Serial.println(encryption, HEX);

  Serial.println();
}