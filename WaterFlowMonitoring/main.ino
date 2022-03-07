#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "waterflowdb-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "5bj22DBZgXDgzXKkaufsBm2Uo4ajEMXES96PFlrM"
#define WIFI_SSID "Didik"
#define WIFI_PASSWORD "22des*92"

const int SAMPLE_TIME = 1000;
unsigned long millisCurrent;
unsigned long millisLast = 0;
unsigned long millisElapsed = 0;
int count1 = 0;
int count2 = 0;
int count3 = 0;
double flow1;
double flow2;
double flow3;

void setup() {
  Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

    pinMode(D0, INPUT);
    pinMode(D4, INPUT);
    pinMode(D2, INPUT);
}

void loop() {
    millisElapsed = millis() - millisLast;
    if (digitalRead(D0) == HIGH){
        count1++;
    }
    if (digitalRead(D4) == HIGH){
        count2++;
    }
    if (digitalRead(D2) == HIGH){
        count3++;
    }

    if (millisElapsed > SAMPLE_TIME){

        if (count1 <= 0){
          count1 = abs(count1);
        }
        if (count2 <= 0){
          count2 = abs(count2);
        }
        if (count3 <= 0){
          count3 = abs(count3);
        }

        flow1 = (count1 * 2.25);
        flow1 = flow1 * 60;
        flow1 = flow1 / 1000;
        flow2 = (count2 * 2.25);
        flow2 = flow2 * 60;
        flow2 = flow2 / 1000;
        flow3 = (count3 * 2.25);
        flow3 = flow3 * 60;
        flow3 = flow3 / 1000; 
        Serial.print(flow1);
        Serial.print(",");
        Serial.print(flow2);
        Serial.print(",");
        Serial.println(flow3);

        Firebase.setFloat("user1/wf1", flow1);
        Firebase.setFloat("user1/wf2", flow2);
        Firebase.setFloat("user1/wf3", flow3);
        count1 = 0;
        count2 = 0;
        count3 = 0;
        millisLast = millis();
    }
//    Serial.print(digitalRead(D0));
//    Serial.print("\t");
//    Serial.print(digitalRead(D1));
//    Serial.print("\t");
//    Serial.print(digitalRead(D2));
//    Serial.println("\t");

  
}
