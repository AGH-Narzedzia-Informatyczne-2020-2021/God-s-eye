/**
 * @file error-notification.ino
 * @author Piotr Sokołowski (psokolowski@student.agh.edu.pl)
 * @brief Notifying about errors without serial communication
 * @version 0.1
 * @date 2020-11-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */

// Define built-in LED on GPIO2 pin
#define LED 2

/**
 * @brief Blink onboard LED to communicate with user.
 * IMPORTANT: this function pauses program 
 * @param count How many times LED will blink
 * @param time Specifies on/off interval in milliseconds
 * 
 */
void blink(int count)
{
    for (int i = 0; i < count; i++)
    {
        digitalWrite(LED, LOW);
        delay(200);
        digitalWrite(LED, HIGH);
        delay(200);
    }
}