int valRead(0);

void setup() {
  Serial.begin(9600);

}

float adcToVoltage(unsigned val)
{
  return val*5.0/1023.;
}

void loop() {
  valRead = analogRead(A5);
  Serial.println(adcToVoltage(valRead));
  delay(200);

}
