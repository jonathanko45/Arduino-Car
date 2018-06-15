#include <SoftwareSerial.h>
SoftwareSerial mySerial(8, 12); // RX, TX

int a;
int mode = 0;
long duration, distance;

void setup() {
  // initalizing the pin locations and input/output
  pinMode(8, INPUT);
  pinMode(2, OUTPUT);   //line follower LED
  pinMode(4, OUTPUT);   //left motor
  pinMode(7, OUTPUT);   //right motor
  pinMode(12, INPUT);
  pinMode(13, OUTPUT);
  pinMode(A0, INPUT);   //light sensor
  // initalizing the bitrate per second between the arduino and bluetooth
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  // when the bluetooth sensor detects input form the moblie device
  while (mySerial.available()){
    // reads the input and puts it into a variable
    a = mySerial.read();
    //switches mode to line follower
    if (a == 'J')
    {
      mode = 1;
    }

    bool detect;
    int direct = 0;
    
    while (mode == 1){
      // turns on led
      digitalWrite(2, HIGH);
      // turns on light sesor and reads in its input
      detect = digitalRead(A0);
      a = mySerial.read();
      if (a == 'H')
      {
        mode = 0;
      }
      if (detect)
      {
        // drives the car to the right
        // left motor is forwards
        digitalWrite(4, HIGH);
        // right motor is bacwards
        digitalWrite(7, LOW);
        // second num sets the speed of the motors
        analogWrite(5, 80);
        analogWrite(6, 120);
      }
      else
      {
        digitalWrite(4, LOW);
        digitalWrite(7, HIGH);
        analogWrite(5, 120);
        analogWrite(6, 80);
      }
    }
    digitalWrite(2, LOW);
    
    /*
    while (mode == 1){
      a = mySerial.read();
       if (a == 'H')
      {
        mode = 0;
      }
      digitalWrite(13, LOW);
      delayMicroseconds(2);
      Serial.print("working  ");
      digitalWrite(13, HIGH);
      delayMicroseconds(10);
      
      digitalWrite(13, LOW);
      duration = pulseIn(12, HIGH);
      
      distance = duration / 58.2;
      if (distance <= 50){
        digitalWrite(4, HIGH);
        digitalWrite(7, LOW);
        analogWrite(5, 130);
        analogWrite(6, 130);
      }else{
        digitalWrite(4, LOW);
        digitalWrite(7, LOW);
        analogWrite(5, 190);
        analogWrite(6, 190);
      }
    }
    */
    // reads in the input and runs the motor appropriately
    if (a=='F')
    {
      digitalWrite(4, LOW);
      digitalWrite(7, LOW);
      analogWrite(5, 255);
      analogWrite(6, 255);
    }
    else if (a=='R')
    {
      digitalWrite(4, LOW);
      digitalWrite(7, HIGH);
      analogWrite(5, 130);
      analogWrite(6, 130);
    }
    else if (a == 'L')
    {
      digitalWrite(4, HIGH);
      digitalWrite(7, LOW);
      analogWrite(5, 130);
      analogWrite(6, 130);
    }   
    else if (a == 'B')
    {
      digitalWrite(4, HIGH);
      digitalWrite(7, HIGH);
      analogWrite(5, 255);
      analogWrite(6, 255);
    }
    else if (a == 'G')
    {
      digitalWrite(4, LOW);
      digitalWrite(7, LOW);
      analogWrite(5, 150);
      analogWrite(6, 255);
    }
    else if (a == 'I')
    {
      digitalWrite(4, LOW);
      digitalWrite(7, LOW);
      analogWrite(5, 255);
      analogWrite(6, 150);
    }
    else
    {
      analogWrite(5, 0);
      analogWrite(6, 0);
    }
  }
}
