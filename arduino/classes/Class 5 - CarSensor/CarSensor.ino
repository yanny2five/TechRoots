#include <Servo.h>

// Ultrasonic
const int trigPin = 9;
const int echoPin = 10;

// LEDs
const int greenLED = 3;
const int yellowLED = 5;
const int redLED = 6;

// Buzzer
const int buzzerPin = 2;

// Servo
const int servoPin = 13;
Servo landingServo;

int servoAngle = 0;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  landingServo.attach(servoPin);
  landingServo.write(servoAngle);

  Serial.begin(9600);
}

void loop() {
  // Ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 25000);
  int distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Reset outputs
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW);
  digitalWrite(buzzerPin, LOW);

  int stepSize = 1;
  int stepDelay = 40; // slow by default

  if (distance > 50) {
    digitalWrite(greenLED, HIGH);
    stepSize = 1;   // slow
    stepDelay = 40;
  } else if (distance > 20) {
    digitalWrite(yellowLED, HIGH);
    stepSize = 3;   // medium
    stepDelay = 20;
  } else if (distance > 0) {
    digitalWrite(redLED, HIGH);
    digitalWrite(buzzerPin, HIGH);
    stepSize = 6;   // fast
    stepDelay = 8;
  }

  // Move servo (faster when closer)
  servoAngle += stepSize;
  if (servoAngle > 90) servoAngle = 0;

  landingServo.write(servoAngle);
  delay(stepDelay);
}
