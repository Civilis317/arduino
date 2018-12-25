const int sensorPin = A0;
const float baselineTemp = 22.0;
const int greenLed = 2;
const int yellowLed = 3;
const int redLed = 4;

void setup() {
  // open serial port for monitoring:
  Serial.begin(9600);

  // init led pins
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);

  // all leds off
  digitalWrite(greenLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(redLed, LOW);
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor value: ");
  Serial.print(sensorVal);

  // convert the ADC reading to voltage
  float voltage = (sensorVal / 1024.0) * 5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);

  // convert the voltage to temperature in degrees
  float temperature = (voltage - .5) * 100;
  Serial.print(", degrees C: ");
  Serial.println(temperature);

  // show temp range using leds:
  if (temperature < baselineTemp) {
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, LOW);
    
  } else if (temperature >= baselineTemp+2 && temperature < baselineTemp+4) {
    digitalWrite(greenLed, HIGH);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, LOW);
    
  } else if (temperature >= baselineTemp+4 && temperature < baselineTemp+6) {
    digitalWrite(greenLed, HIGH);
    digitalWrite(yellowLed, HIGH);
    digitalWrite(redLed, LOW);
    
  } else if (temperature >= baselineTemp+6) {
    digitalWrite(greenLed, HIGH);
    digitalWrite(yellowLed, HIGH);
    digitalWrite(redLed, HIGH);
    
  }

  delay(1);

}
