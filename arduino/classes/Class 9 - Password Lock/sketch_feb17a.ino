#include <Servo.h>

// Pins
const int SERVO_PIN = 9;
const int BTN1 = 2;
const int BTN2 = 3;

// Servo positions
const int LOCK_POS = 10;
const int UNLOCK_POS = 90;

// Password: 1,2,2,1
const int PASS[4] = {1, 2, 2, 1};

Servo s;
int indexPos = 0;                 // how many correct presses so far
unsigned long lastPress = 0;

void lockIt() { s.write(LOCK_POS); }
void unlockIt() { s.write(UNLOCK_POS); }

int getPress() {
  if (millis() - lastPress < 200) return 0;   // debounce

  if (digitalRead(BTN1) == LOW) { lastPress = millis(); return 1; }
  if (digitalRead(BTN2) == LOW) { lastPress = millis(); return 2; }
  return 0;
}

void setup() {
  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);

  s.attach(SERVO_PIN);
  lockIt();
}

void loop() {
  int p = getPress();
  if (p == 0) return;

  // If correct next input, move forward
  if (p == PASS[indexPos]) {
    indexPos++;

    // If finished all 4 inputs, unlock
    if (indexPos == 4) {
      unlockIt();
      delay(2000);
      lockIt();
      indexPos = 0;   // reset for next time
    }

  } else {
    // Wrong input -> reset immediately
    indexPos = 0;

    // optional "nope" wiggle feedback
    s.write(LOCK_POS + 10); delay(120);
    lockIt(); delay(120);
  }
}
