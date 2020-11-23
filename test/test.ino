/**
 * @file test.ino
 * @author Piotr Sokołowski (psokolowski@student.agh.edu.pl)
 * @brief Firmware to test basic functions of God's eye device
 * @version 0.1
 * @date 2020-11-02
 * 
 * @copyright Copyright (c) 2020
 * 
 */

void setup()
{
    WiFi.mode(WIFI_OFF);     // For some reasons, Wi-fi should be turned off before any actions
    pinMode(LED, OUTPUT);    // Set LED as output
    digitalWrite(LED, HIGH); // Turn LED off
    Serial.begin(115200);    // Enable serial connection at baudrate 115200
    Serial.println();        // After boot there are some chars, so let's make empty line before test
    Serial.println();
    WiFi.mode(WIFI_STA);
    Serial.println("Wi-fi enabled successfully");
    network = scanWifi();
    connected = connectTo(network)
    Serial.println();
    Serial.print("Connected successfully to ");
    Serial.print(netwok);
    Serial.println(" network");
    Serial.println();
}

void loop()
{
    // Let's display on monitor everything, what it gets!
    if (Serial.available() > 0);
    {
        digitalWrite(LED, LOW);            // On data recieve, turn LED on
        Serial.print(Serial.readString()); // Print recieved string
        digitalWrite(LED, HIGH);           // Turn LED off
    }
}

void loop()
{
    if (connected)
        Seria.print("Connected to wifi")
    else
        Serial.print("device is offline");
}
