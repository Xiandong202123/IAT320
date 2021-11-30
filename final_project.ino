#include <Adafruit_CircuitPlayground.h>
#include <Servo.h>

float value; //variable to read the value from the sound sensor
Servo myservo; //create the servo object
int servoPin = 12;
int degree;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  //pinMode(servoPin, OUTPUT);
  myservo.attach(6);
}

void loop() {
  // Take 10 milliseconds of sound data to calculate
  value = CircuitPlayground.mic.soundPressureLevel(10);
  Serial.println(value);
  
  if(value >= 58){
    //degree = 90;
    //analogWrite(servoPin, degree);
    value = map(value, 58, 63, 0, 180);
    myservo.write(value);
    //Serial.println(value);
  }

  delay(1000);
}
