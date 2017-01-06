#include <Adafruit_NeoPixel.h>

#define RGB_CONTROL_PIN A0
#define NO_OF_LEDS 8
#define POWER_MAX 5

Adafruit_NeoPixel xProgLed = Adafruit_NeoPixel(NO_OF_LEDS, RGB_CONTROL_PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  xProgLed.begin();
  xProgLed.show();
}

void loop()
{
  for (int i{0}; i < NO_OF_LEDS; ++i)
  {
    if (i < NO_OF_LEDS / 4)
      xProgLed.setPixelColor(i, xProgLed.Color(POWER_MAX, 0, 0));
    else if (i < 2*NO_OF_LEDS / 4)
      xProgLed.setPixelColor(i, xProgLed.Color(0, 0, POWER_MAX));
    else if (i < 3*NO_OF_LEDS / 4)
      xProgLed.setPixelColor(i, xProgLed.Color(0, POWER_MAX, 0));
    else
      xProgLed.setPixelColor(i, xProgLed.Color(POWER_MAX, POWER_MAX, POWER_MAX));

    xProgLed.show();
    delay(100);
  }

  xProgLed.clear();

  for (int i{NO_OF_LEDS}; i > 0; --i)
  {
    if (i < NO_OF_LEDS / 4)
      xProgLed.setPixelColor(i, xProgLed.Color(POWER_MAX, 0, 0));
    else if (i < 2*NO_OF_LEDS / 4)
      xProgLed.setPixelColor(i, xProgLed.Color(0, 0, POWER_MAX));
    else if (i < 3*NO_OF_LEDS / 4)
      xProgLed.setPixelColor(i, xProgLed.Color(0, POWER_MAX, 0));
    else
      xProgLed.setPixelColor(i, xProgLed.Color(POWER_MAX, POWER_MAX, POWER_MAX));

    xProgLed.show();
    delay(100);
  }

  xProgLed.clear();
}
