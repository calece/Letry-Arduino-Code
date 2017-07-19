int lightSensor = A0;
int sensorValue = 0;
int ledRedPin = 13;
int ledBluePin = 2;
int dir1 = 10;
int dir2 = 9;
int pwm1 = 8;
int pwm2 = 7;


void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledRedPin, OUTPUT);
  pinMode(ledBluePin, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
}

void loop() {
  sensorValue = analogRead(lightSensor);
  if(sensorValue < 500)
  {
  if(millis() % 1000 > 500)
  {
    digitalWrite(ledRedPin, HIGH);
    digitalWrite(ledBluePin, LOW);
  }
  else
  {
    digitalWrite(ledRedPin, LOW);
    digitalWrite(ledBluePin, HIGH);
  }
  analogWrite(pwm1, 128);
  analogWrite(pwm2, 128);
  }
  else
  {
  digitalWrite(ledRedPin, LOW);
  digitalWrite(ledBluePin, LOW);
  analogWrite(pwm1, 255);
  analogWrite(pwm2, 255);
  }
  
  
  
}
