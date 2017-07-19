int sensorPin = A0;
int ledPin = 13;
int sensorValue = 0;
 
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}
 
void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  if(sensorValue < 300)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
}

