/*
  Telefonnal irányítható távirányítós jármű tervezése

  Készítette: Magyar Arduino Labor©

 */
 
int motor1Pin1 = 3; // Az L293D IC 2-es lába
int motor1Pin2 = 4; // Az L293D IC 7-es lába
int enable1Pin = 6; // Az L293D IC 1-es lába
int motor2Pin1 = 8; // Az L293D IC 10-es lába
int motor2Pin2 = 9; // Az L293D IC 15-ös lába
int enable2Pin = 11; // Az L293D IC 9-es lába
int state;
int flag=0; 
int stateStop=0;

void setup() {
  
    pinMode(motor1Pin1, OUTPUT);    // A lábak OUTPUT-okra állítása
    pinMode(motor1Pin2, OUTPUT);
    pinMode(enable1Pin, OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
    pinMode(enable2Pin, OUTPUT);

    digitalWrite(enable1Pin, HIGH);   // Az engedélyező lábak 1-re állítása 
    digitalWrite(enable2Pin, HIGH);

    Serial.begin(9600);     // A soros kommunikáció kezdőértékének beállítása
}

void loop() {
   
    if(Serial.available() > 0){     
      state = Serial.read();   
      flag=0;
    }   

///////////////////////ELŐREMENET////////////////////////

    if (state == '1') {
        digitalWrite(motor1Pin1, HIGH);
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        if(flag == 0){
          Serial.println("Go Forward!");
          flag=1;
        }
    }
    
///////////////////////BALRA FORDULÁS////////////////////////    

    else if (state == '2') {
        digitalWrite(motor1Pin1, HIGH); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          Serial.println("Turn LEFT");
          flag=1;
        }
        delay(1500);
        state=3;
        stateStop=1;
    }

///////////////////////STOP////////////////////////

    else if (state == '3' || stateStop == 1) {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          Serial.println("STOP!");
          flag=1;
        }
        stateStop=0;
    }

///////////////////////JOBBRA FORDULÁS////////////////////////

    else if (state == '4') {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        if(flag == 0){
          Serial.println("Turn RIGHT");
          flag=1;
        }
        delay(1500);
        state=3;
        stateStop=1;
    }
    
///////////////////////TOLATÁS////////////////////////

    else if (state == '5') {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, HIGH);
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          Serial.println("Reverse!");
          flag=1;
        }
    }
}
