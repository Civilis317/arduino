int switchState = 0;
int greenLed = 3;
int yellowLed = 4;
int redLed = 5;
int buttonState = 2;

void setup() {
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(buttonState, INPUT);
}

void loop() {
  switchState = digitalRead(buttonState);

  if (switchState == LOW) {
    // button not pressed
    digitalWrite(greenLed, HIGH);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, LOW);
  } else {
    // button is pressed
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, HIGH);
    delay(250);

    digitalWrite(yellowLed, HIGH);
    digitalWrite(redLed, LOW);
    delay(250);
  }

}
