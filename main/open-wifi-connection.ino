/**
 * @brief Scanning for open networks and connecting to the strongest automatically.
 * Requires blink and switching between station and monitor mode
 * 
 */

char ssid[MAX_SSID_LEN] = "";

/**
 * @brief Autoconnecting to the best network.
 */
void connectToNetwork()
{
    if (WiFi.status() != WL_CONNECTED)
    {
        // TODO: here must be function to switch to station mode (disable monitor)
        delay(WIFI_DELAY);
        scanAndSort();
        delay(WIFI_DELAY);
        /* Global ssid param need to be filled to connect. */
        if (strlen(ssid) > 0)
        {
            Serial.print("Connecting to ");
            Serial.println(ssid);
            WiFi.begin(ssid);
            unsigned short try_cnt = 0;
            while (WiFi.status() != WL_CONNECTED && try_cnt < MAX_CONNECT_TIME / WIFI_DELAY)
            {
                delay(WIFI_DELAY);
                Serial.print(".");
                try_cnt++;
            }
            if (WiFi.status() == WL_CONNECTED)
            {
                Serial.println("");
                Serial.println("Connection Successful!");
                Serial.println("Your device IP address is ");
                Serial.println(WiFi.localIP());
                blink(GE_WIFI_CONNECTED);
            }
            else
            {
                Serial.println("Connection FAILED");
                blink(GE_WIFI_CONN_FAIL)
            }
        }
        else
        {
            Serial.println("No open networks available");
            blink(GE_NO_WIFI_AVAIL);
        }
    }
}

/**
 * @brief Scan for open networks and choose the best
 */
void scanAndSort()
{
    Serial.println("Scanning...");
    memset(ssid, 0, MAX_SSID_LEN);
    int n = WiFi.scanNetworks();
    Serial.println("Scan complete!");
    if (n != 0)
    {
        int indices[n];
        for (int i = 0; i < n; i++)
        {
            indices[i] = i;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (WiFi.RSSI(indices[j]) > WiFi.RSSI(indices[i]))
                {
                    std::swap(indices[i], indices[j]);
                }
            }
        }
        for (int i = 0; i < n; ++i)
        {
            Serial.print(WiFi.SSID(indices[i]));
            Serial.print(" ");
            Serial.print(WiFi.RSSI(indices[i]));
            Serial.print(" ");
            Serial.print(WiFi.encryptionType(indices[i]));
            Serial.println();
            if (WiFi.encryptionType(indices[i]) == ENC_TYPE_NONE)
            {
                memset(ssid, 0, MAX_SSID_LEN);
                strncpy(ssid, WiFi.SSID(indices[i]).c_str(), MAX_SSID_LEN);
                break;
            }
        }
    }
}
