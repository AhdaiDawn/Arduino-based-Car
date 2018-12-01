#include "DRV8825.h"
#include "rgb_lcd.h"
#include <SoftwareSerial.h>
#include <Wire.h>
#include <arduino.h>
#include <my_Scan.h>
#include <my_Servo.h>
rgb_lcd lcd;
//
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
    while(1)
    {
        int flag=tracing();
//        if(flag==15){
//            stop(100);
//            while(1);
//        }
    }
}
  
