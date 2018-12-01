#include "DRV8825.h"
#include "rgb_lcd.h"
#include <SoftwareSerial.h>
#include <Wire.h>
#include <arduino.h>
#include <my_Scan.h>
#include <my_Servo.h>
rgb_lcd lcd;
//
int GD=2; //光电开关

//触碰开关
int KEY=52;//前面
//步进
int flag_step = 0;//当前位置
int flag_step_y = 0;//执行位置
#define DIR 37//方向
#define STEP 36//步进
#define ENABLE 35//使能
#define MOTOR_STEPS 200 //步数
#define RPM 280//速度
// 1=full step, 2=half step etc.
#define MICROSTEPS 1//细分
DRV8825 stepper(MOTOR_STEPS, DIR, STEP, ENABLE);
//扫码
char a[3] = {'2', '3', '4'};
char flag_scan = ' ';
my_Scan scan(13, 12);
//舵机定义
my_Servo servo(Serial3);

int trac0 = 8; //从车头方向的最左边开始排序
int trac1 = 9;
int trac2 = 10;
int trac3 = 11;
int trac4 = 7; //车右前后排序
int trac5 = 6;
int trac6 = 5;
int trac7 = 4;
//超声波
#define Trig 48 //引脚Tring 连接 IO D48
#define Echo 49 //引脚Echo 连接 IO D49 
float cm; //距离变量
float temp; // 

//转弯方向定义
#define TURN_LIFT 0
#define TURN_RIGHT 1
//左边电机接口定义
#define MOTOR_L1_FORWARD 30
#define MOTOR_L1_BACK 31
#define MOTOR_L2_FORWARD 32
#define MOTOR_L2_BACK 33
//右边电机接口定义
#define MOTOR_R1_FORWARD 42
#define MOTOR_R1_BACK 43
#define MOTOR_R2_FORWARD 44
#define MOTOR_R2_BACK 45

void setup()
{
    Serial.begin(9600);
    Serial3.begin(9600);
    //超声波
    pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  //光电开关
  pinMode(GD,INPUT);
    //触碰
    pinMode(KEY, INPUT);
    //红外
    pinMode(trac0, INPUT);
    pinMode(trac1, INPUT);
    pinMode(trac2, INPUT);
    pinMode(trac3, INPUT);
    pinMode(trac4, INPUT);
    pinMode(trac5, INPUT);
    pinMode(trac6, INPUT);
    pinMode(trac7, INPUT);
    //直流电机
    pinMode(MOTOR_L1_FORWARD, OUTPUT);
    pinMode(MOTOR_L1_BACK, OUTPUT);
     pinMode(MOTOR_L2_FORWARD, OUTPUT);
    pinMode(MOTOR_L2_BACK, OUTPUT);


    pinMode(MOTOR_R1_FORWARD, OUTPUT);
    pinMode(MOTOR_R1_BACK, OUTPUT);
     pinMode(MOTOR_R2_FORWARD, OUTPUT);
    pinMode(MOTOR_R2_BACK, OUTPUT);
    //步进电机
    stepper.begin(RPM, MICROSTEPS);
    //显示屏
    lcd.begin(16, 2);
    lcd.setRGB(255, 255, 255);
}





void loop()
{
    int IS;
    int jishu = 0;//抓放物料次数
    int Flag_1 = 0;//第一个黑线

    int Flag_21 = 0;//上料区
    int Flag_22 = 0;
    int Flag_23 = 0;
    int Flag_24 = 0;

    int Flag_3 = 1;//第二条黑线

    int Flag_41 = 0;//下料区
    int Flag_42 = 0;
    int Flag_43 = 0;

    step_init();
     delay(100);
    flag_step = 0;
    flag_step_y =  15;
    step(flag_step, flag_step_y);

    servo.runActionGroup(0);
    lcd.setCursor(0, 0);
    lcd.print("group_0");
   
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("begin");


// while(1)
//    {
//        tracing();
//         if(avoidance()){
//             break;
//         }
//         Flag_3=1;
//    }
//    
//
//while(1)
//    {
//        tracing();
//    
//    }




    
    while (Flag_3)
    {
        tracing();
        if (!digitalRead(GD))
        {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("flag");
            stop(100);
            break;
        }
    }
    while (Flag_3)
    {
         IS=tracing();
         IS=get_IS2() ;
        if (IS == 8)
        {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("flag");
            stop(100);
            forward();
            delay(120);
            Flag_41 = 1;
            Flag_3 = 0;
            jishu = 0; //计数清零!!!!
        }
    }
    while (Flag_41)
    {
        forward();
        IS=get_IS2() ;
        if ((IS == 12))
        {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("flag_41");
            stop(160);//六个的时候是:160,三个:130
            delay(500);
            tiaozheng_1();
            /**********************第一次**************************/
            flag_step = 15;
            flag_step_y = 9;
            step(flag_step, flag_step_y);
            delay(1500);
            forward();//过掉黑线
            delay(150); /////////////////////////////////////
            Flag_42 = 1;
            Flag_41 = 0;

        }
    }
    while (Flag_42)
    {

         tracing_p();
        IS=get_IS2() ;
        if ((IS == 12))
        {
            lcd.setCursor(0, 0);
            lcd.print("flag_42");
           stop(160);//165
            delay(500);
            tiaozheng_2();
            delay(1500);
            /**********************第二次**************************/
            Flag_43 = 1;
            Flag_42 = 0;

            
            if (jishu == 3)
            {
                Flag_43 = 0;
            }
            forward();
            delay(300); /////////////////////////////////////
        }
    }
    while (Flag_43)
    {
         tracing_p();
        IS=get_IS2();
        if ((IS== 3))
        {
            lcd.setCursor(0, 0);
            lcd.print("flag_43");
            stop(175);//新:170
            delay(500);
            tiaozheng_3();
            delay(1500);
            stop(0);
            while(1);
            /**********************第三次**************************/
            Flag_43 = 0;
        }
    }

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("go home");
    tracing_time(3500);
    while (1)
    {
        IS=tracing();
        if(IS==0)
        {
            ahdai();
        }
    }
}
