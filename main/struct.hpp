/**
 * @file struct.hpp
 * @author Tom2rec
 * @date 02.11.2020
 */

struct target
{
    uint8_t broadcastAddress[6];
    int encType;
    int PWR;
    int beacons;
    time_t firstSeen;
    time_t lastSeen;
};
