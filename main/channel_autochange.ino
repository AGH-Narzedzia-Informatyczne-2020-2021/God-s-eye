void channel_autochange()   //zmienianie kanałów wifi
{
  wifi.monitor.start ()
  for (int i=1; i<maxchannel; i++) 
  {
    wifi.monitor.channel(i);
    delay (czas);
  }
}