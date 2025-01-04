#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

unsigned long long valoare = 0;
bool sensIncrementare = true;
bool incrementatDeja = false;

const int pinSemn = 2;
const int pinIncrementare = 3;
const int pinResetare = 4;

void setup() {
  pinMode(pinSemn, INPUT);
  pinMode(pinIncrementare, INPUT);
  pinMode(pinResetare, INPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print(" *ROSTOVEECTOR*");
  lcd.setCursor(0, 1);
  lcd.print("0");
}

void loop() {
  bool starePinSemn = digitalRead(pinSemn);
  bool starePinIncrementare = digitalRead(pinIncrementare);
  bool starePinResetare = digitalRead(pinResetare);

  sensIncrementare = (starePinSemn == HIGH);

  if (starePinIncrementare == HIGH && !incrementatDeja) {
    if (sensIncrementare) {
      valoare = (valoare + 1) % 10000000000000000ULL;
    } else {
      valoare = (valoare == 0) ? 9999999999999999ULL : valoare - 1;
    }
    lcd.setCursor(0, 1);
    char buffer[21];
    sprintf(buffer, "%-16llu", valoare);
    lcd.print(buffer);
    lcd.print(" ");
    incrementatDeja = true;
  } else {
    incrementatDeja = false;
  }

  if (starePinResetare == HIGH) {
    valoare = 0;
    lcd.setCursor(0, 1);
    lcd.print("0               ");
  }
}
