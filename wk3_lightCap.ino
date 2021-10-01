int analogInpin = A9;
int analogOutpin = 10;

int outputValue = 0;
int sensorValue = 0;
int reverseValue = 0;

int threshold = 800;

void setup() {
  // put your setup code here, to run once:
  pinMode(analogOutpin, OUTPUT);
  pinMode(analogInpin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //read the analog in value
  sensorValue = analogRead(analogInpin);
  if (sensorValue < threshold){
    //map it to the range og the anlog output
    reverseValue = map(sensorValue, 0, 1023, 0 , 255);
    outputValue = 255 - reverseValue;
  }
  else{
    outputValue = 0;
  }
  // change the analog out value
  analogWrite(analogOutpin,outputValue);

  //print the results to the Serial Monitor;
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.print(outputValue);

  delay(2);
}
