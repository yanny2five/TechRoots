const int lightPin = A0;
const int ledPin = 8;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lightValue = analogRead(lightPin);
  Serial.println(lightValue);

  if (lightValue > 700) {   // DARK
    digitalWrite(ledPin, HIGH
    );
  } else {                  // BRIGHT
    digitalWrite(ledPin, LOW);
  }

  delay(200);
}
