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
    // Let's display on monitor everything, what it gets!
    if (Serial.available() > 0)
    {
        enableLED();                             // On data recieve, turn LED on
        String userString = Serial.readString(); // Save user string to variable
        Serial.print(userString);                // Print recieved string
        disableLED();                            // Turn LED off
    }
}