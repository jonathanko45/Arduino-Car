#include <SoftwareSerial.h>
SoftwareSerial mySerial(8, 12); // RX, TX

int a;
long duration, distance;

void setup() {
  pinMode(8, INPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(12, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  mySerial.begin(9600);
}

    
void loop() {
  
  digitalWrite(13, LOW);
  delayMicroseconds(2);
  
  digitalWrite(13, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(13, LOW);
  duration = pulseIn(12, HIGH);
  
  distance = duration / 58.2;
  
  Serial.print(distance);
  Serial.print(' ');

  if (distance <= 30){
    digitalWrite(4, HIGH);
    digitalWrite(7, LOW);
    analogWrite(5, 170);
    analogWrite(6, 170);
  }else{
    digitalWrite(4, LOW);
    digitalWrite(7, LOW);
    analogWrite(5, 255);
    analogWrite(6, 255);
  }
  
  /*
  while (mySerial.available()){

    a=mySerial.read();
    if (a=='0'){
      analogWrite(5, 0);
      analogWrite(6, 0);
    }else{
      if (a=='1')
      {
        
        digitalWrite(4, LOW);
        digitalWrite(7, LOW);
        analogWrite(5, 255);
        analogWrite(6, 255);
      }
      if (a=='2')
      {
        digitalWrite(4, LOW);
        digitalWrite(7, HIGH);
        analogWrite(5, 255);
        analogWrite(6, 255);
      }
      if (a=='3')
      {
        digitalWrite(4, HIGH);
        digitalWrite(7, LOW);
        analogWrite(5, 255);
        analogWrite(6, 255);
      }   
      if (a=='4')
      {
        digitalWrite(4, HIGH);
        digitalWrite(7, HIGH);
        analogWrite(5, 255);
        analogWrite(6, 255);
      }
    }
  }
  */
}

 
