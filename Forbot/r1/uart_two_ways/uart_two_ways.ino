const int OUTPUT_LED = 7;
String dataBuffer;

void setup() {
    pinMode(OUTPUT_LED, OUTPUT);
    digitalWrite(OUTPUT_LED, LOW);
    Serial.begin(9600);
    Serial.println("Setup complete");
}

void loop() {
  if (Serial.available() > 0)
  {
    dataBuffer = Serial.readStringUntil('\n');
    if (dataBuffer == "TURN ON")
      digitalWrite(OUTPUT_LED, HIGH);
    else if (dataBuffer == "TURN OFF")
      digitalWrite(OUTPUT_LED, LOW);
    else
      Serial.println("Unknown command: " + dataBuffer);
  }

  delay(25);
}
