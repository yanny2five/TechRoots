// Class 10 - 4 LED Dice (STEADY patterns, uses all LEDs)
// LEDs: 3,4,5,6 (each -> resistor -> LED -> GND)
// Button: 2 -> GND (INPUT_PULLUP)

const int buttonPin = 2;
const int L1 = 3;
const int L2 = 4;
const int L3 = 5;
const int L4 = 6; // this one was "ignored" before

unsigned long lastPress = 0;

void clearLEDs() {
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
  digitalWrite(L3, LOW);
  digitalWrite(L4, LOW);
}

void showDice(int n) {
  clearLEDs();

  switch (n) {
    case 1:
      digitalWrite(L4, HIGH);
      break;

    case 2:
      digitalWrite(L1, HIGH);
      digitalWrite(L4, HIGH);
      break;

    case 3:
      digitalWrite(L1, HIGH);
      digitalWrite(L2, HIGH);
      digitalWrite(L4, HIGH);
      break;

    case 4:
      digitalWrite(L1, HIGH);
      digitalWrite(L2, HIGH);
      digitalWrite(L3, HIGH);
      digitalWrite(L4, HIGH);
      break;

    case 5:
      digitalWrite(L2, HIGH);
      digitalWrite(L3, HIGH);
      digitalWrite(L4, HIGH);
      break;

    case 6:
      digitalWrite(L1, HIGH);
      digitalWrite(L2, HIGH);
      digitalWrite(L3, HIGH);
      break;
  }
}

bool pressed() {
  if (digitalRead(buttonPin) == LOW && millis() - lastPress > 250) {
    lastPress = millis();
    return true;
  }
  return false;
}

void setup() {
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);
  randomSeed(analogRead(A0));
}

void loop() {
  if (pressed()) {

    // rolling animation (fast changing patterns)
    for (int i = 0; i < 12; i++) {
      showDice(random(1, 7));
      delay(80);
    }

    // final roll (steady)
    int roll = random(1, 7);
    showDice(roll);

    delay(1500);
    clearLEDs();
  }
}
