#include struct.ino
#define tarNum = 100; // Number of hosts in array 

typedef struct target Target;

Target targets[tarNum];


String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}

void IPdecoder(string IPaddresses[], IParray)
{
    for(int j = 0; j < sizeof(IPaddresses); j++){
        for(int i = 0; i < 4; i++)
        {
            IParray[j][i] = getValue(IPaddresses[j],":",i);
        }
    }

}

void MACdecoder(string MACadress, MACarray)
{
    for(int i = 0; i < 4; i++)
    {
        MACarray[i] = getValue(MACaddress,"-",i);
    }

}

// int macAdress[6];
// MACdecoder(adress,macAdress);
// int IPHosts[255][4];
// IPdecoder(IPaddresses, IPHosts);

/**for(int i = 0; i < ; i++)
{
    targets[i] = {
        macAdress;
        IPHosts;
        encType = ...;
        PWR = ...;
        beacons = ...;
        firstSeen = ...;
        lastSeen = ...;
    }

}

*/
