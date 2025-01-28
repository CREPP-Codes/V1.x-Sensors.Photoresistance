/*
 * This program is free software; you can redistribute it and/or
 * modify without any restriction
 */

/*
 *   Libraries
 */
#include <Arduino.h>
#include <SPI.h>
#include "Adafruit_ADS1X15.h"

#include "CREPP_I2C_Scanner.h"
#include "CREPP_ADS1115.h"

Adafruit_ADS1115 ads;

void setup() 
{
  
  Serial.begin(9600);       //Baudrate 
  I2C_Scan();

  bool status_ADS = ads.begin(0x49);  

  if (!status_ADS) 
  {
    Serial.println("Could not find a valid ADS1115 sensor, check wiring!");
  }

  //ADS1115_Init(0x49);



 
}

void loop() 
{
  uint16_t adc0 = ads.readADC_SingleEnded(0);
  
  Serial.print("Raw value : ");
  Serial.print(adc0);
  Serial.print("/65536");
  Serial.print(" --> ");
  if(adc0 > 17000)
  {
    Serial.println("Night");
  }
  else
  {
    Serial.println("Day");
  }

  /*
  uint16_t raw_value = ADS1115_Get_Channel_0();
  Serial.print("Raw value : ");
  Serial.print(raw_value);
  Serial.print("/65536");
  Serial.print(" --> ");
  if(raw_value > 17000)
  {
    Serial.println("Night");
  }
  else
  {
    Serial.println("Day");
  }
  */

  





  delay(200);


}
