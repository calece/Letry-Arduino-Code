/*
  Analog Input
 Demonstrates analog input by reading an analog sensor on analog pin 0 and
 turning on and off a light emitting diode(LED)  connected to digital pin 13.
 The amount of time the LED will be on and off depends on
 the value obtained by analogRead().

 The circuit:
 * Potentiometer attached to analog input 0
 * center pin of the potentiometer to the analog pin
 * one side pin (either one) to ground
 * the other side pin to +5V
 * LED anode (long leg) attached to digital output 13
 * LED cathode (short leg) attached to ground

 * Note: because most Arduinos have a built-in LED attached
 to pin 13 on the board, the LED is optional.


 Created by David Cuartielles
 modified 30 Aug 2011
 By Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/AnalogInput

 */
int ledPIN = 12;
int dir1 = 10;
int dir2 = 9;
int pwm1 = 8;
int pwm2 = 7;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPIN, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
}

void loop() {

  digitalWrite(ledPIN, HIGH);
  analogWrite(pwm1, 200);
  analogWrite(pwm2, 200);
  delay(5000);
  digitalWrite(ledPIN, LOW);
  analogWrite(pwm1, 200);
  analogWrite(pwm2, 0);
  delay(3700);
  
  
  
}
