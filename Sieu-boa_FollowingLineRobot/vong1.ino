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
void chay()
{
  if(ss3==0)
  chaythang();
  else if(ss1==0||ss2==0)
  retrai();
  else if(ss4==0||ss5==0)
  rephai();
}
void chaythang()
{
   analogWrite(7,200);
   analogWrite(6,0);
  
   analogWrite(4,200);
   analogWrite(5,0);
  
}
void retrai()
{
  
   analogWrite(7,190);
   analogWrite(6,0);
  
   
   analogWrite(4,0);
   analogWrite(5,170);
  
}
void rephai()
{
   analogWrite(7,0);
   analogWrite(6,170);
  
   analogWrite(4,190);
   analogWrite(5,0);
}

void loop() {
 readsensor();
 Hienthi();
 chay(); 
 //chaythang();
 //retrai();
 //rephai();
}



