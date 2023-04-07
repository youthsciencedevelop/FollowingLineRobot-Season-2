#include <THIROBOT.h>

#define LCD_ENABLE_PIN  PIN_D3                                    ////
#define LCD_RS_PIN      PIN_D1                                    ////
#define LCD_RW_PIN      PIN_D2                                    ////
#define LCD_DATA4       PIN_D4                                    ////
#define LCD_DATA5       PIN_D5                                    ////
#define LCD_DATA6       PIN_D6                                    ////
#define LCD_DATA7       PIN_D7 
#INCLUDE<LCD.C>
#define in1  pin_c3
#define in2  pin_c4
#define in3  pin_c0
#define in4  pin_c5
#define trigger pin_E0
#define echo PIN_E1

int1  s1, s2, s3, s4, s5;

//int8 trangthai;
void tien_nguocchieukimdongho();
void lui_cungchieukimdongho();
void quayphai();
void quaytrai();
void quaydau();
void main()
{
   setup_ccp1(CCP_PWM);
   setup_ccp2(CCP_PWM);
   
   setup_timer_2(T2_DIV_BY_16,249, 1);
set_tris_b(0xff);
set_tris_d(0);
set_tris_c(0);
lcd_init();
tien_nguocchieukimdongho();
    delay_ms(3000);
    quayphai();
    delay_ms(600);
    tien_nguocchieukimdongho();
    delay_ms(1700);
    quaytrai();
    delay_ms(580);
    
    tien_nguocchieukimdongho();
    delay_ms(500);
    
    
   while(TRUE)
   {
      s1 = input(pin_B5);
      s2 = input(pin_B1);
      s3 = input(pin_B2);
      s4 = input(pin_B3);
      s5 = input(pin_B4);
    lcd_gotoxy(1,1);
    printf(lcd_putc,"%d%d%d%d%d",s1,s2,s3,s4,s5);
    
    
    
   
    if(s3==0 || (s1==1 && s2==1 && s3==0 && s4==0 && s5==0) ||   (s1==1 && s2==0 && s3==0 && s4==0 && s5==0) || (s1==0 && s2==0 && s3==0 && s4==0 && s5==1)  )
    {
    
    tien_nguocchieukimdongho();
    }
    IF( (s1==0) || (s1==0 && s2==0 && s3==1 && s4==1 && s5==1)     )
    quaytrai();
    if((s5==0) ||(s4==0 && s5==0) )
    quayphai();
    }
    }
    
    
   

void tien_nguocchieukimdongho()
{
output_low(in1);
output_high(in2);
output_low(in3);
output_high(in4);

set_pwm1_duty(650);//hoac 500
set_pwm2_duty(650);//hoac 500
}

void quayphai()
{

OUTPUT_low(IN3);
OUTPUT_LOW(IN4);
OUTPUT_LOW(IN1);
OUTPUT_HIGH(IN2);

//QUAY PHAI DONG CO TRAI QUAY TOC DO CAO HON
set_pwm1_duty(650);
set_pwm2_duty(0);
}
void quaytrai()
{

OUTPUT_low(IN1);
OUTPUT_LOW(IN2);
OUTPUT_LOW(IN3);
OUTPUT_HIGH(IN4);

//QUAY PHAI DONG CO TRAI QUAY TOC DO CAO HON
set_pwm1_duty(0);
set_pwm2_duty(650);
}

void quaydau()
{

OUTPUT_high(IN1);
OUTPUT_LOW(IN2);
OUTPUT_LOW(IN3);
OUTPUT_HIGH(IN4);

//QUAY PHAI DONG CO TRAI QUAY TOC DO CAO HON
set_pwm1_duty(300);
set_pwm2_duty(300);
}
