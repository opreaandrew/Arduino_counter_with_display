#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

unsigned long long value = 0;
bool incrementDirection = true;
bool alreadyIncremented = false;

const int signPin = 2;
const int incrementPin = 3;
const int resetPin = 4;

void setup() {
  pinMode(signPin, INPUT);
  pinMode(incrementPin, INPUT);
  pinMode(resetPin, INPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print(" *ROSTOVEECTOR*");
  lcd.setCursor(0, 1);
  lcd.print("0");
}

void loop() {
  bool signPinState = digitalRead(signPin);
  bool incrementPinState = digitalRead(incrementPin);
  bool resetPinState = digitalRead(resetPin);

  incrementDirection = (signPinState == HIGH);

  if (incrementPinState == HIGH && !alreadyIncremented) {
    if (incrementDirection) {
      value = (value + 1) % 10000000000000000ULL;
    } else {
      value = (value == 0) ? 9999999999999999ULL : value - 1;
    }
    lcd.setCursor(0, 1);
    char buffer[21];
    sprintf(buffer, "%-16llu", value);
    lcd.print(buffer);
    lcd.print(" ");
    alreadyIncremented = true;
  } else {
    alreadyIncremented = false;
  }

  if (resetPinState == HIGH) {
    value = 0;
    lcd.setCursor(0, 1);
    lcd.print("0 ");
  }
}