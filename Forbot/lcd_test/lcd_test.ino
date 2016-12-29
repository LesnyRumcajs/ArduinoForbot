#include <LiquidCrystal.h>

LiquidCrystal lcd(2,3,4,5,6,7);

void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Hello");
  lcd.setCursor(0,1);
  lcd.print("World!");
}

void loop() {
  lcd.setCursor(0,0);
  for (int i(0) ;  i < 16 ; ++i)
  {
    lcd.clear();
    lcd.setCursor(i,0);
    lcd.print(">");
    delay(100);
  }

  lcd.print("v");
  delay(100);
  lcd.setCursor(15,0);
  lcd.print("v");
  delay(100);
  for (int i(15) ; i >= 0; --i)
  {
    lcd.clear();
    lcd.setCursor(i,1);
    lcd.print("<");
    delay(100);
  }

  lcd.print("^");
  delay(100);
}
