#include <my_Servo.h>
#include "DRV8825.h"
#include <Arduino.h>
my_Servo servo(Serial3);
//触碰开关
int KEY= 53; //后面
// Motor steps per revolution. Most steppers are 200 steps or 1.8 degrees/step
#define MOTOR_STEPS 200
#define RPM 300
// 1=full step, 2=half step etc.
#define MICROSTEPS 1

// All the wires needed for full functionality
#define DIR 37
#define STEP 36
#define ENABLE 35
//步进
int flag_step = 0;//当前位置
int flag_step_y = 0;//执行位置
DRV8825 stepper(MOTOR_STEPS, DIR, STEP, ENABLE);

void setup()
{
    Serial.begin(9600);
    //触碰
    pinMode(KEY, INPUT);
//    stepper.enable();
    stepper.begin(RPM, MICROSTEPS);
Serial3.begin(9600);
    // servo.runActionGroup(6);
}

void loop()
{


    step_init();
     delay(100);
    flag_step = 0;
    flag_step_y =  9;
    step(flag_step, flag_step_y);
    
    while(1){
        ;
    }
    
}
void step(int a,int C)
{
    int x;
    x=C-a;
    stepper.rotate(90*(x));
}
void step_init()//步进电机初始化
{
  
  digitalWrite(DIR, LOW); // 电机前进

  for (int x = 0; x < (100 * 50); x++) // Loop 2000 times
  {
    digitalWrite(STEP, HIGH); // Output high
    delayMicroseconds(500);  // Wait 1/2 a ms
    digitalWrite(STEP, LOW);  // Output low
    delayMicroseconds(500);  // Wait 1/2 a ms
    if (digitalRead(KEY) == LOW)
      x = 100 * 50;
  }
}
