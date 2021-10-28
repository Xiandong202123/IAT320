int input1 = 12;
int input2 = 6;

int led1 = 9;//RED
int led2 = 10;//GREEN
int buzzer = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(input1, INPUT);
  pinMode(input2, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(input1) == HIGH){
    Serial.print("input1");
    digitalWrite(led1, HIGH);
    tone(buzzer, 2000);
    delay(1000);
    noTone(buzzer);
    digitalWrite(led1, LOW);
  }
  if(digitalRead(input2) == HIGH){
    Serial.print("input2");
    digitalWrite(led2, HIGH);
    delay(1000);
    digitalWrite(led2, LOW);
  }
}
