#define ECHO1 8 //digital
#define ECHO2 11 //digital
#define ECHO3 4 //digital

#define TRIG1 7 //digital
#define TRIG2 10 //digital
#define TRIG3 2 //digital

#define MOTOR1A 3 //pwm
#define MOTOR1B 5 //pwm
#define MOTOR2A 6 //pwm
#define MOTOR2B 9 //pwm

#define LIMIT 20

long distance(int TRIG, int ECHO) {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG,LOW);
  long duration = pulseIn(ECHO, HIGH);
  long distance = duration*17/1000;
  return distance;
}

void motor1(int speed) {
  if(speed > 0){
    analogWrite(MOTOR1A, speed);
    analogWrite(MOTOR1B, 0);
  }
  else if(speed == 0){
    analogWrite(MOTOR1A, 0);
    analogWrite(MOTOR1B, 0);
  }
  else if(speed < 0){
    analogWrite(MOTOR1A, 0);
    analogWrite(MOTOR1B, -1*speed);
  }
}

void motor2(int speed) {
  if(speed > 0){
    analogWrite(MOTOR2A, speed);
    analogWrite(MOTOR2B, 0);
  }
  else if(speed == 0){
    analogWrite(MOTOR2A, 0);
    analogWrite(MOTOR2B, 0);
  }
  else if(speed < 0){
    analogWrite(MOTOR2A, 0);
    analogWrite(MOTOR2B, -1*speed);
  }
}

bool left(){
  int dis = 0;
  if(distance(TRIG1, ECHO1) > 200){
    dis = 200;
  } else {
    dis = distance(TRIG1, ECHO1);
  }
  if(dis < LIMIT){
    return(1);
  } else {
    return(0);
  }
}

bool right(){
  int dis = 0;
  if(distance(TRIG3, ECHO3) > 200){
    dis = 200;
  } else {
    dis = distance(TRIG3, ECHO3);
  }
  if(dis < LIMIT){
    return(1);
  } else {
    return(0);
  }
}

bool center(){
  int dis = 0;
  if(distance(TRIG2, ECHO2) > 200){
    dis = 200;
  } else {
    dis = distance(TRIG2, ECHO2);
  }
  if(dis < LIMIT){
    return(1);
  } else {
    return(0);
  }
}

void straight(int time) {
  motor1(240);
  motor2(255);
  if(time != 9999){
    delay(time*1000);
    motor1(0);
    motor2(0);
  }
}

void turn_left(int time) {
  motor1(255);
  motor2(-255);
  delay(time*1000);
  motor1(0);
  motor2(0);
}

void turn_right(int time) {
  motor1(-255);
  motor2(255);
  delay(time*1000);
  motor1(0);
  motor2(0);
}

void setup() {
  Serial.begin(9600);
  pinMode(ECHO1, INPUT);
  pinMode(TRIG1, OUTPUT);
  pinMode(ECHO2, INPUT);
  pinMode(TRIG2, OUTPUT);
  pinMode(ECHO3, INPUT);
  pinMode(TRIG3, OUTPUT);
  pinMode(MOTOR1A, OUTPUT);
  pinMode(MOTOR1B, OUTPUT);
  pinMode(MOTOR2A, OUTPUT);
  pinMode(MOTOR2B, OUTPUT);

//  delay(2000);
//  straight(9);
//  delay(500);
//  turn_left(2.2);
//  delay(800);
//  straight(2);
//  delay(1000);
//  turn_left(2.2);
//  delay(800);
//  straight(8);
//  delay(500);
//  turn_right(2.2);
//  delay(800);
//  straight(2);
//  delay(1000);
//  turn_right(2.2);
//  delay(800);
//  straight(8);
//  delay(500);
//  turn_left(2.2);
//  delay(800);
//  straight(2);
//  delay(1000);
//  turn_left(2.2);
//  delay(800);
//  straight(9);
//  
//  straight(1);
  delay(1000);
  straight(9);
  delay(500);
  turn_left(2.3);
  delay(100);
  straight(2);
  delay(1000);
  turn_left(3);
  delay(800);
  straight(4);
  delay(500);
  turn_right(2.5);
  delay(2000);
  straight(8);

//  delay(2000);
//  while(!center()){
//    straight(9999);  
//  }
//  straight(9999);
//  Serial.print("straight");
//  if(center()){
//    Serial.print("center");
//    straight(0);
//    delay(1000);
//    while(center()){
//      Serial.print("left");
//      turn_left(1);
//      delay(500);
//    }
//    straight(9999);
//    if(center()){
//      Serial.print("center");
//      straight(0);
//      delay(1000);
//      while(center()){
//        turn_left(1);
//        delay(500);
//      }
//      straight(9999);
//      if(center()){
//        straight(0);
//        delay(1000);
//        while(center()){
//          turn_left(1);
//          delay(500);
//        }
//        straight(9999);
//        if(center()){
//          straight(0);
//          delay(1000);
//          while(center()){
//            turn_right(1);
//            delay(500);
//          }
//          straight(2);
//          delay(1000);
//          turn_right(1);
//          delay(500); 
//
//          straight(9999);
//          if(center()){
//            straight(0);
//            delay(1000);
//            while(center()){
//              turn_left(1);
//              delay(500);
//            }
//            straight(9999);
//            if(center()){
//              straight(0);
//            }
//          }  
//        } 
//      } 
//    }
//  }
}

void loop() {
   delay(100);
//  int d1 = distance(TRIG1, ECHO1);
//  int d2 = distance(TRIG2, ECHO2);
//  int d3 = distance(TRIG3, ECHO3);
  Serial.print("## ");
  Serial.print(left());
  Serial.print("\t");
  Serial.print(center());
  Serial.print("\t");
  Serial.print(right());
  Serial.print("\t");
  Serial.println();
 
//  straight(1);
//  delay(1000);
//  turn_left();
//  delay(1000);
//  turn_right();
//  delay(1000);
}