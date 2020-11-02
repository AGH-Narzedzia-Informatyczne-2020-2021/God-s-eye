#include struct.ino
#define tarNum = 100; // Number of hosts in array 

typedef struct target Target;

Target targets[tarNum];
/**for(int i = 0; i < ; i++)
{
    targets[i] = {
        macAdress[6] = MACdecoder(string adress,**macAdress);
        IPHosts[255][4] = ...;
        encType = ...;
        PWR = ...;
        beacons = ...;
        firstSeen = ...;
        lastSeen = ...;
    }

}


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

void IPdecoder(string IPaddresses[],**IParray)
{
    for(int j = 0; j < sizeof(IPaddresses); j++){
        for(int i = 0; i < 4; i++)
        {
            (*IParray)[j][i] = getValue(IPaddresses[j],":",i);
        }
    }

}

void MACdecoder(string MACadress,**MACarray)
{
    for(int i = 0; i < 4; i++)
    {
        (*MACarray)[i] = getValue(MACaddress,":",i);
    }

}

*/