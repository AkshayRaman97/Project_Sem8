/* Imports */
#include <OneWire.h>
#include <DallasTemperature.h>


/* Pin definitions*/
// Level Sensor
#define TRIGGER 12
#define ECHO 11
// Temperature Sensor
#define ONE_WIRE_BUS 5

/* Constants */
const float CONTAINER_HEIGHT = 20; // in cm

/*Variables*/
// Level Sensor
float time_ = 0;
float distance = 0;
float level = 0;
// Temperature Sensor
float Celcius=0;
float Fahrenheit=0;

// Temperature Sensor object
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature temp_sensor(&oneWire);


void setup() {
  // Setting pin modes
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);

  temp_sensor.begin();
  
  Serial.begin(9600);
}

void loop() {
  // Level sensor
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(2);
  time_ = pulseIn(ECHO, HIGH);
  distance = time_ * 340 / 20000;
  float level = CONTAINER_HEIGHT - distance;
  // Temperature sensor
  temp_sensor.requestTemperatures(); 
  Celcius = temp_sensor.getTempCByIndex(0);
  Fahrenheit = temp_sensor.toFahrenheit(Celcius);

  Serial.print(level);
  Serial.print(" cm ");
  Serial.print(Celcius);
  Serial.print(" C  ");
  Serial.print(Fahrenheit);
  Serial.print(" F  ");
  Serial.print("\n");
  delay(1000);

}
