#include <Arduino.h>

// #define StepperTest
#define GpsTest

#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

char step;
char GpsChar;

#ifdef GpsTest
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available())
  {
    GpsChar = Serial.read();
    Serial.print(GpsChar);
  }
}

#endif

#ifdef StepperTest
void setup()
{
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}
void loop()
{
  step = Serial.read();
  if (step == 'g')
  {
    while (step != 's')
    {
      digitalWrite(IN1, HIGH);
      delay(2);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      delay(2);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      delay(2);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      delay(2);
      digitalWrite(IN4, LOW);
      Serial.println("stepping!");
      step = Serial.read();
    }
  }
}
#endif
