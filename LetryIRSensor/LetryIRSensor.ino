int leftIRSensor = A1;
int rightIRSensor = A0;

int dir1 = 12;
int dir2 = 11;
int pwm1 = 10;
int pwm2 = 9;
bool isRunning = false;
int lowestValue = 1000;

void setup() {
  pinMode(leftIRSensor, INPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);  
  Serial.begin(9600);
}

void loop() {
  int leftSensorValue = analogRead(leftIRSensor);
  int rightSensorValue = analogRead(rightIRSensor);

  if(leftSensorValue < 100 && rightSensorValue < 100)
  {
    analogWrite(pwm1, 255);
    analogWrite(pwm2, 255);
  }
  else if(leftSensorValue > 200 && rightSensorValue < 100)
  {
    analogWrite(pwm1, 0);
    analogWrite(pwm2, 255);
  }
  else if(leftSensorValue < 100 && rightSensorValue > 200)
  {
    analogWrite(pwm1, 255);
    analogWrite(pwm2, 0);
  }
  
  Serial.println(leftSensorValue);
  Serial.println(rightSensorValue);
}
