/* Water Level Meter */

// Pin definitions
#define TRIGGER 12
#define ECHO 11


//Constants
float CONTAINER_HEIGHT = 20;

// Variables
float t = 0, distance = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT); 
}

void loop()
{
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(2);
  t = pulseIn(ECHO, HIGH);
  distance = t * 340 / 20000;
  float level = CONTAINER_HEIGHT - distance;
  Serial.println(level);
  delay(500);
}
