/**
 * @file struct.ino
 * @author Tom2rec
 * @date 02.11.2020
 */

struct target
{
    byte macAdress[6];
    byte ipHosts[255][4];
    string encType;
    int PWR;
    int beacons;
    time_t firstSeen;
    time_t lastSeen;
};


