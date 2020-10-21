/**
 * @brief Blink onboard LED to communicate with user.
 * IMPORTANT: this function pauses program 
 * @param count How many times LED will blink
 * @param time Specifies on/off interval in milliseconds
 * 
 */
void blink(int count, int time)
{
    for (int i = 0; i < count; i++)
    {
        digitalWrite(LED, LOW);
        delay(time);
        digitalWrite(LED, HIGH);
        delay(time);
    }
}