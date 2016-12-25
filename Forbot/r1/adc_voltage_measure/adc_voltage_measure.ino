void setup() {
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(A5);
  float voltage= val * (5.0 / 1023.0);
  Serial.println(voltage);
  delay(200);
}
