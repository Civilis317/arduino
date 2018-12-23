int interval = 180;
int potMeterPin = 0; 
int potMeterValue;

void setup() {
  for (int outPin = 9; outPin < 14; outPin++) {
    pinMode(outPin, OUTPUT);
  }

}

void loop() {
  for (int pin = 9; pin < 13; pin++) {
    fireLed(pin);
  }

  for (int pin = 13; pin > 9; pin--) {
    fireLed(pin);
  }

}

void fireLed(int pin) {
  potMeterValue = analogRead(potMeterPin);

  digitalWrite(pin, HIGH);
  delay(potMeterValue);
  digitalWrite(pin, LOW);
}
