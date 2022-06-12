#define ECHO1 14 //digital
#define ECHO2 16 //digital
#define ECHO3 18 //digital

#define TRIG1 15 //digital
#define TRIG2 17 //digital
#define TRIG3 19 //digital

#define MOTOR1A 3 //pwm
#define MOTOR1B 5 //pwm
#define MOTOR2A 6 //pwm
#define MOTOR2B 9 //pwm

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

void straight(int time) {
  motor1(100);
  motor2(100);
  delayMicroseconds(2);
  motor1(0);
  motor2(0);
}

void turn_left() {
  motor1(100);
  motor2(0);
  delayMicroseconds(2);
  motor1(0);
  motor2(0);
}

void turn_right() {
  motor1(0);
  motor2(100);
  delayMicroseconds(2);
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

  straight(0);
  turn_left();
  turn_right();
  straight(0);
}