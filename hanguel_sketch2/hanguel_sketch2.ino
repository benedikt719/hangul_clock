#include <DS1302RTC.h>
#include <TimeLib.h>
#include "Func.h"

// Set pins:  CE(reset), IO(dat),CLK
DS1302RTC RTC(2, 4, 3);

// Optional connection for RTC module


void setup(void)
{
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  
  Serial.begin(9600);
    
  // Activate RTC module
 
  Serial.println("RTC module activated");
  delay(500);
  
  if (RTC.haltRTC()) {
    Serial.println("The DS1302 is stopped.  Please set time");
    Serial.println("to initialize the time and begin running.");
    Serial.println();
  }
  if (!RTC.writeEN()) {
    Serial.println("The DS1302 is write protected. This normal.");
    Serial.println();

  }
  
  delay(5000);
    
  //setSyncProvider() causes the Time library to synchronize with the
  //external RTC by calling RTC.get() every five minutes by default.
  setSyncProvider(RTC.get);

  Serial.println("RTC Sync");
  if (timeStatus() == timeSet)
    Serial.println(" Ok!");
  else
    Serial.println(" FAIL!");

  Serial.println();
}

void loop(void)
{
    static time_t tLast;
    time_t t;
    tmElements_t tm;
    Func Func;
    
  if (RTC.read(tm) == 0){

    int hours = tm.Hour;
    int minutes = tm.Minute;
    int seconds = tm.second;
    Func.FilterHour(hours);
    Func.FilterMin(minutes);
  }
  else{
    Serial.println("fail to read");
  }
  delay(1000);
    
    //check for input to set the RTC, minimum length is 12, i.e. yy,m,d,h,m,s
    if (Serial.available() >= 12) {
        //note that the tmElements_t Year member is an offset from 1970,
        //but the RTC wants the last two digits of the calendar year.
        //use the convenience macros from Time.h to do the conversions.
        int y = Serial.parseInt();
        
        if (y >= 100 && y < 1000)
            Serial.println("Error: Year must be two digits or four digits!");
            
        else {
            if (y >= 1000)
                tm.Year = CalendarYrToTm(y);
            else    //(y < 100)
                tm.Year = y2kYearToTm(y);
            tm.Month = Serial.parseInt();
            tm.Day = Serial.parseInt();
            tm.Hour = Serial.parseInt();
            tm.Minute = Serial.parseInt();
            tm.Second = Serial.parseInt();
            t = makeTime(tm);
      //use the time_t value to ensure correct weekday is set
            if(RTC.set(t) == 0) { // Success
              setTime(t);

              Serial.println("RTC set to: ");
              printDateTime(t);
              Serial.println();
      }
      else
        Serial.println();
        
        Serial.println("RTC set failed!");
  
        //dump any extraneous input
        while (Serial.available() > 0) Serial.read();
        }
    }
    
    t = now();
    if (t != tLast) {
        tLast = t;
        printDateTime(t);
        Serial.println();
    }
}

//print date and time to Serial
void printDateTime(time_t t)
{
   printDate(t);
   Serial.println("----------------------");
   printTime(t);
}

//print time to Serial
void printTime(time_t t)
{
    printI00(hour(t), ':');
    printI00(minute(t), ':');
    printI00(second(t), ' ');
}

//print date to Serial
void printDate(time_t t)
{
    printI00(day(t), 0);
    Serial.print(monthShortStr(month(t)));
    Serial.println(year(t), DEC);

}

//Print an integer in "00" format (with leading zero),
//followed by a delimiter character to Serial.
//Input value assumed to be between 0 and 99.
void printI00(int val, char delim)
{
    if (val < 10) Serial.print("0");
    Serial.print(val, DEC);
    
    if (delim > 0) Serial.print(delim);
    
    return;
}
