本库使用Serial类进行串口通信，占用Arduino的一个硬件串口
接线：舵机控制板的Tx接Arduino的Rx，舵机控制板的Rx接Arduino的Tx，
舵机控制板的GND接Arduino的GND

使用库前请初始化串口为波特率9600  不支持其他波特率
实例化myServo类后调用
调用举例：
  myServo servo(Serial3); //使用Serial3作为与舵机板的通信接口，
                                            //无参数是为Serial
  servo.moveServo(0,1200,10)； //0号舵机以10的速度移动至1200位置
  
  对于Arduino Leonardo等 atmega32u4的板子默认串口为Serial1，其他均为Serial
  更多函数参看代码，代码有详细注释

