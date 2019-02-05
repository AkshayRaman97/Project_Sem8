/* TEMPERATURE SENSOR DS18B20 */

// Libraries
#include <OneWire.h>
#include <DallasTemperature.h>

// Temperature sensor input
#define ONE_WIRE_BUS 2

// Sensor object
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature temp_sensor(&oneWire);

// Temperature values
float Celcius=0;
float Fahrenheit=0;

void setup(void)
{
  
  Serial.begin(9600);

// Begin sensing temp
  temp_sensor.begin();
}

void loop(void)
{ 
  temp_sensor.requestTemperatures(); 
  Celcius=temp_sensor.getTempCByIndex(0);
  Fahrenheit=temp_sensor.toFahrenheit(Celcius);
  Serial.print(" C  ");
  Serial.print(Celcius);
  Serial.print(" F  ");
  Serial.println(Fahrenheit);
  delay(1000);
}
