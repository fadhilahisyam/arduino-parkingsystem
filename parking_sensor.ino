#include <LiquidCrystal_I2C.h>

// C++ code
//

const int trigPin = 2;
const int echoPin = 3;
const int ledRed = 4;
const int ledGreen = 5;
const int buzzPin = 6;
LiquidCrystal_I2C lcd(32, 16, 2);
void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(buzzPin, OUTPUT);
  lcd.print("Sensor Parkir");
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  float distance = (duration*0.034/2);
  lcd.setCursor(0, 1);
  lcd.print("Jarak: ");
  lcd.print(distance);
  Serial.println(distance);
  lcd.print("cm");
  
  if (distance <= 25) {
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledGreen, LOW);
    buzzActive1();
  }
  else if (distance >= 25 && distance <= 50) {
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledGreen, HIGH);
    buzzActive2();
  }
  else if (distance >= 50) {
    digitalWrite(ledRed, LOW);
    digitalWrite(ledGreen, HIGH);
    noTone(buzzPin);
  }
  delay(500);
}
void buzzActive1()
{
  digitalWrite(buzzPin, HIGH);
  delay(100);
  digitalWrite(buzzPin, LOW);
  delay(100);
}
void buzzActive2()
{
  digitalWrite(buzzPin, HIGH);
  delay(1000);
  digitalWrite(buzzPin, LOW);
  delay(1000);
}