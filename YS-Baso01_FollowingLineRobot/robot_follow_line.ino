int stop_distance = 18;
int trigPin = 5;
int echoPin = 4;

int sensor1 = A3;
int sensor2 = A2;
int sensor3 = A1;
int sensor4 = A0;
int sensor[4] = { 0, 0, 0, 0 };

int ENA = 9;
int motorInput1 = 8;
int motorInput2 = 7;
int motorInput3 = 12;
int motorInput4 = 11;
int ENB = 10;

int initial_motor_speed = 80;

float Kp = 25;
float Ki = 0;
float Kd = 15;

long duration;
int distance;

float error = 0, P = 0, I = 0, D = 0, PID_value = 0;
float previous_error = 0, previous_I = 0;

int flag = 0;

void setup() {
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);

  pinMode(motorInput1, OUTPUT);
  pinMode(motorInput2, OUTPUT);
  pinMode(motorInput3, OUTPUT);
  pinMode(motorInput4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  sensor[0] = digitalRead(sensor1);
  sensor[1] = digitalRead(sensor2);
  sensor[2] = digitalRead(sensor3);
  sensor[3] = digitalRead(sensor4);

  // Serial.print("Sensor[0]: ");
  // Serial.println(sensor[0]);
  // Serial.print("Sensor[1]: ");
  // Serial.println(sensor[1]);
  // Serial.print("Sensor[2]: ");
  // Serial.println(sensor[2]);
  // Serial.print("Sensor[3]: ");
  // Serial.println(sensor[3]);
  // Serial.println("");
  // delay(initial_motor_speed0);


  if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 0)) {
    analogWrite(ENA, (initial_motor_speed * 0.6));
    analogWrite(ENB, (initial_motor_speed * 0.6));
    digitalWrite(motorInput1, LOW);
    digitalWrite(motorInput2, HIGH);
    digitalWrite(motorInput3, HIGH);
    digitalWrite(motorInput4, LOW);
  }
  if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[3] == 0)) {
    analogWrite(ENA, (initial_motor_speed * 0.6));
    analogWrite(ENB, (initial_motor_speed * 0.6));
    digitalWrite(motorInput1, LOW);
    digitalWrite(motorInput2, HIGH);
    digitalWrite(motorInput3, HIGH);
    digitalWrite(motorInput4, LOW);
  }
  if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 0)) {
    analogWrite(ENA, (initial_motor_speed * 0.6));
    analogWrite(ENB, (initial_motor_speed * 0.6));
    digitalWrite(motorInput1, LOW);
    digitalWrite(motorInput2, HIGH);
    digitalWrite(motorInput3, HIGH);
    digitalWrite(motorInput4, LOW);
  }

  if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 0)) {
    analogWrite(ENA, initial_motor_speed * 0.42);
    analogWrite(ENB, initial_motor_speed * 0.42);
    right();
  }
  if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0)) {
    analogWrite(ENA, initial_motor_speed * 0.42);
    analogWrite(ENB, initial_motor_speed * 0.42);
    right();
  }
  if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 0)) {
    analogWrite(ENA, initial_motor_speed * 0.42);
    analogWrite(ENB, initial_motor_speed * 0.42);
    right();
  }

  if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1)) {
    analogWrite(ENA, initial_motor_speed * 0.42);
    analogWrite(ENB, initial_motor_speed * 0.42);
    left();
  }
  if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[3] == 1)) {
    analogWrite(ENA, initial_motor_speed * 0.42);
    analogWrite(ENB, initial_motor_speed * 0.42);
    left();
  }
  if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1)) {
    analogWrite(ENA, initial_motor_speed * 0.42);
    analogWrite(ENB, initial_motor_speed * 0.42);
    left();
  }

  // if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0)) {
  //   analogWrite(ENA, initial_motor_speed * 0.5);
  //   analogWrite(ENB, initial_motor_speed * 0.5);
  //   sharpLeftTurn();
  // }

  // if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1)) {
  //   analogWrite(ENA, initial_motor_speed);
  //   analogWrite(ENB, initial_motor_speed);
  //   digitalWrite(motorInput1, HIGH);
  //   digitalWrite(motorInput2, LOW);
  //   digitalWrite(motorInput3, LOW);
  //   digitalWrite(motorInput4, HIGH);
  // }
  // if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1)) {
  //   analogWrite(ENA, initial_motor_speed);
  //   analogWrite(ENB, initial_motor_speed);
  //   digitalWrite(motorInput1, HIGH);
  //   digitalWrite(motorInput2, LOW);
  //   digitalWrite(motorInput3, LOW);
  //   digitalWrite(motorInput4, HIGH);
  // }
  // if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 0)) {
  //   analogWrite(ENA, initial_motor_speed);
  //   analogWrite(ENB, initial_motor_speed);
  //   digitalWrite(motorInput1, HIGH);
  //   digitalWrite(motorInput2, LOW);
  //   digitalWrite(motorInput3, LOW);
  //   digitalWrite(motorInput4, HIGH);
  // }

  if (distance < stop_distance)  // nếu khoảng cách nhỏ hơn giới hạn
  {

    analogWrite(ENA, 100);  // tốc độ động cơ a ban đầu 120 ( 0 - 255)
    analogWrite(ENB, 100);
    digitalWrite(motorInput1, HIGH);  // cho xe robot chạy lùi 1 đoạn
    digitalWrite(motorInput2, LOW);
    digitalWrite(motorInput3, LOW);
    digitalWrite(motorInput4, HIGH);
    delay(400);

    analogWrite(ENA, 40);  // tốc độ động cơ a ban đầu 120 ( 0 - 255)
    analogWrite(ENB, 40);
    digitalWrite(motorInput1, LOW);
    digitalWrite(motorInput2, LOW);
    digitalWrite(motorInput3, LOW);
    digitalWrite(motorInput4, LOW);
    delay(300);


    // analogWrite(ENA, 50);  // tốc độ động cơ a ban đầu 120 ( 0 - 255)
    // analogWrite(ENB, 50);
    // digitalWrite(motorInput1, LOW);  // cho xe robot xoay phải 1 đoạn
    // digitalWrite(motorInput2, HIGH);
    // digitalWrite(motorInput3, LOW);
    // digitalWrite(motorInput4, LOW);
    // delay(550);
    // digitalWrite(motorInput1, LOW);
    // digitalWrite(motorInput2, LOW);
    // digitalWrite(motorInput3, LOW);
    // digitalWrite(motorInput4, LOW);
    // delay(200);

    analogWrite(ENA, 70);  // tốc độ động cơ a ban đầu 120 ( 0 - 255)
    analogWrite(ENB, 70);
    digitalWrite(motorInput1, LOW);  //cho xe robot đi thẳng 1 đoạn
    digitalWrite(motorInput2, HIGH);
    digitalWrite(motorInput3, HIGH);
    digitalWrite(motorInput4, LOW);
    delay(450);
    digitalWrite(motorInput1, LOW);
    digitalWrite(motorInput2, LOW);
    digitalWrite(motorInput3, LOW);
    digitalWrite(motorInput4, LOW);
    delay(200);

    analogWrite(ENA, 100);  // tốc độ động cơ a ban đầu 120 ( 0 - 255)
    analogWrite(ENB, 100);
    digitalWrite(motorInput1, LOW);
    digitalWrite(motorInput2, LOW);
    digitalWrite(motorInput3, HIGH);
    digitalWrite(motorInput4, LOW);
    delay(400);

    digitalWrite(motorInput1, LOW);
    digitalWrite(motorInput2, LOW);
    digitalWrite(motorInput3, LOW);
    digitalWrite(motorInput4, LOW);
    delay(200);

    analogWrite(ENA, 70);  // tốc độ động cơ a ban đầu 120 ( 0 - 255)
    analogWrite(ENB, 70);
    digitalWrite(motorInput1, LOW);  //cho xe robot đi thẳng 1 đoạn
    digitalWrite(motorInput2, HIGH);
    digitalWrite(motorInput3, HIGH);
    digitalWrite(motorInput4, LOW);
    delay(450);
    digitalWrite(motorInput1, LOW);
    digitalWrite(motorInput2, LOW);
    digitalWrite(motorInput3, LOW);
    digitalWrite(motorInput4, LOW);
    delay(200);

    analogWrite(ENA, 70);  // tốc độ động cơ a ban đầu 120 ( 0 - 255)
    analogWrite(ENB, 70);
    digitalWrite(motorInput1, LOW);  // cho xe robot xoay sang trái
    digitalWrite(motorInput2, LOW);
    digitalWrite(motorInput3, HIGH);
    digitalWrite(motorInput4, LOW);
    delay(400);
    digitalWrite(motorInput1, LOW);
    digitalWrite(motorInput2, LOW);
    digitalWrite(motorInput3, LOW);
    digitalWrite(motorInput4, LOW);
    delay(200);

    analogWrite(ENA, 70);  // tốc độ động cơ a ban đầu 120 ( 0 - 255)
    analogWrite(ENB, 70);
    digitalWrite(motorInput1, LOW);  //cho xe robot đi thẳng 1 đoạn
    digitalWrite(motorInput2, HIGH);
    digitalWrite(motorInput3, HIGH);
    digitalWrite(motorInput4, LOW);
    delay(500);
    digitalWrite(motorInput1, LOW);
    digitalWrite(motorInput2, LOW);
    digitalWrite(motorInput3, LOW);
    digitalWrite(motorInput4, LOW);
    delay(200);




    //   ///////////////////
    //   analogWrite(ENA, 70);  // tốc độ động cơ a ban đầu 120 ( 0 - 255)
    //   analogWrite(ENB, 70);
    //   digitalWrite(motorInput1, LOW);  //cho xe robot đi thẳng 1 đoạn
    //   digitalWrite(motorInput2, HIGH);
    //   digitalWrite(motorInput3, HIGH);
    //   digitalWrite(motorInput4, LOW);
    //   delay(600);
    //   digitalWrite(motorInput1, LOW);
    //   digitalWrite(motorInput2, LOW);
    //   digitalWrite(motorInput3, LOW);
    //   digitalWrite(motorInput4, LOW);
    //   delay(200);

    //   ////////////////////////
    //   analogWrite(ENA, 50);  // tốc độ động cơ a ban đầu 120 ( 0 - 255)
    //   analogWrite(ENB, 50);
    //   digitalWrite(motorInput1, LOW);  //cho xe robot xoay phải 1 đoạn
    //   digitalWrite(motorInput2, HIGH);
    //   digitalWrite(motorInput3, LOW);
    //   digitalWrite(motorInput4, LOW);
    //   delay(500);
    //   digitalWrite(motorInput1, LOW);
    //   digitalWrite(motorInput2, LOW);
    //   digitalWrite(motorInput3, LOW);
    //   digitalWrite(motorInput4, LOW);
    //   delay(200);

    //   analogWrite(ENA, 70);  // tốc độ động cơ a ban đầu 120 ( 0 - 255)
    //   analogWrite(ENB, 70);
    //   digitalWrite(motorInput1, LOW);  //cho xe robot đi thẳng 1
    //   digitalWrite(motorInput2, HIGH);
    //   digitalWrite(motorInput3, HIGH);
    //   digitalWrite(motorInput4, LOW);
  }
}

// void read_sensor_values() {
//   sensor[0] = digitalRead(sensor1);
//   sensor[1] = digitalRead(sensor2);
//   sensor[2] = digitalRead(sensor3);
//   sensor[3] = digitalRead(sensor4);

//   if ((sensor[0] == 1) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0))
//     error = -3;
//   else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 0))
//     error = -2;
//   else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 0) && (sensor[3] == 0))
//     error = -1;
//   else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 0))
//     error = 0;
//   else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[3] == 0))
//     error = 1;
//   else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 1) && (sensor[3] == 1))
//     error = 2;
//   else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 1))
//     error = 3;
//   else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 0))
//     error = initial_motor_speed;
//   else if ((sensor[0] == 0) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1))
//     error = 101;
//   else if ((sensor[0] == 0) && (sensor[1] == 0) && (sensor[2] == 0) && (sensor[3] == 0))
//     error = 102;
//   else if ((sensor[0] == 1) && (sensor[1] == 1) && (sensor[2] == 1) && (sensor[3] == 1))
//     error = 103;
// }

// void calculate_pid() {
//   P = error;
//   I = I + previous_I;
//   D = error - previous_error;

//   PID_value = (Kp * P) + (Ki * I) + (Kd * D);  // error = 3; PID = 120 motor phai chay nhanh hon

//   previous_I = I;
//   previous_error = error;
// }

// void motor_control() {

//   int left_motor_speed = initial_motor_speed - PID_value;
//   int right_motor_speed = initial_motor_speed + PID_value;

//   left_motor_speed = constrain(left_motor_speed, 0, initial_motor_speed);
//   right_motor_speed = constrain(right_motor_speed, 0, initial_motor_speed);

//   analogWrite(ENA, left_motor_speed - 23);
//   analogWrite(ENB, right_motor_speed);

//   forward();
// }

void forward() {
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, HIGH);
  digitalWrite(motorInput3, HIGH);
  digitalWrite(motorInput4, LOW);
}
void reverse() {
  digitalWrite(motorInput1, HIGH);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, HIGH);
}
void right() {
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, HIGH);
  digitalWrite(motorInput4, LOW);
}
void left() {
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, HIGH);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, LOW);
}
void sharpRightTurn() {
  digitalWrite(motorInput1, HIGH);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, HIGH);
  digitalWrite(motorInput4, LOW);
}
void sharpLeftTurn() {
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, HIGH);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, HIGH);
}
void stop_bot() {
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, LOW);
  digitalWrite(motorInput3, LOW);
  digitalWrite(motorInput4, LOW);
}