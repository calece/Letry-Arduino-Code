int sensorPin = A0;
int sensorValue = 0;
int ledPin = 13;
int dir1 = 12;
int dir2 = 11;
int pwm1 = 10;
int pwm2 = 9;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  if(sensorValue < 100)
  {
  digitalWrite(ledPin, HIGH);
  analogWrite(pwm1, 128);
  analogWrite(pwm2, 128);
  }
  else
  {
  digitalWrite(ledPin, LOW);
  analogWrite(pwm1, 255);
  analogWrite(pwm2, 255);
  }
  
  
  
}
