#define rc3 A0 // receiver chanel 3 on pin 9
#define rc4 A1 // receiver chanel 4 on pin 10
#define spd 3 // PWM pin on L298N      left motor
#define spd1 11 // PWM pin on L298N    right motor
#define pin1 4 // in 1 pin on L298N to pin 4 on ARDUINO    left motor
#define pin2 5 // in 2 pin on L298N to pin 5 on ARDUINO    left motor
#define pin3 12 // in 3 pin on L298N to pin 12 on ARDUINO  right motor 
#define pin4 13 // in 4 pin on L298N to pin 13 on ARDUINO   right motor
 
int ch3; // value of chanel 3 of the receiver
int ch4; // value of chanel 4 of the receiver
int u;
int d;
int l;
int r;
int n;


void setup() {

  pinMode (rc3, INPUT);
  pinMode (rc4, INPUT);
  pinMode (spd, OUTPUT);
  pinMode (spd1, OUTPUT);
  pinMode (pin1, OUTPUT);
  pinMode (pin2, OUTPUT);
  pinMode (pin3, OUTPUT);
  pinMode (pin4, OUTPUT);
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
  Serial.begin(9600);
}
  void loop(){
  ch3 = pulseIn(rc3, HIGH);
  ch4 = pulseIn(rc4, HIGH);

  Serial.println(ch3);
  Serial.println(ch4);
   
u = (255*(ch3-1415))/245;
d = (255/170)*(1270-ch3);
l = (1620-ch4)*(255/230);
r = (ch4-1130)*(255/245);
n = 0;

if (ch3 == 0)
  {
   analogWrite(spd,n);
   analogWrite(spd1,n);
   digitalWrite(pin1, LOW);
   digitalWrite(pin2, LOW);
   digitalWrite(pin3, LOW);
   digitalWrite(pin4, LOW);
  }
  
if (ch3 > 1415 && ch4>1390)
  {
   analogWrite(spd,u);
   analogWrite(spd1,u+l);
   digitalWrite(pin1, LOW);
   digitalWrite(pin2, HIGH);
   digitalWrite(pin3, LOW);
   digitalWrite(pin4, HIGH);
  }

if (ch3 > 1415 && ch4 < 1375)
  {
   analogWrite(spd,u+r);
   analogWrite(spd1,u);
   digitalWrite(pin1, LOW);
   digitalWrite(pin2, HIGH);
   digitalWrite(pin3, LOW);
   digitalWrite(pin4, HIGH);
  }
  
if (ch3 > 1415 && ch4>=1375 && ch4<=1390 )
  {
   analogWrite(spd,u);
   analogWrite(spd1,u);
   digitalWrite(pin1, LOW);
   digitalWrite(pin2, HIGH);
   digitalWrite(pin3, LOW);
   digitalWrite(pin4, HIGH);
  }
  
if (ch3 < 1270 && ch4>1390)
  {
  analogWrite(spd,d);
   analogWrite(spd1,d+l);
   digitalWrite(pin1, HIGH);
   digitalWrite(pin2, LOW);
   digitalWrite(pin3, HIGH);
   digitalWrite(pin4, LOW);
  }

if (ch3 < 1270 && ch4<1375 && ch3!=0)
  {
   analogWrite(spd,d+r);
   analogWrite(spd1,d);
   digitalWrite(pin1, HIGH);
   digitalWrite(pin2, LOW);
   digitalWrite(pin3, HIGH);
   digitalWrite(pin4, LOW);
  }

if (ch3 < 1270 && ch4<= 1390 && ch4>=1375)
  {
   analogWrite(spd,d);
   analogWrite(spd1,d);
   digitalWrite(pin1, HIGH);
   digitalWrite(pin2, LOW);
   digitalWrite(pin3,HIGH);
   digitalWrite(pin4, LOW);
  }
  
if (ch3 >= 1270 && ch3<=1415 && ch4>1390)
  {
   analogWrite(spd,n);
   analogWrite(spd1,l);
   digitalWrite(pin1, LOW);
   digitalWrite(pin2, LOW);
   digitalWrite(pin3, LOW);
   digitalWrite(pin4, HIGH);
  }

if (ch3 >= 1270 && ch3<=1415 && ch4<1375)
  {
   analogWrite(spd,r);
   analogWrite(spd1,n);
   digitalWrite(pin1, LOW);
   digitalWrite(pin2, LOW);
   digitalWrite(pin3, LOW);
   digitalWrite(pin4, HIGH);
  }
if (ch3 >= 1270 && ch3<=1415 && ch4>=1375 && ch4<=1390)
  {
   analogWrite(spd,n);
   analogWrite(spd1,n);
   digitalWrite(pin1, LOW);
   digitalWrite(pin2, LOW);
   digitalWrite(pin3, LOW);
   digitalWrite(pin4, LOW);
  }

}

