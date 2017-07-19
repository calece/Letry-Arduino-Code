int leftIRSensor = A0;
int rightIRSensor = A1;
int dir1 = 12;
int dir2 = 11;
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
  if (leftSensorValue < 100 && rightSensorValue < 100)
  {
    analogWrite(pwm1, 200);
    analogWrite(pwm2, 200);
  }
  else if (leftSensorValue > 200 && rightSensorValue < 100)
  {
    analogWrite(pwm1, 0);
    analogWrite(pwm2, 200);
  }
  else if (leftSensorValue < 100 && rightSensorValue > 200)
  {
    analogWrite(pwm1, 200);
    analogWrite(pwm2, 0);
  }  
  }
    
