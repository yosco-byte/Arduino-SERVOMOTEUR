#include <Servo.h>
#include <Arduino.h>

Servo s;

const int pinBouton = 2;
const int pinServo = 9;

bool tourne = false;         
int boutonavant = HIGH;   

void setup() {
  s.attach(pinServo);
  s.write(0); 
  pinMode(pinBouton, INPUT_PULLUP); 
}

void loop() {
  int boutonmtn = digitalRead(pinBouton);

  if (boutonavant == HIGH && boutonmtn == LOW) {
    
    if (tourne == false) {
      
      for (int pos = 0; pos <= 180; pos++) {
        s.write(pos);
        delay(10); 
      }
      tourne = true; 
    } 
    else {

 for (int pos = 180; pos >= 0; pos--) {
        s.write(pos);
        delay(10);
      }
      tourne = false; 
    }
    
    delay(50); 
  }
  boutonavant = boutonmtn;
}
