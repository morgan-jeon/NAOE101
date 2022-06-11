#define ECHO1 2
#define ECHO2 4
#define ECHO3 6

#define TRIG1 3
#define TRIG2 5
#define TRIG3 7

#define MOTOR1A 10
#define MOTOR1B 11
#define MOTOR2A 12
#define MOTOR2B 13

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
    analogWrite(MOTOR1B, speed);
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
    analogWrite(MOTOR2B, speed);
  }
}

bool left(){
  int dis = 0;
  if(distance(TRIG1, ECHO1) > 200){
    dis = 200;
  } else {
    dis = distance(TRIG1, ECHO1);
  }
  if(dis < 40){
    return(0);
  } else {
    return(1);
  }
}

bool right(){
  int dis = 0;
  if(distance(TRIG3, ECHO3) > 200){
    dis = 200;
  } else {
    dis = distance(TRIG3, ECHO3);
  }
  if(dis < 40){
    return(0);
  } else {
    return(1);
  }
}

bool center(){
  int dis = 0;
  if(distance(TRIG2, ECHO2) > 200){
    dis = 200;
  } else {
    dis = distance(TRIG2, ECHO2);
  }
  if(dis < 40){
    return(0);
  } else {
    return(1);
  }
}

void straight(int time){
  motor1(100);
  motor2(100);
  dalay(time);
  motor1(0);
  motor2(0);
}

void turn_left(){
  motor1(100);
  motor2(0);
  delay(50);
  motor1(0);
  motor2(0);
}

void turn_right(){
  motor1(0);
  motor2(100);
  delay(50);
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
}

void loop() {
  delay(100);
  int d1 = distance(TRIG1, ECHO1);
  int d2 = distance(TRIG2, ECHO2);
  int d3 = distance(TRIG3, ECHO3);
  Serial.print("## ");
  Serial.print(d1);
  Serial.print("\t");
  Serial.print(d2);
  Serial.print("\t");
  Serial.print(d3);
  Serial.print("\t");
  Serial.println();

  while(1){
    while( !center() ){
      // go_straight
    }
    if( center() ){
      if( right() ){
        while(!center()){
          // turn_left
        }
      }
      if( left() ){
        while(!center()){
          // turn_right
        }
      }
    }
  }
}