#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"
//============START SETTING============//
unsigned long delayStart    = 0;
unsigned long tEnd          = 30000;
unsigned long tEndLose      = 4000;
unsigned long tStabilizing  = 1000;
int           range         = 20;
bool          LDRsen        = true;
int           trigg         = 2; //
// trigg, 1 = us mobil, 2 = us sweep, 3 = light//
unsigned long delayPrint    = 50; //1000 = 1 second

bool R1active = true;
bool R2active = true;
bool R3active = true;
bool R4active = true;
bool R5active = true;
bool R6active = false;
bool R7active = false;
bool R8active = false;

int     printType = 0; //jenis print
String  myRel1      = "background ";
String  myRel2      = "strobo "; 
String  myRel3      = "dorong ";
String  myRel4      = "tangan ";
String  myRel5      = "goyang ";
String  myRel6      = "background";
String  myRel7      = "background";
String  myRel8      = "kaki "; 

unsigned long tAudio[] = {0,0,0,0,0};

unsigned long relay1[] = {
    0,   30000,   0,   30000,
    0,   0,   0,   0,
    0,   0,   0,   0,
    0,   0,   0,   0,
    0,   0,   0,   0,
    //animasi setelah ditembak
    100,   100,   0,2000, 
    100,   100,   0,1000,
    };

unsigned long relay2[] = {
    100,   100,   5000,   25000,
    0,   0,   0,   0,
    0,   0,   0,   0,
    0,   0,   0,   0,
    0,   0,   0,   0,
    //animasi setelah ditembak
    0,   0,   0,   0,
    0,   0,   0,   0,
    };

unsigned long relay3[] = {
    0,   25000,   0,   25000,
    3000,   0,   25000,   30000,
    0,   0,   0,   0,
    0,   0,   0,   0,
    0,   0,   0,   0,
    //animasi setelah ditembak
    10000,   0,   0,   10000,
    0,   0,   0,   0,
    };

unsigned long relay4[] = {
    0,   0,   0,   0,
    200,   200,   5000,   10000,
    400,   400,   10000,   15000,
    200,   150,   15000,   27000,
    0,   0,   0,   0,
    //animasi setelah ditembak
    150,   150,   0,   10000,
    0,   0,   0,   0,
    };

unsigned long relay5[] = {
    500,   500,   5000,   20000,
    700,   700,   20000,   27000,
    0,   0,   0,   0,
    0,   0,   0,   0,
    0,   0,   0,   0,
    //animasi setelah ditembak
    100,   50,   0,   5000,
    50,   100,   5000,   10000,
    };

unsigned long relay6[] = {
    0,   0,   0,   0,
    0,   0,   0,   0,
    0,   0,   0,   0,
    0,   0,   0,   0,
    0,   0,   0,   0,
    //animasi setelah ditembak
    0,   0,   0,   0,
    0,   0,   0,   0,
    };

unsigned long relay7[] = {
    0,   0,   0,   0,
    0,   0,   0,   0,
    0,   0,   0,   0,
    0,   0,   0,   0,
    0,   0,   0,   0,
    //animasi setelah ditembak
    0,   0,   0,   0,
    0,   0,   0,   0,
    };

unsigned long relay8[] = {
    0,   0,   0,   0,
    0,   0,   0,   0,
    0,   0,   0,   0,
    0,   0,   0,   0,
    0,   0,   0,   0,
    //animasi setelah ditembak
    0,   0,   0,   0,
    0,   0,   0,   0,
    };

//=============END SETTING=============//


DFRobotDFPlayerMini myDFPlayer;

unsigned long t0;
unsigned long t01;
unsigned long t02;
unsigned long t03;
unsigned long t04;
unsigned long t05;
unsigned long t06;
unsigned long t07;
unsigned long t08;
unsigned long t1;
unsigned long t2;
unsigned long t3;
unsigned long t4;
unsigned long t5;
unsigned long t6;
unsigned long t7;
unsigned long t8;
unsigned long tPrintDelay;
unsigned long tAnimEnd;
unsigned long tAnimEnd01;
unsigned long tAnimEnd02;
unsigned long tAnimEnd03;
unsigned long tAnimEnd04;
unsigned long tAnimEnd05;
unsigned long tAnimEnd06;
unsigned long tAnimEnd07;
unsigned long tAnimEnd08;
unsigned long tAE1;
unsigned long tAE2;
unsigned long tAE3;
unsigned long tAE4;
unsigned long tAE5;
unsigned long tAE6;
unsigned long tAE7;
unsigned long tAE8;

int r1 = 0;
int r2 = 0;
int r3 = 0;
int r4 = 0;
int r5 = 0;
int r6 = 0;
int r7 = 0;
int r8 = 0;

int a1 = 0;
int a2 = 0;
int a3 = 0;
int a4 = 0;
int a5 = 0;


#define trigPin  11
#define echoPin  12
#define lightPin 13

int lig         = 0;
int state       = 0;
int dis         = 0;
int i           = 0;
int o           = 0;
String arr[50]  = {};
  
void setup(){
    mySetting();
}

void loop(){
    if (LDRsen == true){
        lightSensor();
    }
    runModelUS();
    playAudio();
    delay(20);
    if (millis() - tPrintDelay >= delayPrint){
        myPrint();
        tPrintDelay = millis();
    } 
}

void mode1(){
    if (millis() - t01 >= relay1[2] && millis() - t01 <= relay1[3]){
        if (millis() - t1 >= relay1[0]){
            digitalWrite(2, LOW);
        }
        if (millis() - t1 >= relay1[0] + relay1[1]){
            digitalWrite(2, HIGH);
            t1 = millis();
        }
        r1 = 1;
    }else if (millis() - t01 >= relay1[6] && millis() - t01 <= relay1[7]){
        if (millis() - t1 >= relay1[4]){
            digitalWrite(2, LOW);
        }
        if (millis() - t1 >= relay1[4] + relay1[5]){
            digitalWrite(2, HIGH);
            t1 = millis();
        }
        r1 = 1;
    }else if (millis() - t01 >= relay1[10] && millis() - t01 <= relay1[11]){
        if (millis() - t1 >= relay1[8]){
            digitalWrite(2, LOW);
        }
        if (millis() - t1 >= relay1[8] + relay1[9]){
            digitalWrite(2, HIGH);
            t1 = millis();
        }
        r1 = 1;
    }else if (millis() - t01 >= relay1[14] && millis() - t01 <= relay1[15]){
        if (millis() - t1 >= relay1[12]){
            digitalWrite(2, LOW);
        }
        if (millis() - t1 >= relay1[12] + relay1[13]){
            digitalWrite(2, HIGH);
            t1 = millis();
        }
        r1 = 1;
    }else if (millis() - t01 >= relay1[18] && millis() - t01 <= relay1[19]){
        if (millis() - t1 >= relay1[16]){
            digitalWrite(2, LOW);
        }
        if (millis() - t1 >= relay1[16] + relay1[17]){
            digitalWrite(2, HIGH);
            t1 = millis();
        }
        r1 = 1;
    }else{
        r1 = 0;
    }
}

void mode2(){
    if (millis() - t02 >= relay2[2] && millis() - t02 <= relay2[3]){
        if (millis() - t2 >= relay2[0]){
            digitalWrite(3, LOW);
        }
        if (millis() - t2 >= relay2[0] + relay2[1]){
            digitalWrite(3, HIGH);
            t2 = millis();
        }
        r2 = 1;
    }else if (millis() - t02 >= relay2[6] && millis() - t02 <= relay2[7]){
        if (millis() - t2 >= relay2[4]){
            digitalWrite(3, LOW);
        }
        if (millis() - t2 >= relay2[4] + relay2[5]){
            digitalWrite(3, HIGH);
            t2 = millis();
        }
        r2 = 1;
    }else if (millis() - t02 >= relay2[10] && millis() - t02 <= relay2[11]){
        if (millis() - t2 >= relay2[8]){
            digitalWrite(3, LOW);
        }
        if (millis() - t2 >= relay2[8] + relay2[9]){
            digitalWrite(3, HIGH);
            t2 = millis();
        }
        r2 = 1;
    }else if (millis() - t02 >= relay2[14] && millis() - t02 <= relay2[15]){
        if (millis() - t2 >= relay2[12]){
            digitalWrite(3, LOW);
        }
        if (millis() - t2 >= relay2[12] + relay2[13]){
            digitalWrite(3, HIGH);
            t2 = millis();
        }
        r2 = 1;
    }else if (millis() - t02 >= relay2[18] && millis() - t02 <= relay2[19]){
        if (millis() - t2 >= relay2[16]){
            digitalWrite(3, LOW);
        }
        if (millis() - t2 >= relay2[16] + relay2[17]){
            digitalWrite(3, HIGH);
            t2 = millis();
        }
        r2 = 1;
    }else{
        r2 = 0;
    }
}

void mode3(){
    if (millis() - t03 >= relay3[2] && millis() - t03 <= relay3[3]){
        if (millis() - t3 >= relay3[0]){
            digitalWrite(4, LOW);
        }
        if (millis() - t3 >= relay3[0] + relay3[1]){
            digitalWrite(4, HIGH);
            t3 = millis();
        }
        r3 = 1;
    }else if (millis() - t03 >= relay3[6] && millis() - t03 <= relay3[7]){
        if (millis() - t3 >= relay3[4]){
            digitalWrite(4, LOW);
        }
        if (millis() - t3 >= relay3[4] + relay3[5]){
            digitalWrite(4, HIGH);
            t3 = millis();
        }
        r3 = 1;
    }else if (millis() - t03 >= relay3[10] && millis() - t03 <= relay3[11]){
        if (millis() - t3 >= relay3[8]){
            digitalWrite(4, LOW);
        }
        if (millis() - t3 >= relay3[8] + relay3[9]){
            digitalWrite(4, HIGH);
            t3 = millis();
        }
        r3 = 1;
    }else if (millis() - t03 >= relay3[14] && millis() - t03 <= relay3[15]){
        if (millis() - t3 >= relay3[12]){
            digitalWrite(4, LOW);
        }
        if (millis() - t3 >= relay3[12] + relay3[13]){
            digitalWrite(4, HIGH);
            t3 = millis();
        }
        r3 = 1;
    } else if (millis() - t03 >= relay3[18] && millis() - t03 <= relay3[19]){
        if (millis() - t3 >= relay1[16]){
            digitalWrite(4, LOW);
        }
        if (millis() - t3 >= relay1[16] + relay3[17]){
            digitalWrite(4, HIGH);
            t3 = millis();
        }
        r3 = 1;
    }else{
        r3 = 0;
    }
}

void mode4(){
    if (millis() - t04 >= relay4[2] && millis() - t04 <= relay4[3]){
        if (millis() - t4 >= relay4[0]){
            digitalWrite(5, LOW);
        }
        if (millis() - t4 >= relay4[0] + relay1[1]){
            digitalWrite(5, HIGH);
            t4 = millis();
        }
        r4 = 1;
    }else if (millis() - t04 >= relay4[6] && millis() - t04 <= relay4[7]){
        if (millis() - t4 >= relay4[4]){
            digitalWrite(5, LOW);
        }
        if (millis() - t4 >= relay4[4] + relay4[5]){
            digitalWrite(5, HIGH);
            t4 = millis();
        }
        r4 = 1;
    }else if (millis() - t04 >= relay4[10] && millis() - t04 <= relay4[11]){
        if (millis() - t4 >= relay4[8]){
            digitalWrite(5, LOW);
        }
        if (millis() - t4 >= relay4[8] + relay4[9]){
            digitalWrite(5, HIGH);
            t4 = millis();
        }
        r4 = 1;
    }else if (millis() - t04 >= relay4[14] && millis() - t04 <= relay4[15]){
        if (millis() - t4 >= relay4[12]){
            digitalWrite(5, LOW);
        }
        if (millis() - t4 >= relay4[12] + relay4[13]){
            digitalWrite(5, HIGH);
            t4 = millis();
        }
        r4 = 1;
    }else if (millis() - t04 >= relay4[18] && millis() - t04 <= relay4[19]){
        if (millis() - t4 >= relay4[16]){
            digitalWrite(5, LOW);
        }
        if (millis() - t4 >= relay4[16] + relay4[17]){
            digitalWrite(5, HIGH);
            t4 = millis();
        }
        r4 = 1;
    }else{
        r4 = 0;
    }
}

void mode5(){
    if (millis() - t05 >= relay5[2] && millis() - t05 <= relay5[3]){
        if (millis() - t5 >= relay5[0]){
            digitalWrite(6, LOW);
        }
        if (millis() - t5 >= relay5[0] + relay5[1]){
            digitalWrite(6, HIGH);
            t5 = millis();
        }
        r5 = 1;
    }else if (millis() - t05 >= relay5[6] && millis() - t05 <= relay5[7]){
        if (millis() - t5 >= relay5[4]){
            digitalWrite(6, LOW);
        }
        if (millis() - t5 >= relay5[4] + relay5[5]){
            digitalWrite(6, HIGH);
            t5 = millis();
        }
        r5 = 1;
    }else if (millis() - t05 >= relay5[10] && millis() - t05 <= relay5[11]){
        if (millis() - t5 >= relay5[8]){
            digitalWrite(6, LOW);
        }
        if (millis() - t5 >= relay5[8] + relay5[9]){
            digitalWrite(6, HIGH);
            t5 = millis();
        }
        r5 = 1;
    }else if (millis() - t05 >= relay5[14] && millis() - t05 <= relay5[15]){
        if (millis() - t5 >= relay5[12]){
            digitalWrite(6, LOW);
        }
        if (millis() - t5 >= relay5[12] + relay5[13]){
            digitalWrite(6, HIGH);
            t5 = millis();
        }
        r5 = 1;
    }else if (millis() - t05 >= relay5[18] && millis() - t05 <= relay5[19]){
        if (millis() - t5 >= relay5[16]){
            digitalWrite(6, LOW);
        }
        if (millis() - t5 >= relay5[16] + relay5[17] ){
            digitalWrite(6, HIGH);
            t5 = millis();
        }
        r5 = 1;
    }else{
        r5 = 0;
    }
}

void mode6(){
    if (millis() - t06 >= relay6[2] && millis() - t06 <= relay6[3]){
        if (millis() - t6 >= relay6[0]){
            digitalWrite(7, LOW);
        }
        if (millis() - t6 >= relay6[0] + relay6[1]){
            digitalWrite(7, HIGH);
            t6 = millis();
        }
        r6 = 1;
    }else if (millis() - t06 >= relay6[6] && millis() - t06 <= relay6[7]){
        if (millis() - t6 >= relay6[4]){
            digitalWrite(7, LOW);
        }
        if (millis() - t6 >= relay6[4] + relay6[5]){
            digitalWrite(7, HIGH);
            t6 = millis();
        }
        r6 = 1;
    }else if (millis() - t06 >= relay6[10] && millis() - t06 <= relay6[11]){
        if (millis() - t6 >= relay6[8]){
            digitalWrite(7, LOW);
        }
        if (millis() - t6 >= relay6[8] + relay6[9]){
            digitalWrite(7, HIGH);
            t6 = millis();
        }
        r6 = 1;
    }else if (millis() - t06 >= relay6[14] && millis() - t06 <= relay6[15]){
        if (millis() - t6 >= relay6[12]){
            digitalWrite(7, LOW);
        }
        if (millis() - t6 >= relay6[12] + relay6[13]){
            digitalWrite(7, HIGH);
            t6 = millis();
        }
        r6 = 1;
    }else if (millis() - t06 >= relay6[18] && millis() - t06 <= relay6[19]){
        if (millis() - t6 >= relay6[16]){
            digitalWrite(7, LOW);
        }
        if (millis() - t6 >= relay6[16] + relay6[17]){
            digitalWrite(7, HIGH);
            t6 = millis();
        }
        r6 = 1;
    }else{
        r6 = 0;
    }
}

void mode7(){
    if (millis() - t07 >= relay7[2] && millis() - t07 <= relay7[3]){
        if (millis() - t7 >= relay7[0]){
            digitalWrite(8, LOW);
        }
        if (millis() - t7 >= relay7[0] + relay7[1]){
            digitalWrite(8, HIGH);
            t7 = millis();
        }
        r7 = 1;
    }else if (millis() - t07 >= relay7[6] && millis() - t07 <= relay7[7]){
        if (millis() - t7 >= relay7[4]){
            digitalWrite(8, LOW);
        }
        if (millis() - t7 >= relay7[4] + relay7[5]){
            digitalWrite(8, HIGH);
            t7 = millis();
        }
        r7 = 1;
    }else if (millis() - t07 >= relay7[10] && millis() - t07 <= relay7[11]){
        if (millis() - t7 >= relay7[8]){
            digitalWrite(8, LOW);
        }
        if (millis() - t7 >= relay7[8] + relay7[9]){
            digitalWrite(8, HIGH);
            t7 = millis();
        }
        r7 = 1;
    }else if (millis() - t07 >= relay7[14] && millis() - t07 <= relay7[15]){
        if (millis() - t7 >= relay7[12]){
            digitalWrite(8, LOW);
        }
        if (millis() - t7 >= relay7[12] + relay7[13]){
            digitalWrite(8, HIGH);
            t7 = millis();
        }
        r7 = 1;
    }else if (millis() - t07 >= relay7[18] && millis() - t07 <= relay7[19]){
        if (millis() - t7 >= relay7[16]){
            digitalWrite(8, LOW);
        }
        if (millis() - t7 >= relay7[16] + relay7[17]){
            digitalWrite(8, HIGH);
            t7 = millis();
        }
        r7 = 1;
    }else {
        r7 = 0;
    }
}

void mode8(){
    if (millis() - t08 >= relay8[2] && millis() - t08 <= relay8[3]){
        if (millis() - t8 >= relay8[0]){
            digitalWrite(9, LOW);
        }
        if (millis() - t8 >= relay8[0] + relay8[1]){
            digitalWrite(9, HIGH);
            t8 = millis();
        }
        r8 = 1;
    }else if (millis() - t08 >= relay8[6] && millis() - t08 <= relay8[7]){
        if (millis() - t8 >= relay8[4]){
            digitalWrite(9, LOW);
        }
        if (millis() - t8 >= relay8[4] + relay8[5]){
            digitalWrite(9, HIGH);
            t8 = millis();
        }
        r8 = 1;
    }else if (millis() - t08 >= relay8[10] && millis() - t08 <= relay8[11]){
        if (millis() - t8 >= relay8[8]){
            digitalWrite(9, LOW);
        }
        if (millis() - t8 >= relay8[8] + relay8[9]){
            digitalWrite(9, HIGH);
            t8 = millis();
        }
        r8 = 1;
    }else if (millis() - t08 >= relay8[14] && millis() - t08 <= relay8[15]){
        if (millis() - t8 >= relay8[12]){
            digitalWrite(9, LOW);
        }
        if (millis() - t8 >= relay8[12] + relay8[13]){
            digitalWrite(9, HIGH);
            t8 = millis();
        }
        r8 = 1;
    }else if (millis() - t08 >= relay8[18] && millis() - t08 <= relay8[19]){
        if (millis() - t8 >= relay8[16]){
            digitalWrite(9, LOW);
        }
        if (millis() - t8 >= relay8[16] + relay8[17]){
            digitalWrite(9, HIGH);
            t8 = millis();
        }
        r8 = 1;
    }else{
        r8 = 0;
    }
}

void modeEnd(){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    delay(2000);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
}

void modeAnimEnd(){
    for (int i = 0 ; i <= 1000 ; i++){
      Serial.print(i);
      Serial.println("");
      digitalWrite(2, LOW);
        if (millis() - tAnimEnd01 >= relay1[22] && millis() - tAnimEnd01 <= relay1[23]){
            if (millis() - tAE1 >= relay1[20]){
                digitalWrite(2, LOW);
            }
            if (millis() - tAE1 >= relay1[20] + relay1[21]){
                digitalWrite(2, HIGH);
                tAE1 = millis();
            }
        }
        if (millis() - tAnimEnd02 >= relay2[22] && millis() - tAnimEnd02 <= relay2[23]){
            if (millis() - tAE2 >= relay2[20]){
                digitalWrite(3, LOW);
            }
            if (millis() - tAE2 >= relay2[20] + relay2[21]){
                digitalWrite(3, HIGH);
                tAE2 = millis();
            }
        }
        if (millis() - tAnimEnd03 >= relay3[22] && millis() - tAnimEnd03 <= relay3[23]){
            if (millis() - tAE3 >= relay3[20]){
                digitalWrite(4, LOW);
            }
            if (millis() - tAE3 >= relay3[20] + relay3[21]){
                digitalWrite(4, HIGH);
                tAE3 = millis();
            }
        }
        if (millis() - tAnimEnd04 >= relay4[22] && millis() - tAnimEnd04 <= relay4[23]){
            if (millis() - tAE4 >= relay4[20]){
                digitalWrite(5, LOW);
            }
            if (millis() - tAE4 >= relay4[21]){
                digitalWrite(5, HIGH);
                tAE4 = millis();
            }
        }
        if (millis() - tAnimEnd05 >= relay5[22] && millis() - tAnimEnd05 <= relay5[23]){
            if (millis() - tAE5 >= relay5[20]){
                digitalWrite(6, LOW);
            }
            if (millis() - tAE5 >= relay5[20] + relay5[21]){
                digitalWrite(6, HIGH);
                tAE5 = millis();
            }
        }
        if (millis() - tAnimEnd06 >= relay6[22] && millis() - tAnimEnd06 <= relay6[23]){
            if (millis() - tAE6 >= relay6[20]){
                digitalWrite(7, LOW);
            }
            if (millis() - tAE6 >= relay6[20] + relay6[21]){
                digitalWrite(7, HIGH);
                tAE6 = millis();
            }
        }
        if (millis() - tAnimEnd07 >= relay7[22] && millis() - tAnimEnd07 <= relay7[23]){
            if (millis() - tAE7 >= relay7[20]){
                digitalWrite(8, LOW);
            }
            if (millis() - tAE7 >= relay7[20] + relay7[21]){
                digitalWrite(8, HIGH);
                tAE7 = millis();
            }
        }
        if (millis() - tAnimEnd08 >= relay8[22] && millis() - tAnimEnd08 <= relay8[23]){
            if (millis() - tAE8 >= relay8[20]){
                digitalWrite(9, LOW);
            }
            if (millis() - tAE8 >= relay8[20] + relay8[21]){
                digitalWrite(9, HIGH);
                tAE8 = millis();
            }
        }
        if (millis() - tAnimEnd01 >= relay1[26] && millis() - tAnimEnd01 <= relay1[27]){
            if (millis() - tAE1 >= relay1[24]){
                digitalWrite(2, LOW);
            }
            if (millis() - tAE1 >= relay1[24] + relay1[25]){
                digitalWrite(2, HIGH);
                tAE1 = millis();
            }
        }
        if (millis() - tAnimEnd02 >= relay2[26] && millis() - tAnimEnd02 <= relay2[27]){
            if (millis() - tAE2 >= relay2[24]){
                digitalWrite(3, LOW);
            }
            if (millis() - tAE2 >= relay2[25]){
                digitalWrite(3, HIGH);
                tAE2 = millis();
            }
        }
        if (millis() - tAnimEnd03 >= relay3[26] && millis() - tAnimEnd03 <= relay3[27]){
            if (millis() - tAE3 >= relay3[24]){
                digitalWrite(4, LOW);
            }
            if (millis() - tAE3 >= relay3[24] + relay3[25]){
                digitalWrite(4, HIGH);
                tAE3 = millis();
            }
        }
        if (millis() - tAnimEnd04 >= relay4[26] && millis() - tAnimEnd04 <= relay4[27]){
            if (millis() - tAE4 >= relay4[24]){
                digitalWrite(5, LOW);
            }
            if (millis() - tAE4 >= relay4[24] + relay4[25]){
                digitalWrite(5, HIGH);
                tAE4 = millis();
            }
        }
        if (millis() - tAnimEnd05 >= relay5[26] && millis() - tAnimEnd05 <= relay5[27]){
            if (millis() - tAE5 >= relay5[24]){
                digitalWrite(6, LOW);
            }
            if (millis() - tAE5 >= relay5[24] + relay5[25]){
                digitalWrite(6, HIGH);
                tAE5 = millis();
            }
        }
        if (millis() - tAnimEnd06 >= relay6[26] && millis() - tAnimEnd06 <= relay6[27]){
            if (millis() - tAE6 >= relay6[24]){
                digitalWrite(7, LOW);
            }
            if (millis() - tAE6 >= relay6[24]+relay6[25]){
                digitalWrite(7, HIGH);
                tAE6 = millis();
            }
        }
        if (millis() - tAnimEnd07 >= relay7[26] && millis() - tAnimEnd07 <= relay7[27]){
            if (millis() - tAE7 >= relay7[24]){
                digitalWrite(8, LOW);
            }
            if (millis() - tAE7 >= relay7[24]+relay7[25]){
                digitalWrite(8, HIGH);
                tAE7 = millis();
            }
        }
        if (millis() - tAnimEnd08 >= relay8[26] && millis() - tAnimEnd08 <= relay8[27]){
            if (millis() - tAE8 >= relay8[24]){
                digitalWrite(9, LOW);
            }
            if (millis() - tAE8 >= relay8[24]+relay8[25]){
                digitalWrite(9, HIGH);
                tAE8 = millis();
            }
        }
        delay(20);
        if (millis() - tAnimEnd >= tEndLose){
            break;
        }
    }
}

void playAudio(){
    if (millis() - t0 >= tAudio[0] && millis() - t0 <= tAudio[0] + 25){
        myDFPlayer.play(1);
    }
    if (millis() - t0 >= tAudio[1] && millis() - t0 <= tAudio[1] + 25){
        myDFPlayer.play(2);
    }
    if (millis() - t0 >= tAudio[2] && millis() - t0 <= tAudio[2] + 25){
        myDFPlayer.play(3);
    }
    if (millis() - t0 >= tAudio[3] && millis() - t0 <= tAudio[3] + 25){
        myDFPlayer.play(4);
    }
    if (millis() - t0 >= tAudio[4] && millis() - t0 <= tAudio[4] + 25){
        myDFPlayer.play(5);
    }
}

void mySetting(){
    Serial.begin(9600);
    Serial1.begin(9600);
    myDFPlayer.begin(Serial1);
    myDFPlayer.volume(30);
    myDFPlayer.play(1);
    delay(500);
    myDFPlayer.stop();

    for (int i = 2 ; i <= 9 ; i++){
        pinMode(i, OUTPUT);
        digitalWrite(i, HIGH);
    }

    pinMode(trigPin,  OUTPUT);
    pinMode(echoPin,  INPUT);
    pinMode(lightPin, INPUT);
}

void runModelUS(){
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    int dur = pulseIn(echoPin, HIGH);
    dis = 0.017 * dur;

    if (trigg == 1){
        if (dis <= range ){
            o = 1;
        } else {
            o = 0;
        }

        arr[i] = o;
        if (i == 49){
            i = 0;
        }
        i = i + 1;
    } else if (trigg == 2){
        if (state == 1){
            arr[1]  = String(1);
            arr[17] = String(1);
            arr[35] = String(1);
        } else {
            arr[1]  = String(0);
            arr[17] = String(0);
            arr[35] = String(0);
        } 

        if (dis <= range && state == 0){
            arr[1]  = String(1);
            arr[17] = String(1);
            arr[35] = String(1);
        } 
    } else if (trigg == 3){
        int ligRead = digitalRead(13);
        if (state == 1){
            arr[1]  = String(1);
            arr[17] = String(1);
            arr[35] = String(1);
        } else {
            arr[1]  = String(0);
            arr[17] = String(0);
            arr[35] = String(0);
        } 

        if (ligRead == 0 && state == 0){
            arr[1]  = String(1);
            arr[17] = String(1);
            arr[35] = String(1);
        }
    }

    if (arr[1] == "1" && arr[17] == "1" && arr[35] == "1" && state == 0){
        state  = 1;
        delay(delayStart);
        t0  = millis();
        t1  = millis();
        t2  = millis();
        t3  = millis();
        t4  = millis();
        t5  = millis();
        t6  = millis();
        t7  = millis();
        t8  = millis();
        t01 = millis();
        t02 = millis();
        t03 = millis();
        t04 = millis();
        t05 = millis();
        t06 = millis();
        t07 = millis();
        t08 = millis();
    }else if (arr[1] == "1" && arr[17] == "1" && arr[35] == "1" && state == 1){
        if (millis() - t0 >= tEnd){
            state = 2;
            modeEnd();
        }

        if (R1active == true){mode1();}
        if (R2active == true){mode2();}
        if (R3active == true){mode3();}
        if (R4active == true){mode4();}
        if (R5active == true){mode5();}
        if (R6active == true){mode6();}
        if (R7active == true){mode7();}
        if (R8active == true){mode8();}
    }else if (arr[1] == "0" && arr[17] == "0" && arr[35] == "0" && state == 1){
        state = 0;
        delay(tStabilizing);
    }else if (arr[1] == "0" && arr[17] == "0" && arr[35] == "0" && state == 2){
        state = 0;
        delay(tStabilizing);
    }else if (arr[1] == "0" && arr[17] == "1" && arr[35] == "1" && state == 1){
        modeEnd();
        state = 2;  
    }else if (arr[1] == "1" && arr[17] == "0" && arr[35] == "1" && state == 1){
        modeEnd();
        state = 2;
    }else if (arr[1] == "1" && arr[17] == "1" && arr[35] == "0" && state == 1){
        modeEnd();
        state = 2;
    }else {
        r1 = 0; r2 = 0; r3 = 0; r4 = 0; r5 = 0; r6 = 0; r7 = 0; r8 = 0;
        for (int i=2;i<=9;i++){
            digitalWrite(i, HIGH);
        }
    }
}

void lightSensor(){
    lig = digitalRead(lightPin);

    if (lig == 0){
        myDFPlayer.play(4);
        tAnimEnd = millis();
        tAnimEnd01 = millis();
        tAnimEnd02 = millis();
        tAnimEnd03 = millis();
        tAnimEnd04 = millis();
        tAnimEnd05 = millis();
        tAnimEnd06 = millis();
        tAnimEnd07 = millis();
        tAnimEnd08 = millis();
        tAE1 = millis();
        tAE2 = millis();
        tAE3 = millis();
        tAE4 = millis();
        tAE5 = millis();
        tAE6 = millis();
        tAE7 = millis();
        tAE8 = millis();
        for (int i = 0 ; i <= 1000 ; i++){
        Serial.print(i);
        Serial.println("");
          if (millis() - tAnimEnd01 >= relay1[22] && millis() - tAnimEnd01 <= relay1[23]){
              if (millis() - tAE1 >= relay1[20]){
                  digitalWrite(2, LOW);
              }
              if (millis() - tAE1 >= relay1[20] + relay1[21]){
                  digitalWrite(2, HIGH);
                  tAE1 = millis();
              }
          }
          if (millis() - tAnimEnd02 >= relay2[22] && millis() - tAnimEnd02 <= relay2[23]){
              if (millis() - tAE2 >= relay2[20]){
                  digitalWrite(3, LOW);
              }
              if (millis() - tAE2 >= relay2[20] + relay2[21]){
                  digitalWrite(3, HIGH);
                  tAE2 = millis();
              }
          }
          if (millis() - tAnimEnd03 >= relay3[22] && millis() - tAnimEnd03 <= relay3[23]){
              if (millis() - tAE3 >= relay3[20]){
                  digitalWrite(4, LOW);
              }
              if (millis() - tAE3 >= relay3[20] + relay3[21]){
                  digitalWrite(4, HIGH);
                  tAE3 = millis();
              }
          }
          if (millis() - tAnimEnd04 >= relay4[22] && millis() - tAnimEnd04 <= relay4[23]){
              if (millis() - tAE4 >= relay4[20]){
                  digitalWrite(5, LOW);
              }
              if (millis() - tAE4 >= relay4[20] + relay4[21]){
                  digitalWrite(5, HIGH);
                  tAE4 = millis();
              }
        }
        if (millis() - tAnimEnd05 >= relay5[22] && millis() - tAnimEnd05 <= relay5[23]){
            if (millis() - tAE5 >= relay5[20]){
                digitalWrite(6, LOW);
            }
            if (millis() - tAE5 >= relay5[20] + relay5[21]){
                digitalWrite(6, HIGH);
                tAE5 = millis();
            }
        }
        if (millis() - tAnimEnd06 >= relay6[22] && millis() - tAnimEnd06 <= relay6[23]){
            if (millis() - tAE6 >= relay6[20]){
                digitalWrite(7, LOW);
            }
            if (millis() - tAE6 >= relay6[20] + relay6[21]){
                digitalWrite(7, HIGH);
                tAE6 = millis();
            }
        }
        if (millis() - tAnimEnd07 >= relay7[22] && millis() - tAnimEnd07 <= relay7[23]){
            if (millis() - tAE7 >= relay7[20]){
                digitalWrite(8, LOW);
            }
            if (millis() - tAE7 >= relay7[20] + relay7[21]){
                digitalWrite(8, HIGH);
                tAE7 = millis();
            }
        }
        if (millis() - tAnimEnd08 >= relay8[22] && millis() - tAnimEnd08 <= relay8[23]){
            if (millis() - tAE8 >= relay8[20]){
                digitalWrite(9, LOW);
            }
            if (millis() - tAE8 >= relay8[20] + relay8[21]){
                digitalWrite(9, HIGH);
                tAE8 = millis();
            }
        }
        if (millis() - tAnimEnd01 >= relay1[26] && millis() - tAnimEnd01 <= relay1[27]){
            if (millis() - tAE1 >= relay1[24]){
                digitalWrite(2, LOW);
            }
            if (millis() - tAE1 >= relay1[24] + relay1[25]){
                digitalWrite(2, HIGH);
                tAE1 = millis();
            }
        }
        if (millis() - tAnimEnd02 >= relay2[26] && millis() - tAnimEnd02 <= relay2[27]){
            if (millis() - tAE2 >= relay2[24]){
                digitalWrite(3, LOW);
            }
            if (millis() - tAE2 >= relay2[24] + relay2[25]){
                digitalWrite(3, HIGH);
                tAE2 = millis();
            }
        }
        if (millis() - tAnimEnd03 >= relay3[26] && millis() - tAnimEnd03 <= relay3[27]){
            if (millis() - tAE3 >= relay3[24]){
                digitalWrite(4, LOW);
            }
            if (millis() - tAE3 >= relay3[24] + relay3[25]){
                digitalWrite(4, HIGH);
                tAE3 = millis();
            }
        }
        if (millis() - tAnimEnd04 >= relay4[26] && millis() - tAnimEnd04 <= relay4[27]){
            if (millis() - tAE4 >= relay4[24]){
                digitalWrite(5, LOW);
            }
            if (millis() - tAE4 >= relay4[24] + relay4[25]){
                digitalWrite(5, HIGH);
                tAE4 = millis();
            }
        }
        if (millis() - tAnimEnd05 >= relay5[26] && millis() - tAnimEnd05 <= relay5[27]){
            if (millis() - tAE5 >= relay5[24]){
                digitalWrite(6, LOW);
            }
            if (millis() - tAE5 >= relay5[24] + relay5[25]){
                digitalWrite(6, HIGH);
                tAE5 = millis();
            }
        }
        if (millis() - tAnimEnd06 >= relay6[26] && millis() - tAnimEnd06 <= relay6[27]){
            if (millis() - tAE6 >= relay6[24]){
                digitalWrite(7, LOW);
            }
            if (millis() - tAE6 >= relay6[24]+relay6[25]){
                digitalWrite(7, HIGH);
                tAE6 = millis();
            }
        }
        if (millis() - tAnimEnd07 >= relay7[26] && millis() - tAnimEnd07 <= relay7[27]){
            if (millis() - tAE7 >= relay7[24]){
                digitalWrite(8, LOW);
            }
            if (millis() - tAE7 >= relay7[24]+relay7[25]){
                digitalWrite(8, HIGH);
                tAE7 = millis();
            }
        }
        if (millis() - tAnimEnd08 >= relay8[26] && millis() - tAnimEnd08 <= relay8[27]){
            if (millis() - tAE8 >= relay8[24]){
                digitalWrite(9, LOW);
            }
            if (millis() - tAE8 >= relay8[24]+relay8[25]){
                digitalWrite(9, HIGH);
                tAE8 = millis();
            }
        }
        delay(20);
        if (millis() - tAnimEnd >= tEndLose){
            break;
        }
    }
        state = 2;
        lig = 1;
    }
}

void myPrint(){
    Serial.print(lig);
    Serial.print("\t");
    Serial.print(dis);
    Serial.print("\t");
    Serial.print(arr[1]);
    Serial.print(arr[17]);
    Serial.print(arr[35]);
    Serial.print("\t");
    Serial.print(state);
    Serial.print("\t");
    Serial.print(millis() - t0);
    Serial.print("\t");
    if (printType == 0){
        Serial.print(r1);
        Serial.print(r2);
        Serial.print(r3);
        Serial.print(r4);
        Serial.print(r5);
        Serial.print(r6);
        Serial.print(r7);
        Serial.print(r8);
    } else if (printType == 1) {
        if ( r1 == 1){
            Serial.print(myRel1);
        } else {
            Serial.print("    ");
        }
        if ( r2 == 1){
            Serial.print(myRel2);
        } else {
            Serial.print("    ");
        }
        if ( r3 == 1){
            Serial.print(myRel3);
        } else {
            Serial.print("    ");
        }
        if ( r4 == 1){
            Serial.print(myRel4);
        } else {
            Serial.print("    ");
        }
        if ( r5 == 1){
            Serial.print(myRel5);
        } else {
            Serial.print("    ");
        }
        if ( r6 == 1){
            Serial.print(myRel6);
        } else {
            Serial.print("    ");
        }
        if ( r7 == 1){
            Serial.print(myRel7);
        } else {
            Serial.print("    ");
        }
        if ( r8 == 1){
            Serial.print(myRel8);
        } else {
            Serial.print("    ");
        }
    }
    
    Serial.print("\t");
    Serial.print(a1);
    Serial.print(a2);
    Serial.print(a3);
    Serial.print(a4);
    Serial.print(a5);

    Serial.println(" ");

}
