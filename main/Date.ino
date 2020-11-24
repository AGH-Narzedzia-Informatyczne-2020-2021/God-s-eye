#include <DateTime.h>
#include <DateTimeStrings.h>

#define TIME_MSG_LEN  11   // time sync to PC is HEADER and unix time_t as ten ascii digits
#define TIME_HEADER  255   // Header tag for serial time sync message

void setup(){
  Serial.begin(19200);
}

void  loop(){  
  getPCtime();   // try to get time sync from pc        
  if(DateTime.available()) { 
    unsigned long prevtime = DateTime.now();
    while( prevtime == DateTime.now() )  
      ;
    DateTime.available(); 
    digitalClockDisplay( );   

    /
    Serial.print( TIME_HEADER,BYTE); 
    Serial.println(DateTime.now());      
  }
}

void getPCtime() {
  
  while(Serial.available() >=  TIME_MSG_LEN ){  
    if( Serial.read() == TIME_HEADER ) {        
      time_t pctime = 0;
      for(int i=0; i < TIME_MSG_LEN -1; i++){  
        char c= Serial.read();          
        if( c >= '0' && c <= '9')  
          pctime = (10 * pctime) + (c - '0') ;            
      }  
      DateTime.sync(pctime);   
    }  
  }
}

void digitalClockDisplay(){
  // digital clock display of current time
  Serial.print(DateTime.Hour,DEC);  
  printDigits(DateTime.Minute);  
  printDigits(DateTime.Second);
  Serial.print(" ");
  Serial.print(DateTimeStrings.dayStr(DateTime.DayofWeek));
  Serial.print(" ");  
  Serial.print(DateTimeStrings.monthStr(DateTime.Month));  
  Serial.print(" ");
  Serial.println(DateTime.Day, DEC);  
}

void printDigits(byte digits){
  // utility function for digital clock display
  Serial.print(":");
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits,DEC);  
}