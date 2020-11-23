/**
 * @file blink.ino
 * @author Piotr Sokołowski (psokolowski@student.agh.edu.pl)
 * @brief LED blinking
 * @version 0.1
 * @date 2020-11-23
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#define LED 2

/**
 * @brief Enabling on-board LED
 * 
 */
void enableLED()
{
    digitalWrite(LED, LOW);
}

/**
 * @brief Disabling on-board LED
 * 
 */
void disableLED()
{
    digitalWrite(LED, HIGH);
}

/**
 * @brief On-board LED blinking function. Caution: this function pauses program!
 * 
 * @param time blinking interval in milliseconds
 * @param count how many times LED must turn on
 */
void blink(int time, int count)
{
    for (int i = 0; i < count; i++)
    {
        enableLED();
        delay(time);
        disableLED();
        delay(time);
    }
}
