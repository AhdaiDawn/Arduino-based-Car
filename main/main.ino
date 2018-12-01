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
char a[6] = {'1', '2', '3', '4', '5', '6'};
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
    //触碰
    pinMode(KEY, INPUT);
    //光电开关
  pinMode(GD,INPUT);
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

    int Flag_3 = 0;//第二条黑线

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

    forward();
    delay(400);
    while (1) //开始
    {
        IS=tracing();
        if (IS == 15)
        {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("flag_1");
            forward();
            delay(200);
            Flag_1 = 1;
            break;
        }
    }
   
    while (Flag_1) //爬坡
    {
        tracing_p();
        IS=get_IS2() ;
        if ((IS == 8))
        {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("flag");
            stop(100);
            forward();
            delay(200);
            Flag_21 = 1;
            Flag_1 = 0;
        }
    }
    while (Flag_21)
    {
         tracing_p();
         IS=get_IS2() ;
        if ( (IS == 12))
        {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("flag_21");
              stop(150);//163
              delay(500);
              tiaozheng();
            /**********************第一次**************************/
            flag_step = 15;
            flag_step_y = 49;
            step(flag_step, flag_step_y);
            
            flag_step = 49;
            flag_step_y = 0;
            jishu = grub(flag_step,jishu,flag_step_y);
            flag_step = 0;
            flag_step_y = 0;
            jishu = grub(flag_step,jishu,flag_step_y);
            forward();//过掉黑线
            delay(150); /////////////////////////////////////
             Flag_22 = 1;
            Flag_21 = 0;
        }
    }
    while (Flag_22)
    {
        tracing_p();
        IS=get_IS2() ;
        if ( (IS == 12))
        {
            lcd.setCursor(0, 0);
            lcd.print("flag_22");
            stop(168);//170
              delay(500);
              tiaozheng();
            /**********************第二次**************************/
            flag_step = 0;
            flag_step_y = 0;
            jishu = grub(flag_step,jishu,flag_step_y);
            Flag_23 = 1;
            Flag_22 = 0;
            forward();//过掉黑线
            delay(150); /////////////////////////////////////
            if (jishu == 6)//在grub()已经有丝杠归位了,改丝杠初始位置时一定要改grub()函数
            {
                Flag_23 = 0;
                forward();
                delay(1000);//冲下坡
            }
        }
    }
        while (Flag_23)
    {
        tracing_p();
        IS=get_IS2() ;
        if ((IS == 3))
        {
            lcd.setCursor(0, 0);
            lcd.print("flag_23");
            stop(135);//150
            delay(500);

              tiaozheng();
            /**********************第三次**************************/
            flag_step = 0;
            flag_step_y = 0;
            jishu = grub(flag_step,jishu,flag_step_y);
            Flag_23 = 0;
            Flag_24 = 1;
            forward();//过掉黑线
           delay(150); /////////////////////////////////////
            if (jishu == 6)//在grub()已经有丝杠归位了,改丝杠初始位置时一定要改grub()函数
            {
                Flag_24 = 0;
                forward();
                delay(1000);//冲下坡
            }
        }
    }

    while (Flag_24)
    {
        tracing_p();
        IS=get_IS2() ;
        if ((IS == 3))
        {
            lcd.setCursor(0, 0);
            lcd.print("flag_23");
            stop(165);//170
            delay(500);
            tiaozheng_4();
            /**********************第四次**************************/
            flag_step = 0;
            flag_step_y = 15;
            jishu = grub(flag_step,jishu,flag_step_y);
            servo.runActionGroup(0);
            forward();
            delay(1000);//冲下坡
            Flag_24 = 0;
        }
    }
    while (1)
    {
         IS=tracing();
        if (IS == 15)
        {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Flag_3 go");
            forward();//过掉黑线
            delay(198); 
            break;
        }
        Flag_3=1;
    }




    //     while(1)//有减速带
    // {
    //     forward();//过掉障碍物
    //     delay(2000); /////////////////////////////////////
    //     break;
    //      Flag_3=1;
    // }
    

    // 无减速带


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
            stop(130);//140
            delay(500);
            tiaozheng_1();
            /**********************第一次**************************/
            flag_step = 15;
            flag_step_y = 58;
           step(flag_step, flag_step_y);
            flag_step = 58;
            flag_step_y =9;

            jishu=put_down(flag_step,jishu,flag_step_y);
            flag_step = 9;
            flag_step_y = 9;

            jishu=put_down(flag_step,jishu,flag_step_y);
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
           stop(160);//160
            delay(500);
            tiaozheng_2();
            /**********************第二次**************************/
            flag_step = 9;
            flag_step_y = 9;
            jishu=put_down(flag_step,jishu,flag_step_y);
            Flag_43 = 1;
            Flag_42 = 0;

            
            if (jishu == 6)
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
            /**********************第三次**************************/
            flag_step = 9;
            flag_step_y = 58;

            jishu = put_down(flag_step,jishu,flag_step_y);
            if (jishu < 6)
            {
                flag_step = 58;
                flag_step_y = 15;
                jishu=put_down(flag_step,jishu,flag_step_y);
            }
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
            forward();
            delay(500);
            ahdai();
        }
    }
}