// Automatic Irrigation System
// Potentiometer as Soil Moisture Sensor

const int sensorPin = A0;
const int motorPin = 8;
const int threshold = 500;

void setup() {
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin);

  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);

  if (sensorValue < threshold) {
    digitalWrite(motorPin, HIGH);   // Pump ON
    Serial.println("Soil Dry - Pump ON");
  } else {
    digitalWrite(motorPin, LOW);    // Pump OFF
    Serial.println("Soil Wet - Pump OFF");
  }

  delay(500);
}