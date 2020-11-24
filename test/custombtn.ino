/**
 * @file custombtn.ino
 * @author Piotr Sokołowski (psokolowski@student.agh.edu.pl)
 * @brief Custom action with FLASH button
 * @version 0.1
 * @date 2020-11-24
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#define BUTTON 0

/**
 * @brief Check if button is pressed
 * 
 * @return true When button is pressed
 * @return false When button is released
 */
bool isBtnDown()
{
    if (digitalRead(BUTTON) == LOW)
        return true;
    return false;
}

/**
 * @brief Check if button is released
 * 
 * @return true When button is released
 * @return false When button is pressed
 */
bool isBtnUp()
{
    if (digitalRead(BUTTON) == HIGH)
        return true;
    return false;
}