int leftIRSensor = A0;
int rightIRSensor = A1;
int blueLED = 13;
int redLED = 2;
int photoSensor = A4;
bool blueOn = false;
int dir1 = 12;
int dir2 = 11;
int pwm1 = 10;
int pwm2 = 9;
bool isRunning = false;

void setup() {
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int leftSensorValue = analogRead(leftIRSensor);
  int rightSensorValue = analogRead(rightIRSensor);
  int photoValue = analogRead(photoSensor);

  Serial.println(String(photoValue));
  Serial.println("Left Sensor: " + String(leftSensorValue));
  Serial.println("Right Sensor: " + String(rightSensorValue));
  if (leftSensorValue < 100 && rightSensorValue < 100)
  {
    analogWrite(pwm1, 200);
    analogWrite(pwm2, 200);
  }
  else if (leftSensorValue > 200 && rightSensorValue < 200)
  {
    analogWrite(pwm1, 0);
    analogWrite(pwm2, 200);
  }
  else if (leftSensorValue < 200 && rightSensorValue > 200)
  {
    analogWrite(pwm1, 200);
    analogWrite(pwm2, 0);
  }  
  if(photoValue < 70)
  {
    if(blueOn)
    {
      blueOn = !blueOn;
      digitalWrite(blueLED, LOW);
      digitalWrite(redLED, HIGH);
      delay(100);
    }
    else
    {
      blueOn = !blueOn;
      digitalWrite(blueLED, HIGH);
      digitalWrite(redLED, LOW);
      delay(100);
    }
  }
  else
  {
    digitalWrite(blueLED, LOW);
    digitalWrite(redLED, LOW);
  }
}
