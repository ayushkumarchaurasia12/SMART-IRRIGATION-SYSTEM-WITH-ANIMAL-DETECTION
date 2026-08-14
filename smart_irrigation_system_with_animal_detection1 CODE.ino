#include <LiquidCrystal.h>

// ===============================
// ORIGINAL PROJECT
// ===============================

const int sensorPin = A0;
const int motorPin = 8;

// LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(7, 6, 5, 4, 3, 9);

const int threshold = 500;


// ===============================
// NEW ANIMAL PROTECTION
// ===============================

const int dayNightPin = A1;
const int pirPin = 10;
const int ledPin = 11;
const int buzzerPin = 2;


void setup()
{
  pinMode(motorPin, OUTPUT);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  lcd.begin(16, 2);

  Serial.begin(9600);

  lcd.print("Plant Watering");
  delay(2000);
  lcd.clear();

  Serial.println("================================");
  Serial.println(" SMART PLANT SYSTEM");
  Serial.println("================================");
}


void loop()
{
  // ===============================
  // SOIL MOISTURE
  // ===============================

  int moisture = analogRead(sensorPin);


  // ===============================
  // PUMP
  // ===============================

  if (moisture < threshold)
  {
    digitalWrite(motorPin, HIGH);
  }
  else
  {
    digitalWrite(motorPin, LOW);
  }


  // ===============================
  // READ POTENTIOMETER
  // ===============================

  int dayNight = analogRead(dayNightPin);


  // ===============================
  // READ PIR
  // ===============================

  int motion = digitalRead(pirPin);


  // ===============================
  // SERIAL MONITOR
  // ===============================

  Serial.print("Moisture: ");
  Serial.print(moisture);

  Serial.print(" | Potentiometer: ");
  Serial.print(dayNight);


  // ===============================
  // NIGHT / DAY
  // ===============================

  if (dayNight < 400)
  {
    Serial.print(" | NIGHT");

    // ===========================
    // PIR ACTIVE AT NIGHT
    // ===========================

    Serial.print(" | PIR: ");

    if (motion == HIGH)
    {
      Serial.print("MOTION");

      digitalWrite(ledPin, HIGH);
      tone(buzzerPin, 1500);

      Serial.println(" | LED: ON | BUZZER: ON");

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("NIGHT ALERT!");
      lcd.setCursor(0, 1);
      lcd.print("ANIMAL DETECTED");

    }
    else
    {
      Serial.println("NO MOTION | LED: OFF | BUZZER: OFF");

      digitalWrite(ledPin, LOW);
      noTone(buzzerPin);
    }
  }
  else
  {
    // ===========================
    // DAY MODE
    // ===========================

    Serial.println(" | DAY | PIR: OFF | LED: OFF | BUZZER: OFF");

    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  }


  // ===============================
  // NORMAL LCD
  // ===============================

  if (!(dayNight < 400 && motion == HIGH))
  {
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Moisture:");
    lcd.print(moisture);

    lcd.setCursor(0, 1);

    if (moisture < threshold)
    {
      lcd.print("Pump: ON");
    }
    else
    {
      lcd.print("Pump: OFF");
    }
  }


  delay(1000);
}