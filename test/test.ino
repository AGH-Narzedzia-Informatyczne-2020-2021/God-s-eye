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
    setupLED();           // Set LED as output
    disableLED();         // Turn LED off
    Serial.begin(115200); // Enable serial connection at baudrate 115200
    Serial.println();     // After boot there are some chars, so let's make empty line before test
    Serial.println();
    Serial.print("Device's MAC address: ");
    Serial.println(macAddr());
    Serial.println("Going to testing loop...");
}

void loop()
{
    separate();

#pragma region Wi - Fi
    enableWifi();
    Serial.println("Wi-fi enabled successfully");
    connectToNetwork();
    if (isWifiConnected())
        httpPostRequest("http://vps.smarthive.pl:8081/", "");
    disableWifi();
    Serial.println("Disabled Wi-Fi");
#pragma endregion

    separate();

#pragma region Serial connection
    Serial.println("Testing serial connection...");
    Serial.println(" Type \"exit\" to leave this test");
    Serial.println(" Type \"shutdown\" to disable device");
    readFromSerial();
    Serial.println("Leaving serial connection test...");
#pragma endregion

    separate();

#pragma region Flash button
    while (true)
    {
        Serial.println("Press and hold FLASH button to exit this test");
        if (isBtnDown())
            break;
        delay(1000);
    }
#pragma endregion

    separate();

    Serial.println("Testing finished! It will be started again in 5 seconds...");
    delay(5000);
}