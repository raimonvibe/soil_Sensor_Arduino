const int analogPin = A0; // Analoge pin voor vochtigheid
const int digitalPin = 2; // Digitale pin voor drempelwaarde (D0)
const int greenLED = 9;   // Groene LED
const int blueLED = 6;    // Blauwe LED
const int redLED = 5;     // Rode LED
const int yellowLED = 3;  // Gele LED
const int buzzer = 10;    // Buzzer

void setup() {
  Serial.begin(9600);
  pinMode(digitalPin, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int analogValue = analogRead(analogPin);
  int digitalValue = digitalRead(digitalPin);

  Serial.print("Analoge waarde (vochtigheid): ");
  Serial.println(analogValue);
  Serial.print("Digitale waarde (drempelstatus): ");
  Serial.println(digitalValue);

  // LED en buzzer logica
  if (analogValue > 700) { // Droge grond
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(blueLED, LOW);
    digitalWrite(greenLED, LOW);
    tone(buzzer, 1000); // Buzzer aan met 1 kHz
  } else if (analogValue > 300 && analogValue <= 700) { // Matig vochtige grond
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(blueLED, LOW);
    digitalWrite(greenLED, LOW);
    noTone(buzzer); // Buzzer uit
  } else { // Nat
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(blueLED, HIGH); // Blauwe LED aan voor natte grond
    digitalWrite(greenLED, HIGH);
    noTone(buzzer); // Buzzer uit
  }

  delay(1000); // Wacht 1 seconde
}
