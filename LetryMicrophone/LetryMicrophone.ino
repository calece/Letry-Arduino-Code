int micPin = A2;
int dir1 = 12;
int dir2 = 11;
int pwm1 = 10;
int pwm2 = 9;
int lowestVal = 1000;
int sampleTime = 50;
void setup() {
  Serial.begin(9600);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
}

void loop() {
  int startMillis = millis();
  int micValue = analogRead(micPin);
  
  if(micValue < lowestVal)
  {
    lowestVal = micValue;
  }
  Serial.print("Current value: ");
  Serial.println(micValue);
//  Serial.print("Lowest value: ");
//  Serial.println(lowestVal);
  
}
