#define input_1 5
#define input_2 6
#define input_3 11
#define input_4 10
#define CB_1 2
#define CB_2 3
#define CB_3 4
#define CB_4 7
#define CB_5 8


void setup()
{
  pinMode (input_1, OUTPUT);
  pinMode (input_2, OUTPUT);
  pinMode (input_3, OUTPUT);
  pinMode (input_4, OUTPUT);
  pinMode (CB_4, INPUT);
  pinMode (CB_5, INPUT);
  pinMode (CB_1, INPUT);
  pinMode (CB_2, INPUT);
  pinMode (CB_3, INPUT);
}


//void chay(u8 trai, u8 phai) {
//  analogWrite (input_1, phai);
//  digitalWrite (input_2, 0);
//  analogWrite  (input_3, trai);
//  digitalWrite (input_4, 0);
//}
void chay_thang(){

  
  digitalWrite (input_1, 1);
  digitalWrite (input_2, 0);
  digitalWrite (input_3, 1);
  digitalWrite (input_4, 0);  
}
void chay_phai(){

  
  digitalWrite (input_1, 1);
  digitalWrite (input_2, 0);
  digitalWrite (input_3, 1);
  digitalWrite (input_4, 1);  
}
void chay_trai(){  

  
  digitalWrite (input_1, 1);
  digitalWrite (input_2, 1);
  digitalWrite (input_3, 1);
  digitalWrite (input_4, 0);  
}



/************************************************************************

     FUNCTION: DIEU KHIEN DO LINE
 *   *   INPUT:  + CAM BIEN
     +   OUTPUT: XUAT CHAN DIEU KHIẺN

 *************************************************************************/

void do_line ()
{
  u8 CB1, CB2, CB3, CB4, CB5;

  CB1 = digitalRead(CB_1);
  CB2 = digitalRead(CB_2);
  CB3 = digitalRead(CB_3);
  CB4 = digitalRead(CB_4);
  CB5 = digitalRead(CB_5);


  if (CB1 == 1 && CB2 == 1 && CB3 == 0 && CB4 == 1 && CB5 == 1  )                //chay thang
    chay_thang();
  if (CB1 == 1 && CB2 == 0 && CB3 == 0 && CB4 == 0 && CB5 == 1 )
    chay_thang();
  if (CB1 == 0 && CB2 == 0 && CB3 == 0 && CB4 == 0 && CB5 == 0 )
    chay_thang();
  if (CB1 == 0 && CB2 == 0 && CB3 == 0 && CB4 == 0 && CB5 == 1 )
    chay_thang();
  if (CB1 == 1 && CB2 == 0 && CB3 == 0 && CB4 == 0 && CB5 == 0 )
    chay_thang();
  if (CB1 == 0 && CB2 == 0 && CB3 == 1 && CB4 == 0 && CB5 == 0 )
    chay_thang();

  /*****************************************************************************************
      CAM BIEN LECH VE BEN trai
   ********************************************************************************************/


  if (CB1 == 0 && CB2 == 0 && CB3 == 0 && CB4 == 1 && CB5 == 1 ) {
       chay_phai();

  }
  if (CB1 == 0 && CB2 == 0 && CB3 == 1 && CB4 == 1 && CB5 == 1 ) {
       chay_phai();

  }
  if (CB1 ==0 && CB2 == 1 && CB3 == 1 && CB4 ==1 && CB5 ==1  ) {
       chay_phai();
       
  }
  if (CB1 == 1 && CB2 ==0 && CB3 == 1 && CB4 == 1 && CB5 ==1  ) {
       chay_phai();
       
  }
  if (CB1 == 1 && CB2 == 0 && CB3 == 0 && CB4 == 1 && CB5 == 1  ) {
       chay_phai();
       
  }
  /***********************************************************************************************
              CAM BIEN NHAN VE Ben trai
   *********************************************************************************************/


  if (CB1 == 1 && CB2 == 1 && CB3 == 0 && CB4 ==0 && CB5 == 0 ) {
       chay_trai();

  }
  if (CB1 == 1 && CB2 ==1 && CB3 == 1 && CB4 == 0 && CB5 == 0 ) {
       chay_trai();

  }
  if (CB1 == 1 && CB2 == 1 && CB3 == 1 && CB4 ==1 && CB5 == 0 ) {
       chay_trai();
       
  }
  if (CB1 == 1 && CB2 == 1 && CB3 ==1 && CB4 ==0 && CB5 == 1  ) {
       chay_trai();
       
  }
  if (CB1 ==1 && CB2 == 1&& CB3 == 0 && CB4 ==0 && CB5 == 1  ) {
       chay_trai();
  }
}
/******************************************************************************************************************

 *******************************************************************************************************************/
void loop() {
  delay(3000);
  while (1)
    do_line();
}
