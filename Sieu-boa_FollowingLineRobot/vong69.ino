int ss1, ss2, ss3, ss4, ss5, ss6;
void setup() {
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5, INPUT);


  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);

  Serial.begin(9600);
}

void readsensor()
{ 
  ss1 = digitalRead(A0);
  ss2 = digitalRead(A1);
  ss3 = digitalRead(A2);
  ss4 = digitalRead(A3);
  ss5 = digitalRead(A4);

  ss6 = digitalRead(A5);
}
void Hienthi()
{ 
  Serial.print(ss1);
  Serial.print(ss2);
  Serial.print(ss3);
  Serial.print(ss4);
  Serial.println(ss5);
}
void chay(){
  if (ss6==1) {
    analogWrite (7, 0); // cho xe robot chạy lùi 1 đoạn
    analogWrite(6, 150);
    analogWrite (4, 0);
    analogWrite(5, 150);
    delay(300);

    analogWrite (6, 0);
    analogWrite(7, 0);
    analogWrite (4, 0);
    analogWrite(5, 0);
    delay(300);

    analogWrite (7, 0); // cho xe robot xoay sang trái
    analogWrite(6, 70);
    analogWrite (4, 110);
    analogWrite(5, 0);
    delay(400);
    analogWrite (6, 0);
    analogWrite(7, 0);
    analogWrite (4, 0);
    analogWrite(5, 0);
    delay(200);

    analogWrite (7, 180); //cho xe robot đi thẳng 1 đoạn
    analogWrite(6, 0);
    analogWrite (4, 180);
    analogWrite(5, 0);
    delay(300);
    analogWrite (6, 0);
    analogWrite(7, 0);
    analogWrite (4, 0);
    analogWrite(5, 0);
    delay(200);

    analogWrite (7, 130); // cho xe robot xoay phải 1 đoạn
    analogWrite(6, 0);
    analogWrite (4, 0);
    analogWrite(5, 70);
    delay(300);
    analogWrite (6, 0);
    analogWrite(7, 0);
    analogWrite (4, 0);
    analogWrite(5, 0);
    delay(200);

    ///////////////////
    analogWrite (7, 90); //cho xe robot đi thẳng 1 đoạn
    analogWrite(6, 0);
    analogWrite (4, 90);
    analogWrite(5, 0);
    delay(600); 
    analogWrite (6, 0);
    analogWrite(7, 0);
    analogWrite (4, 0);
    analogWrite(5, 0);
    delay(200);

    analogWrite (7, 130); // cho xe robot xoay phải 1 đoạn
    analogWrite(6, 0);
    analogWrite (4, 0);
    analogWrite(5, 80);
    delay(300);
    analogWrite (6, 0);
    analogWrite(7, 0);
    analogWrite (4, 0);
    analogWrite(5, 0);
    delay(200);

    ///////////////////
    analogWrite (7, 70); //cho xe robot đi thẳng 1 đoạn
    analogWrite(6, 0);
    analogWrite (4, 70);
    analogWrite(5, 0);
    delay(600); 
    analogWrite (6, 0);
    analogWrite(7, 0);
    analogWrite (4, 0);
    analogWrite(5, 0);
    delay(200);

    analogWrite (7, 100); // cho xe robot xoay phải 1 đoạn
    analogWrite(6, 0);
    analogWrite (4, 0);
    analogWrite(5, 50);
    delay(300);
    analogWrite (6, 0);
    analogWrite(7, 0);
    analogWrite (4, 0);
    analogWrite(5, 0);
    delay(200);

    ///////////////////
    analogWrite (7, 95); //cho xe robot đi thẳng 1 đoạn
    analogWrite(6, 0);
    analogWrite (4, 95);
    analogWrite(5, 0);
    delay(600); 
    analogWrite (6, 0);
    analogWrite(7, 0);
    analogWrite (4, 0);
    analogWrite(5, 0);
    delay(200);

    analogWrite (7, 0); // cho xe robot xoay sang trái
    analogWrite(6, 75);
    analogWrite (4, 125);
    analogWrite(5, 0);
    delay(400);
    analogWrite (6, 0);
    analogWrite(7, 0);
    analogWrite (4, 0);
    analogWrite(5, 0);
    delay(200);


    
  }
  else {
  if(ss3==0)
  // if(ss3==0||ss1==1&&ss2==1&&ss3==1&&ss4==1&&ss5==1)
  chaythang();
  else if(ss1==0||ss2==0)
  retrai();
  else if(ss4==0||ss5==0)
  rephai();

  else if(ss1==0&&ss2==0)
  rretrai();
  else if(ss5==0&&ss4==0)
  rrephai();
  
  else if(ss3==1){
    
   analogWrite(7,20);
   analogWrite(6,0);
  
   analogWrite(4,20);
   analogWrite(5,0);
  

  }
}}
void chaythang()
{
   analogWrite(7,69);
   analogWrite(6,0);
  
   analogWrite(4,69);
   analogWrite(5,0);
  
}
void retrai()
{
  
   analogWrite(7,150);
   analogWrite(6,0);
  
   
   analogWrite(4,0);
   analogWrite(5,130);
  
}
void rephai()
{
   analogWrite(7,0);
   analogWrite(6,130);
  
   analogWrite(4,150);
   analogWrite(5,0);
}
void rretrai()
{
  
   analogWrite(7,170);
   analogWrite(6,0);
  
   
   analogWrite(4,0);
   analogWrite(5,150);
  
}
void rrephai()
{
   analogWrite(7,0);
   analogWrite(6,150);
  
   analogWrite(4,170);
   analogWrite(5,0);
}
void dunglai()
{
   analogWrite(7,0);
   analogWrite(6,0);
  
   analogWrite(4,0);
   analogWrite(5,0);
}
void luilai()
{
   analogWrite(7,0);
   analogWrite(6,10);
  
   analogWrite(4,0);
   analogWrite(5,10);
}

void loop() {
 readsensor();
 Hienthi();
 chay(); 
 //chaythang();
 //retrai();
 //rephai();
}


