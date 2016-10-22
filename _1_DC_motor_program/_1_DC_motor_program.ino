/*
   Telefonnal irányítható távirányítós jármű tervezése (1 DC motor)

   Készítette: Magyar Arduino Labor©
*/

int motorPin1 = 3; // Az L293D IC 2-es lába
int motorPin2 = 4; // Az L293D IC 7-es lába
int enablePin = 5; // Az L293D IC 1-es lába
int state;
int flag=0;        
 
void setup() {

    pinMode(motorPin1, OUTPUT);   // A lábak OUTPUT-ra állítása
    pinMode(motorPin2, OUTPUT);
    pinMode(enablePin, OUTPUT);

    digitalWrite(enablePin, HIGH);  // Az engedélyező láb 1-re állítása

    Serial.begin(9600);
}
 
void loop() {
    
    if(Serial.available() > 0){     
      state = Serial.read();   
      flag=0;
    }   

///////////////////MOTOR KIKAPCSOLÁSA////////////////////
    
    if (state == '0') {
        digitalWrite(motorPin1, LOW); // set pin 2 on L293D low
        digitalWrite(motorPin2, LOW); // set pin 7 on L293D low
        if(flag == 0){
          Serial.println("Motor: off");
          flag=1;
        }
    }

///////////////////MOTOR JOBBRA FOROG////////////////////
    
    else if (state == '1') {
        digitalWrite(motorPin1, LOW); 
        digitalWrite(motorPin2, HIGH); 
        if(flag == 0){
          Serial.println("Motor: right");
          flag=1;
        }
    }

///////////////////MOTOR BALRA FOROG////////////////////
    
    else if (state == '2') {
        digitalWrite(motorPin1, HIGH); 
        digitalWrite(motorPin2, LOW); 
        if(flag == 0){
          Serial.println("Motor: left");
          flag=1;
        }
    }
}
