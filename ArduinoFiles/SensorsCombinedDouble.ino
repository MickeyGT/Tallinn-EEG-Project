#include <Wire.h>

const int GSR=A0;
double sensorValue=0;
double gsr_average=0;

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
        double c = Wire.read();   // receive heart rate value (a byte)
        Serial.print(c);         // print heart rate value
        Serial.println("heart");
    }
   sensorValue=analogRead(GSR);
   Serial.print(sensorValue);
   Serial.println("gsr");
    
    delay(10);
}
