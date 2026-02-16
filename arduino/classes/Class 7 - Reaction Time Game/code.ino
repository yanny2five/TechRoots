// Class 8 - Reaction Time Game

const int ledPin = 9;
const int buttonPin = 2;

unsigned long ledOnTime = 0;
bool waitingForPress = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {

  // random delay before LED turns on
  int randomDelay = random(2000, 5000);
  delay(randomDelay);

  digitalWrite(ledPin, HIGH);
  ledOnTime = millis();
  waitingForPress = true;

  // wait for button press
  while (waitingForPress) {
    if (digitalRead(buttonPin) == LOW) {
      unsigned long reactionTime = millis() - ledOnTime;
      Serial.print("Reaction Time: ");
      Serial.print(reactionTime);
      Serial.println(" ms");

      digitalWrite(ledPin, LOW);
      waitingForPress = false;
      delay(2000);
    }
  }
}
