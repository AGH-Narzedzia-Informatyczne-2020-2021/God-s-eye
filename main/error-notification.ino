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