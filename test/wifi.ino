/**
 * @file wifi.ino
 * @author Piotr Sokołowski (psokolowski@student.agh.edu.pl)
 * @brief Wi-Fi management
 * @version 0.1
 * @date 2020-11-23
 * 
 * @copyright Copyright (c) 2020
 * 
 */

/* Both libraries come with ESP8266 support in Arduino IDE. Address given below
must be added in Arduino IDE settings, and esp8266 package must be installed in
board manager
https://arduino.esp8266.com/stable/package_esp8266com_index.json */
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

#define WIFI_DELAY 500
#define MAX_SSID_LEN 32
#define MAX_CONNECT_TIME 30000

char ssid[MAX_SSID_LEN] = "";

/**
 * @brief Disable Wi-Fi
 * 
 */
void disableWifi()
{
    WiFi.mode(WIFI_OFF);
}

/**
 * @brief Enable Wi-Fi
 * 
 */
void enableWifi()
{
    disableWifi();
    WiFi.mode(WIFI_STA);
}

/**
 * @brief Checks if device is connected to Wi-Fi
 * 
 * @return true When connected to Wi-Fi network
 * @return false When not connected to Wi-Fi
 */
bool isWifiConnected()
{
    if (WiFi.status() == WL_CONNECTED)
        return true;
    return false;
}

/**
 * @brief Autoconnecting to the best network.
 * 
 */
void connectToNetwork()
{
    if (WiFi.status() != WL_CONNECTED)
    {
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
                Serial.print("Your device IP address is ");
                Serial.println(WiFi.localIP());
            }
            else
            {
                Serial.println("Connection FAILED");
            }
        }
        else
        {
            Serial.println("No open networks available");
        }
    }
}

/**
 * @brief Scan for open networks and choose the best
 * 
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
        Serial.println("Available networks:");
        for (int i = 0; i < n; ++i)
        {
            Serial.print("    > ");
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

/**
 * @brief Making a HTTP POST JSON request to server
 * 
 * @param url server full address
 * @param jsonData data to be sent
 * @return HTTP response code
 */
int httpPostRequest(String url, String jsonData)
{
    HTTPClient http;
    http.begin(url);
    http.addHeader("Content-Type", "application/json");
    auto httpCode = http.POST(jsonData);
    Serial.println(http.getString());
    http.end();
    return httpCode;
}