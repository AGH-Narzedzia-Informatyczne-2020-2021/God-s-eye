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
    enableWifi();
    Serial.println("Wi-fi enabled successfully");
}

void loop()
{
    Serial.println("Testing serial connection...");
    Serial.println("Type \"exit\" to leave this test");
    Serial.println("Type \"shutdown\" to disable device");
    while (true)
    {
        if (Serial.available() > 0)
        {
            enableLED();                                      // On data recieve, turn LED on
            String userString = Serial.readStringUntil('\n'); // Save user string to variable
            Serial.print("    > ");                           // Print indentation
            Serial.println(userString);                       // Print recieved string
            disableLED();                                     // Turn LED off
            if (userString == "exit")
                break;
            if (userString == "shutdown")
                ESP.deepSleep(0);
        }
    }
    Serial.println("Leaving serial connection test...");
    Serial.println("Testing finished! It will be started again in 5 seconds...");
    delay(5000);
}