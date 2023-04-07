//Khai báo cảm biến siêu âm
#define echopin 11 // echo pin
#define trigpin 10 // Trigger pin
// Khai báo chân kết nối của cảm biến hồng ngoại và động cơ
const int irSensor1 = A0;
const int irSensor2 = A1;
const int irSensor3 = A2;
const int irSensor4 = A3;
const int irSensor5 = A4;
// Khai báo chân kết nối của động cơ
const int ena = 9;
const int in1 = 2;
const int in2 = 4;
const int enb = 3;
const int in3 = 6;
const int in4 = 7;

int  frontdist;
long duration;

int setdist;
void setup() {
  Serial.begin(9600);

  // Khai báo các chân kết nối của Arduino là input/output
  pinMode(irSensor1, INPUT);
  pinMode(irSensor2, INPUT);
  pinMode(irSensor3, INPUT);
  pinMode(irSensor4, INPUT);
  pinMode(irSensor5, INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(echopin , INPUT);
  pinMode(trigpin , OUTPUT);


}
void loop() {
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin, HIGH);
  frontdist = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(frontdist);


  int left_sensor_state  = digitalRead(irSensor1) && (irSensor2);
  int s_sensor_state = digitalRead( irSensor3);
  int right_sensor_state = digitalRead(irSensor4) && (irSensor5);
  int sensorValue1 = digitalRead(irSensor1);
  int sensorValue2 = digitalRead(irSensor2);
  int sensorValue3 = digitalRead(irSensor3);
  int sensorValue4 = digitalRead(irSensor4);
  int sensorValue5 = digitalRead(irSensor5);




  // THẲNG
  if (frontdist > 30) 
    {if (sensorValue1 == HIGH && sensorValue2 == HIGH && sensorValue3 == LOW && sensorValue4 == HIGH && sensorValue5 == HIGH) {
      motorForward();
    }
    else if (sensorValue1 == LOW && sensorValue2 == LOW && sensorValue3 == HIGH && sensorValue4 == LOW && sensorValue5 == LOW) {
      motorForward();
    }
    //XTRAIS
    else if (sensorValue1 == HIGH && sensorValue2 == LOW && sensorValue3 == HIGH && sensorValue4 == HIGH && sensorValue5 == HIGH) {
      motorLeft1();
    }
    //1 TẮT
    else if (sensorValue1 == LOW && sensorValue2 == HIGH && sensorValue3 == HIGH && sensorValue4 == HIGH && sensorValue5 == HIGH) {
      motorLeft12();
    }
    //XPHAIR
    else if (sensorValue1 == HIGH && sensorValue2 == HIGH && sensorValue3 == HIGH && sensorValue4 == LOW && sensorValue5 == HIGH) {
      motorRight1();
    }
    //5 TẮT
    else if (sensorValue1 == HIGH && sensorValue2 == HIGH && sensorValue3 == HIGH && sensorValue4 == HIGH && sensorValue5 == LOW) {
      motorRight12();
    }
    // RẼ PHẢI
    else if (sensorValue1 == HIGH && sensorValue2 == HIGH && sensorValue3 == LOW && sensorValue4 == LOW && sensorValue5 == LOW) {
      motorRight();
    }
    //  RP2
    else if (sensorValue1 == HIGH && sensorValue2 == HIGH && sensorValue3 == LOW && sensorValue4 == LOW && sensorValue5 == HIGH) {
      motorRight();
    }

    // RẼ TRÁI
    else if (sensorValue1 == LOW && sensorValue2 == LOW && sensorValue3 == LOW && sensorValue4 == HIGH && sensorValue5 == HIGH) {
      motorLeft();
    }
    //  RT2
    else if (sensorValue1 == HIGH && sensorValue2 == LOW && sensorValue3 == LOW && sensorValue4 == HIGH && sensorValue5 == HIGH) {
      motorLeft();
    }
    else if (sensorValue1 == HIGH && sensorValue2 == HIGH && sensorValue3 == HIGH && sensorValue4 == HIGH && sensorValue5 == HIGH) {
      motorBackward();
    } }
  
  //khoảng cách
  else if (frontdist < 30) // nếu khoảng cách nhỏ hơn giới hạn
  {
    // cho xe robot STOP và delay khảng 0.2s
    digitalWrite (in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite (in3, LOW);
    digitalWrite(in4, LOW);
    analogWrite (ena, 0);
    analogWrite (enb, 0);
    delay(300);

    // cho robot rẻ phải trong 0.4s
    digitalWrite (in1, LOW); // cho xe robot re phai
    digitalWrite(in2, HIGH);
    digitalWrite (in3, LOW);
    digitalWrite(in4, LOW);
    analogWrite (ena, 130);
    analogWrite (enb, 0);
    delay(500);

    // và đi thẳng 1 đoạn trong 0.7s
    digitalWrite (in1, LOW); //cho xe robot ĐI THẲNG1 1 đoạn
    digitalWrite(in2, HIGH);
    digitalWrite (in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite (ena, 90);
    analogWrite (enb, 85);
    delay(650);

    // sau đó rẻ trái
    digitalWrite (in1, LOW); // cho xe robot re trái 1 đoạn có thể thay đổi
    digitalWrite(in2, LOW);
    digitalWrite (in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite (ena, 0);
    analogWrite (enb, 120);
    delay(300);
    // đi thẳng 1 doan
    digitalWrite (in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite (in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite (ena, 90);
    analogWrite (enb, 85);
    delay(90);
    // sau đó rẻ trái dò line
    digitalWrite (in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite (in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite (ena, 90);
    analogWrite (enb, 90);
    delay(150);
    // đi thẳng 1 doan
    digitalWrite (in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite (in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite (ena, 90);
    analogWrite (enb, 85);
    delay(90);
    
    while (left_sensor_state == LOW) { // ca hai cam bien deu LOW => thuc hien While
      left_sensor_state = digitalRead(sensorValue1 && sensorValue2);
      s_sensor_state = digitalRead(sensorValue3);
      right_sensor_state = digitalRead(sensorValue4 && sensorValue5);
      Serial.println("in the first while");
    } 
  }
}

void motorForward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ena, 100);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enb, 100);
}

void motorLeft1() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(ena, 75);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enb, 65);
}
void  motorLeft12() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ena, 0);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enb, 90);
}
void motorRight1() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ena, 75);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enb, 65);
}
void  motorRight12() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ena, 90);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enb, 0);
}
void motorRight() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ena, 80);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enb, 0);
}
void motorLeft() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ena, 0);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enb, 80);
}

void motorBackward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ena, 0);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enb, 80);
}
