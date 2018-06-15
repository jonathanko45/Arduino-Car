#include <SoftwareSerial.h>
SoftwareSerial BT(10, 11); 
// creates a "virtual" serial port/UART
// connect BT module TX to D10
// connect BT module RX to D11
// connect BT Vcc to 5V, GND to GND
void setup()  
{
  // set digital pin to control as an output
  pinMode(9, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  // set the data rate for the SoftwareSerial port
  BT.begin(9600);
  // Send test message to other device
  BT.println("Hello from Arduino");
}
char a; // stores incoming character from other device
void loop() 
{
  if (BT.available())
  // if text arrived in from BT serial...
  {
    a=(BT.read());
    if (a=='1')
    {
      digitalWrite(9, HIGH);
      digitalWrite(3, HIGH);
      delay(100);
      digitalWrite(9,LOW);
      digitalWrite(3,LOW);
      BT.println("Forward");
    }
    if (a=='2')
    {
      digitalWrite(9, LOW);
      digitalWrite(3, LOW);
      BT.println("LED off");
    }
    if (a=='3')
    {
      digitalWrite(9, HIGH);
      digitalWrite(3, LOW);
      delay(60);
      digitalWrite(9,LOW);
      digitalWrite(3,LOW);
      BT.println("Left");
    }   
    if (a=='4')
    {
      digitalWrite(9, LOW);
      digitalWrite(3, HIGH);
      delay(60);
      digitalWrite(9,LOW);
      digitalWrite(3,LOW);
    }
  }
}
