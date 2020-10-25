#include <user_modules.h>
int i=1;
#define czas 140;
#define maxchannel 13;
void setup() {
  // put your setup code here, to run once:
  wifi.monitor.start
}

void loop() {
  // put your main code here, to run repeatedly:
  wifi.monitor.channel(i);
  i++;  //zmienianie kanałów wifi
  if (i>maxchannel) //kanał o najwyższej wartości, który jest używane w Polsce
    i=1; //nie chcemy przekroczyć tej wartości, więc wracamy spowrotem na kanał pierwszy
  delay (czas); //sygnał zazwyczaj wysyłany jest zazwyczaj co 100 milisekund z lekkim marginesem ustawiam 140
}
