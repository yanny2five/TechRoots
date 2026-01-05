const int trigPin   = 9;
const int echoPin   = 10;
const int buzzerPin = 5;
const int ledPin    = 2;   // NEW LED on pin 2

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo (with timeout)
  long duration = pulseIn(echoPin, HIGH, 25000);
  if (duration == 0) return;

  int distance = duration / 58; // cm
  Serial.println(distance);

  // ONLY activate when close
  if (distance < 30) {
    distance = constrain(distance, 5, 30);

    // Closer → faster blinking/beeping
    int delayTime = map(distance, 5, 30, 50, 400);

    // LED + buzzer ON
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
    delay(delayTime);

    // LED + buzzer OFF
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
    delay(delayTime);

  } else {
    // Far away → everything OFF
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
    delay(100);
  }
}
