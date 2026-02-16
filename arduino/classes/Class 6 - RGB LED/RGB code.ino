
const int PIN_R = 9;
const int PIN_G = 10;
const int PIN_B = 11;

void setRGB(int r, int g, int b) {
  // For common-cathode RGB LED:
  analogWrite(PIN_R, r);
  analogWrite(PIN_G, g);
  analogWrite(PIN_B, b);
}

void setup() {
  pinMode(PIN_R, OUTPUT);
  pinMode(PIN_G, OUTPUT);
  pinMode(PIN_B, OUTPUT);
}

void loop() {
  // Smooth color cycle (fade through rainbow-ish colors)

  for (int i = 0; i <= 255; i += 5) { setRGB(255, i, 0); delay(20); }   // red -> yellow
  for (int i = 255; i >= 0; i -= 5) { setRGB(i, 255, 0); delay(20); }  // yellow -> green
  for (int i = 0; i <= 255; i += 5) { setRGB(0, 255, i); delay(20); }  // green -> cyan
  for (int i = 255; i >= 0; i -= 5) { setRGB(0, i, 255); delay(20); }  // cyan -> blue
  for (int i = 0; i <= 255; i += 5) { setRGB(i, 0, 255); delay(20); }  // blue -> purple
  for (int i = 255; i >= 0; i -= 5) { setRGB(255, 0, i); delay(20); }  // purple -> red
}
