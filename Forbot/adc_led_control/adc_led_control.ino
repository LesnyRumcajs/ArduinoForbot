#define ADC_PHOTORESISTOR_PORT  A5
#define ADC_ADJUSTMENT_PORT     A4
#define LED_OUTPUT_PORT         7

int _light_val(0);
int _threshold(0);

void setup() {
  pinMode(LED_OUTPUT_PORT, OUTPUT);
  digitalWrite(LED_OUTPUT_PORT, LOW);
}

void loop() {
  _light_val = analogRead(ADC_PHOTORESISTOR_PORT);
  _threshold = analogRead(ADC_ADJUSTMENT_PORT);

  if (_light_val < _threshold)
    digitalWrite(LED_OUTPUT_PORT, HIGH);
  else
    digitalWrite(LED_OUTPUT_PORT, LOW);

  delay(50);
}
