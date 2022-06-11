#include <SoftwareSerial.h>
#define BT_RXD 13
#define BT_TXD 10

#define DIR_left 8
#define DIR_right 12
#define PWM_left 9
#define PWM_right 11
#define ECHO_left 2
#define TRIG_left 3
#define ECHO_front 4
#define TRIG_front 5
#define ECHO_right 6
#define TRIG_right 7

SoftwareSerial bluetooth(BT_TXD,BT_RXD);
char mode ='0';

long Left_Staight = 60;
long Right_Straight = 100;
long Threshold = 130;
long distance_front_pre=200;
long distance_left_pre=200;
long distance_right_pre=200;

long get_distance(int trig,int echo){
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  long duration = pulseIn (echo, HIGH);
  long distance = duration*17/1000;
  return distance;
}

void setup() {
  Serial.begin(9600);
  pinMode(DIR_left, OUTPUT);
  pinMode(DIR_right, OUTPUT);
  pinMode(PWM_left, OUTPUT);
  pinMode(PWM_right, OUTPUT);
  pinMode(ECHO_left,INPUT);
  pinMode(TRIG_left, OUTPUT);
  pinMode(ECHO_front,INPUT);
  pinMode(TRIG_front,OUTPUT);
  pinMode(ECHO_right,INPUT);
  pinMode(TRIG_right,OUTPUT);
  bluetooth.begin(9600);
}

void loop() { 
  if (bluetooth available()) {
    mode = bluetooth.read(); 
    distance_front_pre=200; 
    distance_left_pre=200; 
    distance_right_pre=200;
}
  if (mode == '0') {
    analogWrite (PWM_left, 0); 
    analogWrite (PWM_right, 0); 
    delay(50);
  else if (mode == '1') {
    long distance_front = get_distance (TRIG_Front, ECHO_front); 
    long distance_left = get_distance (TRIG_left, ECHO_left); 
    long distance_right = get_distance (TRIG_right, ECHO_right); 
    if(distance_front > 1000){
      distance_front = distance_front_pre;
    }
    if (distance_left > 1000){
      distance_left = distance_left_pre;
    }
    if (distance_right > 1000) {
      distance_right = distance_right_pre;
    } 
    distance_front_pre = distance_front; 
    distance_left_pre = distance_left; 
    distance_right_pre = distance_right;
  if (distance_front > Threshold) { 
    if (distance_right < 50) { 
      digitalWrite(DIR_right, HIGH);
      digitalWrite(DIR_left, HIGH);
      analogWrite(PWM_left, 0.6*Left_Straight);
      analogWrite(PWM_right, 0.6*Right_Straight);
      delay(50);      
      }
    else{
      digitalWrite(DIR_right, LOW);
      digitalWrite(DIR_left, HIGH);
      analogWrite(PWM_left, 2*Left_Straight);
      analogWrite(PWM_right, 2*Right_Staight);
      delay(1250);
      digitalWrite(DIR_right,HIGH));
      digitalWrite(DIR_left, HIGH);
      analogWrite(PWM_left, 0.6*Left_Straight);
      analogWrite(PWM_right, 0.5*Right_Staight);
      delay(1400);
    }
    }
    esle{
      digitalWrite(DIR_right, HIGH);
      digitalWrite(DIR_left, LOW);
      analogWrite(PWM_left, 3*Left_Straight);
      analogWrite(PWM_right, 2.5*Right_Staight);
      delay(1800);
      digitalWrite(DIR_right,HIGH));
      digitalWrite(DIR_left, HIGH);
      analogWrite(PWM_left, 0.6*Left_Straight);
      analogWrite(PWM_right, 0.5*Right_Staight);
      delay(500);
    }
  }
  else{
    delay(50);
  }
  
else if (mode == '1') {
  long distance_front = get_distance (TRIG_front, ECHO_front);
  if (distance_front > 1000){
    distance_front = distance_front_pre;
  }
  distance_front_pre = distance_front;
  if (distance_front > Threshold) {
    digitalWrite(DIR_right, HIGH);
    digitalWrite(DIR_left, HIGH);
    analogWrite (PWM_left, Left_Straight);
    analogWrite (PWM_right, Right_Straight);
    delay(50);
  }
  else {
    if(turn index<1){
      digitalWrite(DIR_right, LOW);
      digitalWrite(DIR_left, HIGH);
      analogWrite(PWM_left, Left_Straight);
      analogWrite(PWM_right, Right_Straight);
      delay(3000);
      digitalWrite(DIR_right, LOW);
      digitalWrite(DIR_left, HIGH);
      analogWrite(PWM_left, Left_Straight);
      analogWrite(PWM_right, Right_Straight);
      delay(2000);
      digitalWrite(DIR_right, LOW);
      digitalWrite(DIR_left, HIGH);
      analogWrite(PWM_left, Left_Straight);
      analogWrite(PWM_right, Right_Straight);
      delay(3000);

      turn index = turn index + 1
    }
    else{
      digitalWrite(DIR_right, HIGH);
      digitalWrite(DIR_left, HIGH);
      analogWrite(PWM_left, Left_Straight);
      analogWrite(PWM_right, Right_Straight);
      delay(50);
    }
  }
}