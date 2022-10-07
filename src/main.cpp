/**
 * LAB - ADVANCED SENSORS
 * STATEMENT OF AUTHORSHIP - I YASH KHANDUJA, 000826385 HERE BY DECLARE THAT THIS IS MY OWN WORK.
 * **/


// library for Arduino framework  
#include <Arduino.h> 
// 1-Wire sensor communication libary 
#include <OneWire.h> 
// DS18B20 sensor library 
#include <DallasTemperature.h> 
 

const int oneWireBus = D3;      
OneWire oneWire(oneWireBus); 
DallasTemperature DS18B20(&oneWire); 




void EstablishConnection(){
DS18B20.begin();
  if(DS18B20.getDeviceCount() == 0)
  {
    Serial.println(DS18B20.getDeviceCount());
    Serial.printf("DS18B20 Not Connected");
    while (DS18B20.getDeviceCount() == 0)
    {
     delay(2000);
     DS18B20.begin();
    }
    
  }
}

String tempRun(float temp)
{
  String currTemp = "Too Hot";

  if(temp<10.0) 
  {
    currTemp = "Cold!";
    return currTemp;
  }
  if(temp>10.0 && temp <15.0) 
  {
     currTemp = "Cool";
    return currTemp;
  }
  if(temp > 15.0 && temp <25.00) 
  {
    currTemp = "Perfect";
    return currTemp;
  }
  if(temp >  25 && temp < 30 ) 
  {
    currTemp = "Warm";
    return currTemp;
  }
   if(temp >  30 && temp < 35 ) 
  {
    currTemp = "Hot!";
    return currTemp;
  }
    return currTemp;
 

}

void setup() { 
  Serial.begin(115200);  
  EstablishConnection();
  DeviceAddress deviceAddress;
  DS18B20.getAddress(deviceAddress, 0);

    Serial.print("\n\nDevice address: 0x");
  for (uint8_t i = 0; i < 8; i++) {
    if (deviceAddress[i] < 16) Serial.print("0");
    Serial.print(deviceAddress[i], HEX);
  }
  Serial.println();


} 
 
void loop() { 

  EstablishConnection();
  float fTemp; 
  DS18B20.requestTemperatures(); 
  fTemp = DS18B20.getTempCByIndex(0); 
  Serial.printf("Current temperature is %s and  %.1f Degrees - ", tempRun(fTemp), fTemp); 
  delay(5000); 
} 

