int leftIRSensor = A0;
int rightIRSensor = A1;
int dir1 = 12; //Left Wheel Reverse
int dir2 = 11; //Right Wheel Reverse
int pwm1 = 10; //Left Wheel
int pwm2 = 9; //Right Wheel

void setup() {
  pinMode(leftIRSensor, INPUT);
  pinMode(rightIRSensor, INPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);

  Serial.begin(9600);

}

void loop() {
  int leftSensorValue = analogRead(leftIRSensor);
  int rightSensorValue = analogRead(rightIRSensor);
  analogWrite(pwm1, 255);
  analogWrite(pwm2, 255);
  Serial.println(leftSensorValue);
  Serial.println(rightSensorValue);
  if(leftSensorValue > 200 && rightSensorValue < 100)//Left side of Letry detects edge, spin right motor in reverse.
  {
    digitalWrite(dir2, HIGH);
    while(leftSensorValue > 100)
    {
      leftSensorValue = analogRead(leftIRSensor);
      rightSensorValue = analogRead(rightIRSensor);
    }
    delay(300);
    digitalWrite(dir2, LOW);    
  }
  else if(rightSensorValue > 200 && leftSensorValue < 100)//Right side of Letry detects edge, spin left motor in reverse.
  {
    digitalWrite(dir1, HIGH);
    while(rightSensorValue > 100)
    {
      leftSensorValue = analogRead(leftIRSensor);
      rightSensorValue = analogRead(rightIRSensor);
    }
    delay(400);
    digitalWrite(dir1, LOW);    
  }
  digitalWrite(dir1, LOW);
  digitalWrite(dir2, LOW);
  
}
