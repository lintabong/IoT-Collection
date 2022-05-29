#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

//initiate variable
int s1;
int s2;
float distance = 11;
float velocity;
unsigned int ct = 0;
unsigned long t0;
unsigned long t1;
unsigned long t2;

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  s1 = digitalRead(6);
  if (s1 == 0){
    ct++;
    tone(11, 1000);
    t0 = millis();
    for (int i = 0 ; i <= 1000; i++){
      s2 = digitalRead(7);
      if (s2 == 0){
        t1 = millis();
        break;
      }
      delay(100);
    }
    lcd.clear();
  }
  noTone(11);
  t2 = abs(t1 - t0);
  velocity = distance/(t2*0.1);
  displayLCD();
  delay(10);
}

void displayLCD(){
  lcd.setCursor(0,0);
  lcd.print("mobil: ");
  lcd.setCursor(0,1);
  lcd.print("kec  : ");

  lcd.setCursor(7,0);
  lcd.print(ct);
  lcd.setCursor(7,1);
  lcd.print(velocity);

  lcd.setCursor(12,1);
  lcd.print("cm/d");

}
