#include <Wire.h>

const int GSR=A0;
long sensorValue=0;
long gsr_average=0;

void setup() 
{
    Serial.begin(9600);
    Serial.println("Heart rate sensor and GSR sensor:");
    Wire.begin();
}
void loop()
{
    Wire.requestFrom(0xA0 >> 1, 1);    // request 1 bytes from slave device
    while(Wire.available())  // slave may send less than requested
    {         
        unsigned char c = Wire.read();   // receive heart rate value (a byte)
        Serial.println(c, DEC);         // print heart rate value
    }

    long sum=0;
    for(int i=0;i<10;i++)           //Average the 10 measurements to remove the glitch
    {
      sensorValue=analogRead(GSR);
      sum += sensorValue;
      delay(5);
    }
   gsr_average = sum/10;
   Serial.println(gsr_average);
    
    delay(500);
}
