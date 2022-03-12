class Flasher{
	int ledPin;
	long OnTime;
  	long OffTime;    

	int ledState;
	unsigned long previousMillis;

  public:
  Flasher(int pin, long on, long off){
      ledPin = pin;
      pinMode(ledPin, OUTPUT);     

      OnTime = on;
      OffTime = off;

      ledState = LOW; 
      previousMillis = 0;
  }

  void Update(){
    unsigned long currentMillis = millis();
     
    if((ledState == HIGH) && (currentMillis - previousMillis >= OnTime)){
    	ledState = LOW;
      previousMillis = currentMillis;
      digitalWrite(ledPin, ledState);
    }
    else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime))
    {
      ledState = HIGH;
      previousMillis = currentMillis;
      digitalWrite(ledPin, ledState);
    }
  }
};


Flasher led1(2, 10, 40);
Flasher led2(7, 350, 350);
Flasher led3(13, 50, 50);

void setup(){
}

void loop(){
	led1.Update();
  	led2.Update();
	led3.Update();
}
