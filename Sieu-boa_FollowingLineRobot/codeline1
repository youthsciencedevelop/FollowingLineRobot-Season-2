int ss1, ss2, ss3, ss4, ss5, ss6;
void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600);
}
void readsensor() {
  ss1 = digitalRead(A0);
  ss2 = digitalRead(A1);
  ss3 = digitalRead(A2);
  ss4 = digitalRead(A3);
  ss5 = digitalRead(A4);

  ss6 = digitalRead(A5);
}
void hienthi() {
  Serial.print(ss1);
  Serial.print(ss2);
  Serial.print(ss3);
  Serial.print(ss4);
  Serial.print(ss5);
  Serial.print(ss6);
}
void chaynha() {
  if (ss6 == 1) {
    dunglai();
  }
   else {
    if (ss3 == 0||
    (ss1 == 0 && ss2 == 0 && ss3 == 0)||(ss4 == 0 && ss5 == 0 && ss3 == 0)||
    (ss1 == 0 && ss2 == 0 && ss3 == 0 && ss4 == 0 && ss5 == 0))
      chaythang();

    else if (ss2 == 0)
      lechtrai();

    else if (ss4 == 0 )
      lechphai();

    else if (ss2 == 0 && ss3 == 0)
      traitrai();

    else if (ss4 == 0 && ss3 == 0)
      phaiphai();

    else if (ss1 == 0 && ss2 == 0)
      queotrai();

    else if (ss4 == 0 && ss5 == 0)
      queophai();


 }
}
void chaythang() {
  
  analogWrite(7, 150); // bên phải
  analogWrite(6, 0);

  analogWrite(4, 150);  // bên trái
  analogWrite(5, 0);
}
void lechtrai() {
  analogWrite(7, 130);
  analogWrite(6, 0);

  analogWrite(4, 150);
  analogWrite(5, 0);

 }
void lechphai() {

  analogWrite(7, 150);
  analogWrite(6, 0);

  analogWrite(4, 130);
  analogWrite(5, 0);

 }

 void queotrai() {

  analogWrite(7, 150);
  analogWrite(6, 0);

  analogWrite(4, 0);
  analogWrite(5, 140);

 }
 void queophai() {
  analogWrite(7, 140);
  analogWrite(6, 0);

  analogWrite(4, 150);
  analogWrite(5, 0);

 }
void phaiphai() {

  analogWrite(7, 140);
  analogWrite(6, 0);

  analogWrite(4, 150);
  analogWrite(5, 0);

 }

 void traitrai() {

  analogWrite(7, 150);
  analogWrite(6, 0);

  analogWrite(4, 0);
  analogWrite(5, 140);

 }
 
 void luilai() {

  analogWrite(7, 0);
  analogWrite(6, 150);

  analogWrite(4, 0);
  analogWrite(5, 150);
 }
 void dunglai() {

  analogWrite(7, 0);
  analogWrite(6, 0);

  analogWrite(4, 0);
  analogWrite(5, 0);
}
void loop() {
  Serial.println();
  readsensor();
  hienthi();
  chaynha();
}

