#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <SD.h>

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
File myFile;

#define sensorCo A0

int readCo;
int mapCo;

int det = 0;
int men = 0;
int jam = 0;

String myClock;
String sdet = "00";
String smen = "00";
String sjam = "00";

void setup() {
    Serial.begin(9600);
    lcd.init();
    lcd.backlight();
    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("setting up...");
    delay(1000);
    if (!SD.begin(4)){
      lcd.setCursor(0,1);
      lcd.print("SD card failed");
      while (1);
    }
    lcd.setCursor(0,1);
    lcd.print("Setting complete");
    delay(1500);
    lcd.clear();
}

void loop() {
    readCo = analogRead(sensorCo);
    mapCo = map(readCo, 0,1023,0,100);
    runClock();
    lcdPrint();

    myFile = SD.open("mydata.txt", FILE_WRITE);
    myFile.print(myClock);
    myFile.print("\t");
    myFile.print(mapCo);
    myFile.println(" %");
    myFile.close();
        
    Serial.print(myClock);
    Serial.print("\t");
    Serial.print(mapCo);
    Serial.println(" %");
  
    delay(1000);
}

void runClock(){
    det++;

    if (det == 60){
      det = 0;
      men++;
    }

    if (men == 60){
      det = 0;
      men = 0;
      jam++;
    }
    
  
    if (det <= 9){
      sdet = "0" + String(det);
    } else {
      sdet = String(det);
    }

    if (men <= 9){
      smen = "0" + String(men);
    } else {
      smen = String(men);
    }

    if (jam <= 9){
      sjam = "0" + String(jam);
    } else {
      sjam = String(jam);
    }
    myClock = sjam + ":" + smen + ":" + sdet;
}

void lcdPrint(){
    lcd.setCursor(0,0);
    lcd.print("Co: ");

    if (mapCo <= 9){
        lcd.setCursor(5,0);
        lcd.print(" ");
        lcd.setCursor(6,0);
        lcd.print(mapCo);
    } else {
        lcd.setCursor(5,0);
        lcd.print(mapCo);
    }
    lcd.setCursor(8,0);
    lcd.print(" %");
    
    lcd.setCursor(0,1);
    lcd.print(myClock);
}
