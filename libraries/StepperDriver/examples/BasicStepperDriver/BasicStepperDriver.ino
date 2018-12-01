
#include "DRV8825.h"
#include <Arduino.h>
//触碰开关
int KEY1 = 53; //后面
// Motor steps per revolution. Most steppers are 200 steps or 1.8 degrees/step
#define MOTOR_STEPS 200
#define RPM 255
// 1=full step, 2=half step etc.
#define MICROSTEPS 1

// All the wires needed for full functionality
#define DIR 37
#define STEP 36
#define ENABLE 35

DRV8825 stepper(MOTOR_STEPS, DIR, STEP, ENABLE);

void setup()
{
    Serial.begin(9600);
    //触碰
    pinMode(KEY1, INPUT);
//    stepper.enable();
    stepper.begin(RPM, MICROSTEPS);

}

void loop()
{
    //  stepper.startMove(1); 

    //  stepper.startRotate(10); 
    stepper.rotate(90);//+后退-前进
    //  stepper.move(-1000);
   if (digitalRead(KEY1) == LOW)
   {
       stepper.stop();
   }

     unsigned wait_time_micros = stepper.nextAction();
     if (wait_time_micros <= 0) {
        stepper.disable();       // comment out to keep motor powered
        delay(3600000);
    }
    if (wait_time_micros > 100){
    }

    // stepper.enable();
    //    stepper.move(-MOTOR_STEPS*MICROSTEPS);

    // stepper.disable();

    // delay(5000);
    
    // while(1){
    //     ;
    // }
    
}
