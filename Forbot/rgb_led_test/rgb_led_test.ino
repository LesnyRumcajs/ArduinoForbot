#define RGB_R_PIN 3
#define RGB_G_PIN 5
#define RGB_B_PIN 6

struct rgb {
  short r;
  short g;
  short b;

  rgb() : r(0), g(0), b(0) {}
};

void changeColor(const rgb& xRGB)
{
  analogWrite(RGB_R_PIN, xRGB.r);
  analogWrite(RGB_G_PIN, xRGB.g);
  analogWrite(RGB_B_PIN, xRGB.b);
}

void setup() {
  pinMode(RGB_R_PIN, OUTPUT);
  pinMode(RGB_G_PIN, OUTPUT);
  pinMode(RGB_B_PIN, OUTPUT);

  randomSeed(analogRead(A5));
}

void loop() {
  rgb xRGB;
  short randomBlue = random(255);
  for (int i = 0; i < 255; ++i, delay(10))
  {
    xRGB.r = i;
    xRGB.g = 255 - i;
    xRGB.b = randomBlue;
    changeColor(xRGB);
  }

  for (int i = 255; i > 0; --i, delay(10))
  {
    xRGB.r = i;
    xRGB.g = 255 - i;
    xRGB.b = randomBlue;
    changeColor(xRGB);
  }
}
