/* Water Level Meter */

// Pin definitions
int trig = 12;
int echo = 11;


//Constants
float CONTAINER_HEIGHT = 20;

// Variables
float t = 0, distance = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT); 
}

void loop()
{
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  t = pulseIn(echo, HIGH);
  distance = t * 340 / 20000;
  float level = CONTAINER_HEIGHT - distance;
  Serial.println(level);
  delay(1000);
}
