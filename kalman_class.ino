class KALMAN{
    int pin;
    int KalmanFilterData;
    float Xt; 
    float Xt_update; 
    float Xt_prev;
    float Pt; 
    float Pt_update;
    float Pt_prev;
    float Kt;
    float R;
    float Q;
  
    public:
    KALMAN(int input_pin){
        pin     = input_pin;
        R       = 100;
        Q       = 1;
        Pt_prev = 1;
    }

    float _process(){
              float SensorData = analogRead(pin);

        //kalman filter sensor adxl335
        Xt_update = Xt_prev;
        Pt_update = Pt_prev + Q;

        Kt = Pt_update / (Pt_update + R);
        Xt = Xt_update + ( Kt * (SensorData - Xt_update));
        Pt = (1 - Kt) * Pt_update;

        Xt_prev = Xt;
        Pt_prev = Pt;

        KalmanFilterData = Xt;
      return KalmanFilterData;
    }
    
    float _read(){
      int senval  = analogRead(pin);

      return senval;
    }
};

KALMAN sen0(A0);
KALMAN sen1(A1);
KALMAN sen2(A2);
KALMAN sen3(A3);
KALMAN sen4(A4);
KALMAN sen5(A5);

void setup() {
    Serial.begin(9600);
}

void loop() {
    float x_pred_1 = sen0._process();
    float x_real_1 = sen0._read();
    float y_pred_1 = sen1._process();
    float y_real_1 = sen1._read();
    float z_pred_1 = sen2._process();
    float z_real_1 = sen2._read();

    float x_pred_2 = sen3._process();
    float x_real_2 = sen3._read();
    float y_pred_2 = sen4._process();
    float y_real_2 = sen4._read();
    float z_pred_2 = sen5._process();
    float z_real_2 = sen5._read();

    float x_pred = (x_pred_1 + x_pred_2)/2;
    float x_real = (x_real_1 + x_real_2)/2;
    float y_pred = (y_pred_1 + y_pred_2)/2;
    float y_real = (y_real_1 + y_real_2)/2;
    float z_pred = (z_pred_1 + z_pred_2)/2;
    float z_real = (z_real_1 + z_real_2)/2;

    //Serial.print(x_pred);
    //Serial.print("\t");
    //Serial.print(y_pred);
    //Serial.print("\t");
    //Serial.print(z_pred);
    //Serial.print("\t");
    //Serial.print(x_real);
    //Serial.print("\t");
    Serial.print(z_pred);
    Serial.print("\t");
    Serial.println(z_real);

    delay(500);
}
