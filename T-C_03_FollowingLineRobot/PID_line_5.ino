int sensor1 = A0;  // Left most sensor
int sensor2 = A1;
int sensor3 = A2;
int sensor4 = A3;
int sensor5 = A4;  // Right most sensor

int sensor[5] = { 0, 0, 0, 0, 0 };
int ENA = 10;
int motorInput1 = 8;
int motorInput2 = 13;
int motorInput3 = 11;
int motorInput4 = 12;
int ENB = 9;
int initial_motor_speed = 60;
float Kp = 0;
float Ki = 0;
float Kd = 0;
float error = 0, P = 0, I = 0, D = 0, PID_value = 0;
float previous_error = 0, previous_I = 0;
int minValues[6], maxValues[6], threshold[6];
int flag = 0;
int bientro1 = A0;

void setup() {
  pinMode(bientro1, INPUT);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(sensor5, INPUT);
  pinMode(motorInput1, OUTPUT);
  pinMode(motorInput2, OUTPUT);
  pinMode(motorInput3, OUTPUT);
  pinMode(motorInput4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  Serial.begin(9600);  //setting serial monitor at a default baund rate of 9600
  //delay(2000);
}
void loop() {



  {
    while (digitalRead(6)) {}
    delay(1000);
    calibrate();
    while (digitalRead(7)) {}
    delay(1000);
    while (1) {
      read_sensor_values();
      calculate_pid();
      motor_control();
    }
  }
}
void read_sensor_values() {

  sensor[0] = digitalRead(A1);
  sensor[1] = digitalRead(A2);
  sensor[2] = digitalRead(A3);
  sensor[3] = digitalRead(A4);
  sensor[4] = digitalRead(A5);

  if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1))
    error = 0;
  else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 1))
    error = 1;
  else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 0) && (sensor[4] == 1))
    error = 2;
  else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 0) && (sensor[4] == 0))
    error = 3;
  else if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1))
    error = -1;
  else if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 1))
    error = -2;
  else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 1))
    error = -3;
  else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 1))
    error = -4;
  else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1) && (sensor[4] == 0))
    error = 4;
  if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1) && (sensor[4] == 1)) {
     goc_quay();}
   if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 1)) {
     tien();
  }
  if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0) && (sensor[4] == 0)) {
     tien();
  }
}
void calculate_pid() {
  P = error;
  I = I + previous_I;
  D = error - previous_error;

  PID_value = (Kp * P) + (Ki * I) + (Kd * D);

  previous_I = I;
  previous_error = error;
  ;

  //Kp = analogRead(bientro1);
  Kp = 250;////28 436
  //Serial.println(Kp);
  //Kd = analogRead(bientro1);
  Kd = 890;////890 2000 1000                    toc do 60 kp 250 kd 776 ki 074
 //Serial.println(Kd);  //                   toc do 60 kp 250 kd 890 ki 08
  Ki = analogRead(bientro1);
  Ki = 0.8;///0.8
  Serial.println(Ki);
  //
}
void motor_control() {
  int left_motor_speed = initial_motor_speed + PID_value;
  int right_motor_speed = initial_motor_speed - PID_value;

  if (left_motor_speed > 255) {
    left_motor_speed = 60;
  }
  if (left_motor_speed < 0) {
    left_motor_speed = 0;
  }
  if (right_motor_speed > 255) {
    right_motor_speed = 60;
  }
  if (right_motor_speed < 0) {
    right_motor_speed = 0;
  }

  constrain(left_motor_speed, 0, 60);
  constrain(right_motor_speed, 0, 60);

  analogWrite(10, left_motor_speed);
  analogWrite(9, right_motor_speed);
  digitalWrite(8, HIGH);
  digitalWrite(13, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
  Serial.println(left_motor_speed);
  Serial.println(right_motor_speed);
}
void calibrate() {
  for (int i = 1; i < 6; i++) {
    minValues[i] = analogRead(i);
    maxValues[i] = analogRead(i);
  }

  for (int i = 0; i < 3000; i++) {
    digitalWrite(8, HIGH);
    digitalWrite(13, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    analogWrite(ENA, 50);
    analogWrite(ENB, 50);

    for (int i = 1; i < 6; i++) {
      if (analogRead(i) < minValues[i]) {
        minValues[i] = analogRead(i);
      }
      if (analogRead(i) > maxValues[i]) {
        maxValues[i] = analogRead(i);
      }
    }
  }

  for (int i = 1; i < 6; i++) {
    threshold[i] = (minValues[i] + maxValues[i]) / 2;
    // Serial.print(threshold[i]);
    // Serial.print("   ");
  }
  Serial.println();
  digitalWrite(8, HIGH);
  digitalWrite(13, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
void goc_quay(){
    digitalWrite(8, LOW);
    digitalWrite(13, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    analogWrite(ENA, 60);
    analogWrite(ENB, 60);
    delay(250);
}
void tien(){
    digitalWrite(8, HIGH);
    digitalWrite(13, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    analogWrite(ENA, 100);
    analogWrite(ENB, 100);
    delay(100);
}