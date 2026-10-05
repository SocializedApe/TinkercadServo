// C++ code
//
/*
  Sweep

  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 8 Nov 2013  by Scott Fitzgerald
  http://www.arduino.cc/en/Tutorial/Sweep
*/


#include <Servo.h>

//config shit
int startPos = 150;
int hitPos = 180;

//hits every x tacts
//tact is like ~15ms?
//right now this just adds delay
float modifier=1;
int every1 = 20;
int every2 = 80;
int every3 = 60;

int downtime=10;


//sound in hz
int sound1=180;
int sound2=60;
int sound3=120;


//accumulate cats
int acc1 = 0;
int acc2 = 0;
int acc3 = 0;






Servo servo_1;
Servo servo_2;
Servo servo_3;
Servo servo_4; 

//pin, min pulse, max pulse:

void setup()
{
  	servo_1.attach(9, 500, 2500);
	servo_2.attach(10, 500, 2500);
	servo_3.attach(11, 500, 2500);
  	servo_4.attach(12,500,2500);
  	
  	pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
  	pinMode(6,OUTPUT);
  
  	pinMode(A0,INPUT);
  	Serial.begin(9600);
  
  	servo_1.write(startPos);
  	servo_2.write(startPos);
  	servo_3.write(startPos);
  	servo_4.write(startPos);
  
  	
}


//old hit code ide to also add
void Hit(int ledPin)
{
  digitalWrite(ledPin,HIGH);
  delay(5);
  digitalWrite(ledPin,LOW);
}



void loop()
{
  
  unsigned long tactStart=millis();
  
  acc1++;
  acc2++;
  acc3++;
  
  float modifier=0.5+analogRead(A0)/500.0;
  //int e1 = every1*modifier;
  //int e2 = every2*modifier;
  //int e3 = every3*modifier;
  int e1=every1;
  int e2=every2;
  int e3=every3;
  Serial.println(modifier);

  //
  if (acc1 == e1) {
    servo_1.write(hitPos);
    digitalWrite(2, HIGH);
    tone(6,sound1,50);
    acc1 = 0;               
  }
  if (acc1 == downtime) {
    servo_1.write(startPos);
    digitalWrite(2, LOW);
  }

  // servo 2
  if (acc2 == e2) {
    servo_2.write(hitPos);
    digitalWrite(3, HIGH);
    tone(6,sound2,50);
    acc2 = 0;
  }
  if (acc2 == downtime) {
    servo_2.write(startPos);
    digitalWrite(3, LOW);
  }

  // servo 3
  if (acc3 == e3) {
    servo_3.write(hitPos);
    digitalWrite(4, HIGH);
    
    tone(6,sound3,50);
    acc3 = 0;
  }
  if (acc3 == downtime) {
    servo_3.write(startPos);
    digitalWrite(4, LOW);
  }
  millis()-tactStart;
  
  delay(15*modifier-(millis()-tactStart));
}
//hits every x tacts