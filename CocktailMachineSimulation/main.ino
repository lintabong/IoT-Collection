#include <LiquidCrystal.h>

#include <Keypad.h>
LiquidCrystal lcd(1, 0, 5, 4, 3, 2);

const byte ROWS = 4;
const byte COLS = 4;
char hexaKeys[ROWS][COLS] = {
  {'1','4','7','*'},
  {'2','5','8','0'},
  {'3','6','9','#'},
  {'A','B','C','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {13, 12, 11, 10};

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

char drink[2];
int state;
unsigned int pay;
unsigned int mustPay;

int a1,a2,a3,a4,a5,a6,a7,a8,a9;
int b1,b2,b3,b4,b5,b6,b7,b8,b9;
int c1,c2,c3,c4,c5,c6,c7,c8,c9;
int d1,d2,d3,d4,d5,d6,d7,d8,d9;

void setup() {
  lcd.begin(16, 2);
  pinMode(A5, OUTPUT); 
  state = 0;
  a1,a2,a3,a4,a5,a6,a7,a8,a9 = 6;
  b1,b2,b3,b4,b5,b6,b7,b8,b9 = 6;
  c1,c2,c3,c4,c5,c6,c7,c8,c9 = 6;
  d1,d2,d3,d4,d5,d6,d7,d8,d9 = 6;
}

void loop() {
  char customKey = customKeypad.getKey();
  
  if (customKey == 'A' || customKey == 'B' || customKey == 'C' || customKey == 'D'){
    lcd.setCursor(0,0);
    lcd.print(customKey);
    drink[0] = customKey;
    for (int i=0; i<1000; i++){
      char customKey = customKeypad.getKey();
      if (customKey == '0' || customKey == '1' || 
          customKey == '2' || customKey == '3' ||
          customKey == '4' || customKey == '5' || 
          customKey == '6' || customKey == '7' ||
          customKey == '8' || customKey == '9' ){
        lcd.setCursor(1,0);
        lcd.print(customKey);
        drink[1] = customKey;
        break;
      }
      delay(200);
    }
  } else if(customKey == '*'){
    drink[0] = ' ';
    drink[1] = ' ';
  } else if(customKey == '#'){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("MONEY:");
    lcd.setCursor(9,0);
    lcd.print("SELECT:");
    lcd.setCursor(0,1);
    lcd.print("Rp");
    lcd.setCursor(14,1);
    lcd.print(drink[0]);
    lcd.print(drink[1]);
    lcd.setCursor(3,1);
    if (drink[0] == 'A'){
      lcd.print("25000");
      mustPay = 25000;
    }
    if (drink[0] == 'B'){
      lcd.print("35000");
      mustPay = 35000;
    }
    if (drink[0] == 'C'){
      lcd.print("40000");
      mustPay = 40000;
    }
    if (drink[0] == 'D'){
      lcd.print("50000");
      mustPay = 50000;
    }
    
    if (drink[0] == 'A' && drink[1] == '1'){
      a1 = a1 - 1;
      if(a1 >= 0){
        payit();
      } else {
        tryot();
      }
    }
    if (drink[0] == 'A' && drink[1] == '2'){
      a2 = a2 - 1;
      if(a2 >= 0){
        payit();
      } else {
        tryot();
      }
    }
    if (drink[0] == 'A' && drink[1] == '3'){
      a3 = a3 - 1;
      if(a3 >= 0){
        payit();
      } else {
        tryot();
      }
    }
    if (drink[0] == 'A' && drink[1] == '4'){
      a4 = a4 - 1;
      if(a4 >= 0){
        payit();
      } else {
        tryot();
      }
    }
    if (drink[0] == 'A' && drink[1] == '5'){
      a5 = a5 - 1;
      if(a5 >= 0){
        payit();
      } else {
        tryot();
      }
    }
    if (drink[0] == 'A' && drink[1] == '6'){
      a6 = a6 - 1;
      if(a6 >= 0){
        payit();
      } else {
        tryot();
      }
    }
    if (drink[0] == 'A' && drink[1] == '7'){
      a7 = a7 - 1;
      if(a7 >= 0){
        payit();
      } else {
        tryot();
      }
    }
    if (drink[0] == 'A' && drink[1] == '8'){
      a8 = a8 - 1;
      if(a8 >= 0){
        payit();
      } else {
        tryot();
      }
    }
    if (drink[0] == 'A' && drink[1] == '9'){
      a9 = a9 - 1;
      if(a9 >= 0){
        payit();
      } else {
        tryot();
      }
    }
    if (drink[0] == 'B' && drink[1] == '1'){
      b1 = b1 - 1;
      if(b1 >= 0){
        payit();
      } else {
        tryot();
      }
    }
    if (drink[0] == 'B' && drink[1] == '2'){
      b2 = b2 - 1;
      if(b2 >= 0){
        payit();
      } else {
        tryot();
      }
    }
    if (drink[0] == 'B' && drink[1] == '3'){
      b3 = b3 - 1;
      if(b3 >= 0){
        payit();
      } else {
        tryot();
      }
    }
    if (drink[0] == 'B' && drink[1] == '4'){
      b4 = b4 - 1;
      if(b4 >= 0){
        payit();
      } else {
        tryot();
      }
    }
    if (drink[0] == 'B' && drink[1] == '5'){
      b5 = b5 - 1;
      if(b5 >= 0){
        payit();
      } else {
        tryot();
      }
    }
    if (drink[0] == 'B' && drink[1] == '6'){
      b6 = b6 - 1;
      if(b6 >= 0){
        payit();
      } else {
        tryot();
      }
    }
    if (drink[0] == 'B' && drink[1] == '7'){
      b7 = b7 - 1;
      if(b7 >= 0){
        payit();
      } else {
        tryot();
      }
    }
    if (drink[0] == 'B' && drink[1] == '8'){
      b8 = b8 - 1;
      if(b8 >= 0){
        payit();
      } else {
        tryot();
      }
    }
    if (drink[0] == 'B' && drink[1] == '9'){
      b9 = b9 - 1;
      if(b9 >= 0){
        payit();
      } else {
        tryot();
      }
    }
    if (drink[0] == 'C' && drink[1] == '1'){
      c1 = c1 - 1;
      if(c1 >= 0){
        payit();
      } else {
        tryot();
      }
    }
    if (drink[0] == 'C' && drink[1] == '2'){
      c2 = c2 - 1;
      if(c2 >= 0){
        payit();
      } else {
        tryot();
      }
    }
    if (drink[0] == 'C' && drink[1] == '3'){
      c3 = c3 - 1;
      if(c3 >= 0){
        payit();
      } else {
        tryot();
      }
    }
    if (drink[0] == 'C' && drink[1] == '4'){
      c4 = c4 - 1;
      if(c4 >= 0){
        payit();
      } else {
        tryot();
      }
    }
    if (drink[0] == 'C' && drink[1] == '5'){
      c5 = c5 - 1;
      if(c5 >= 0){
        payit();
      } else {
        tryot();
      }
    }
    if (drink[0] == 'C' && drink[1] == '6'){
      c6 = c6 - 1;
      if(c6 >= 0){
        payit();
      } else {
        tryot();
      }
    }
    if (drink[0] == 'C' && drink[1] == '7'){
      c7 = c7 - 1;
      if(c7 >= 0){
        payit();
      } else {
        tryot();
      }
    }
    if (drink[0] == 'C' && drink[1] == '8'){
      c8 = c8 - 1;
      if(c8 >= 0){
        payit();
      } else {
        tryot();
      }
    }
    if (drink[0] == 'C' && drink[1] == '9'){
      c9 = c9 - 1;
      if(c9 >= 0){
        payit();
      } else {
        tryot();
      }
    }
    if (drink[0] == 'D' && drink[1] == '1'){
      d1 = d1 - 1;
      if(d1 >= 0){
        payit();
      } else {
        tryot();
      }
    }
    if (drink[0] == 'D' && drink[1] == '2'){
      d2 = d2 - 1;
      if(d2 >= 0){
        payit();
      } else {
        tryot();
      }
    }
    if (drink[0] == 'D' && drink[1] == '3'){
      d3 = d3 - 1;
      if(d3 >= 0){
        payit();
      } else {
        tryot();
      }
    }
    if (drink[0] == 'D' && drink[1] == '4'){
      d4 = d4 - 1;
      if(d4 >= 0){
        payit();
      } else {
        tryot();
      }
    }
    if (drink[0] == 'D' && drink[1] == '5'){
      d5 = d5 - 1;
      if(d5 >= 0){
        payit();
      } else {
        tryot();
      }
    }
    if (drink[0] == 'D' && drink[1] == '6'){
      d6 = d6 - 1;
      if(d6 >= 0){
        payit();
      } else {
        tryot();
      }
    }
    if (drink[0] == 'D' && drink[1] == '7'){
      d7 = d7 - 1;
      if(d7 >= 0){
        payit();
      } else {
        tryot();
      }
    }
    if (drink[0] == 'D' && drink[1] == '8'){
      d8 = d8 - 1;
      if(d8 >= 0){
        payit();
      } else {
        tryot();
      }
    }
    if (drink[0] == 'D' && drink[1] == '9'){
      d9 = d9 - 1;
      if(d9 >= 0){
        payit();
      } else {
        tryot();
      }
    }
  }
  

  digitalWrite(A5, LOW);
  
  lcd.setCursor(0,0);
  lcd.print(drink);
}

void payit(){
    pay = 0;
    for (int i =0; i<=5000;i++){
      
      int read00 = digitalRead(A0);
      int read01 = digitalRead(A1);
      int read02 = digitalRead(A2);
      
      if (read00 == HIGH){
        pay = pay + 20000;
      } else {
        pay = pay;
      }
      if (read01 == HIGH){
        pay = pay + 10000;
      } else {
        pay = pay;
      }
      if (read02 == HIGH){
        pay = pay + 5000;
      } else {
        pay = pay;
      }
      //lcd.print(read00); lcd.print(read01); lcd.print(read02);
      if (pay >=mustPay){
        digitalWrite(A5, HIGH);
        delay(3000);
        lcd.clear();
        delay(1000);
        lcd.setCursor(0,0);
        lcd.print("Selamat Menikmati");
        delay(2000);
        break;
      }
      delay(200);
    }
    lcd.clear();
    drink[0] = ' ';
    drink[1] = ' ';
}

void tryot(){
  lcd.clear();
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print("maaf, item kosong");
  delay(3000);
}
