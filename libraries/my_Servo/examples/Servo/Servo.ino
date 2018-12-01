#include <my_Servo.h> 
#include <Wire.h>
#include <Arduino.h>

my_Servo servo(Serial3);//Serial3：15（Rx） 和 14（Tx）
//接线：舵机控制板的Tx接Arduino的Rx，舵机控制板的Rx接Arduino的Tx，
//舵机控制板的GND接Arduino的GND
void setup()
{
  Serial3.begin(9600);
  servo.moveServos(4, 180, 0, 90, 1, 90, 2, 90, 3, 90);
}
void loop()
{
  servo.runActionGroup(0); //运行1号动作组
  delay(5000);
  servo.runActionGroup(1);
   //0号舵机以10的速度移动至1500位置
  // delay(2000);
  // servo.moveServos(5, 10, 0, 90, 2, 70, 4, 60, 6, 90, 8, 79);
  //控制5个舵机，移动速度10，0号舵机至90位置，2号舵机至70位置，4号舵机至60位置，
  //6号舵机至90位置，8号舵机至79位置
  delay(5000);
  while(1){}
}
