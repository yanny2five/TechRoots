const int ledPin = 8;
const int buttonPin = 2;

unsigned long startTime;
bool waitingForPress = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);

  Serial.println("Reaction Time Game Ready!");
  delay(1000);
}

void loop() {
  // Step 1: wait random time
  digitalWrite(ledPin, LOW);
  delay(random(2000, 5000));  // 2–5 seconds

  // Step 2: turn LED on
  digitalWrite(ledPin, HIGH);
  startTime = millis();
  waitingForPress = true;

  // Step 3: wait for button press
  while (waitingForPress) {
    if (digitalRead(buttonPin) == LOW) {
      unsigned long reactionTime = millis() - startTime;
      Serial.print("Reaction Time: ");
      Serial.print(reactionTime);
      Serial.println(" ms");

      digitalWrite(ledPin, LOW);
      waitingForPress = false;

      delay(3000);  // pause before next round
    }
  }
}
