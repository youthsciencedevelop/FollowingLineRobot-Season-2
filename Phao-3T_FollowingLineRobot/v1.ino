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
  delay(100);
}

void loop() {
  int sensorValue1 = digitalRead(irSensor1);
  int sensorValue2 = digitalRead(irSensor2);
  int sensorValue3 = digitalRead(irSensor3);
  int sensorValue4 = digitalRead(irSensor4);
  int sensorValue5 = digitalRead(irSensor5);
// THẲNG
  if ((sensorValue1 == HIGH && sensorValue2 == HIGH && sensorValue3 == LOW && sensorValue4 == HIGH && sensorValue5 == HIGH)
  || (sensorValue1 == LOW && sensorValue2 == LOW && sensorValue3 == LOW && sensorValue4 == LOW && sensorValue5 == LOW))
  // đi thẳng 
 {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ena, 140);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enb, 140);
}
  
//XTRAIS
  else if (sensorValue1 == HIGH && sensorValue2 == LOW && sensorValue3 == HIGH && sensorValue4 == HIGH && sensorValue5 == HIGH)
  { 
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(ena, 0);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enb, 100);
}

//XPHAIR
  else if (sensorValue1 == HIGH && sensorValue2 == HIGH && sensorValue3 == HIGH && sensorValue4 == LOW && sensorValue5 == HIGH) 
  { 
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ena, 100);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
 analogWrite(enb, 0);//thấp
}




  
//nếu lệch ra khỏi line 1/5 và 5/5 con thì motorB se chạy về giữa line
  else if (sensorValue1 == LOW && sensorValue2 == HIGH && sensorValue3 == HIGH && sensorValue4 == HIGH && sensorValue5 == HIGH)
   // quẹo trái1/5
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(ena, 100);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enb, 130);
}
//quẹo phải5/5
  else if (sensorValue1 == HIGH && sensorValue2 == HIGH && sensorValue3 == HIGH && sensorValue4 == HIGH && sensorValue5 == LOW) 
  {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ena, 130);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enb, 100);
}


// RẼ PHẢI
  if ((sensorValue1 == HIGH && sensorValue2 == HIGH && sensorValue3 == LOW && sensorValue4 == LOW && sensorValue5 == LOW)
  ||
 (sensorValue1 == HIGH && sensorValue2 == HIGH && sensorValue3 == LOW && sensorValue4 == LOW && sensorValue5 == HIGH) 
   ||
  (sensorValue1 == HIGH && sensorValue2 == HIGH && sensorValue3 == LOW && sensorValue4 == HIGH && sensorValue5 == LOW))
  {digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ena, 130);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enb, 110);
}


// RẼ TRÁI
    if ((sensorValue1 == LOW && sensorValue2 == LOW && sensorValue3 == LOW && sensorValue4 == HIGH && sensorValue5 == HIGH)
||   
     (sensorValue1 == HIGH && sensorValue2 == LOW && sensorValue3 == LOW && sensorValue4 == HIGH && sensorValue5 == HIGH)
     ||
  (sensorValue1 == LOW && sensorValue2 == LOW && sensorValue3 == HIGH && sensorValue4 == HIGH && sensorValue5 == HIGH))
  {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(ena, 110);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enb, 130);
}
//XTRAIS2
  else if (sensorValue1 == HIGH && sensorValue2 == HIGH && sensorValue3 == HIGH && sensorValue4 == HIGH && sensorValue5 == HIGH)
  { 
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(ena, 0);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enb, 120);
}
}
