const int buttonPin = 13;
const int ledPin = 4;

bool ledState = false;        // remembers ON or OFF
bool lastButtonState = HIGH;  // button starts unpressed

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  bool currentButtonState = digitalRead(buttonPin);

  // Detect a NEW button press
  if (lastButtonState == HIGH && currentButtonState == LOW) {
    ledState = !ledState;  // toggle LED state
    delay(200);            // debounce (important)
  }

  digitalWrite(ledPin, ledState ? HIGH : LOW);

  lastButtonState = currentButtonState;
}
