/*
//Constants
#define UPDATE_TIME 20

//Parameters
int servoPin = 22;
int pulse = 500;

void setup() {
  // Initialization
  pinMode(servoPin,OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  // main
  digitalWrite(servoPin,HIGH);
  delayMicroseconds(pulse);
  digitalWrite(servoPin,LOW);
  delay(UPDATE_TIME);
}
*/

#include <Servo.h>
int pin = 22;
int pos = 65;
Servo servo;

void setup() {

    Serial.begin(9600);
    
    servo.attach(pin);
    servo.write(pos);
    delay(5000);
}
void loop() {
/*
    while (pos <= 180) {
      delay(50);
      pos++;
      servo.write(pos);
      //Serial.println("Position +1");
      Serial.println(pos);
    }
    delay (2000);
    
    while (pos >= 65) {
      delay(50);
      pos--;
      servo.write(pos);
      //Serial.println("Position -1");
      Serial.println(pos);
    }
    delay (2000);
    
    while (pos <= 190) {
      delay(100);
      pos += 10;
      servo.write(pos);
    }
    delay (500);
    
    pos = 0;
    servo.write(pos);
    delay (500);

    pos = 36;
    servo.write(pos);
    delay (500);

    pos = 72;
    servo.write(pos);
    delay (500);

    pos = 108;
    servo.write(pos);
    delay (500);

    pos = 144;
    servo.write(pos);
    delay (500);

    pos = 180;
    servo.write(pos);
    delay (500);

    pos = 144;
    servo.write(pos);
    delay (500);

    pos = 108;
    servo.write(pos);
    delay (500);

    pos = 72;
    servo.write(pos);
    delay (500);

    pos = 36;
    servo.write(pos);
    delay (500);
*/
    pos = 180;
    servo.write(pos);
    delay (1000);

    pos = 65;
    servo.write(pos);
    delay (1000);

    pos = 180;
    servo.write(pos);
    delay (1000);

    pos = 65;
    servo.write(pos);
    delay (1000);

    pos = 180;
    servo.write(pos);
    delay (1000);
    

    
}
