#include <Wire.h>				// I2C 통신을 위한 기본 라이브러리
#include <LiquidCrystal_I2C.h>	// I2C LCD 라이브러리

#define TRIG 13 // TRIG Pin
#define ECHO 12 // ECHO Pin

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  lcd.init();
  lcd.backlight();
  lcd.print("LCD init");
  delay(2000);
  lcd.clear();
}

void loop()
{

  long duration, distance;
  delayMicroseconds(2); //delay(2)
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  duration = pulseIn(ECHO, HIGH);
  
  distance = duration / 58.2;

  lcd.setCursor(16,0);

  Serial.println(duration);
  lcd.print("Distance : ");
  lcd.print(distance);
  lcd.println(" cm");
  delay(1000); // Wait for 1000 millisecond(s)
 
  for (int position = 0; position < 16; position++) {
    lcd.scrollDisplayLeft();
    delay(150);
  }
}

