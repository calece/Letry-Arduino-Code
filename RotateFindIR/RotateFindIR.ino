int leftReverse = 12;
int rightReverse = 11;
int leftMotor = 10;
int rightMotor = 9;
int irPin = A0;
int rotationTime = 1600;//milliseconds
int degreeTime = 444;//microseconds
int degreeIRValue[360];
int IRValue = 0;
int currentDegree = 0;

void setup() {
  pinMode(leftMotor, OUTPUT);
  pinMode(rightMotor, OUTPUT);
  pinMode(leftReverse, OUTPUT);
  pinMode(rightReverse, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  getDegreeValue();
  int lowest = 1000;
  int degree = 0;
  for(int i = 0; i < 360; i++)
  {
    Serial.println(String(i) + " degree IR Average: " + String(degreeIRValue[i]));
    if(degreeIRValue[i] < lowest)
    {
      lowest = degreeIRValue[i];
      degree = i;
    }
  }
  Serial.println("Lowest IR Value (" + String(lowest) + ") found at " + String(degree) + " degrees");
  delay(3000);
  
 
}

void getDegreeValue()
{  
  currentDegree = 0;
  int timeElapsed = 0;  
  do
  {
    analogWrite(leftMotor, 255);
    analogWrite(rightMotor, 255);
    digitalWrite(rightReverse, HIGH);
    int timeBegin = millis();   
    int timeDegreeElapsed = 0;    
    int flops = 0;
    IRValue = 0;
    do
    {
      analogWrite(leftMotor, 255);
      analogWrite(rightMotor, 255);  
      digitalWrite(rightReverse, HIGH);
      int timeDegreeBegin = micros();
      flops++;
      IRValue += analogRead(irPin);
      if(IRValue < 300)
      {
        digitalWrite(rightReverse, LOW);
        delay(400);
        analogWrite(leftMotor, 0);
        analogWrite(rightMotor, 0);
        return;
      }
      timeDegreeElapsed = timeDegreeElapsed + (micros() - timeDegreeBegin);      
    }while(timeDegreeElapsed < degreeTime);
    IRValue = IRValue / flops;
    degreeIRValue[currentDegree] = IRValue;
    currentDegree = (currentDegree + 1) % 360;
    timeElapsed = timeElapsed + (millis() - timeBegin);
  }while(timeElapsed < rotationTime);
  
    analogWrite(leftMotor, 0);
    analogWrite(rightMotor, 0);
    digitalWrite(rightReverse, LOW);
}
