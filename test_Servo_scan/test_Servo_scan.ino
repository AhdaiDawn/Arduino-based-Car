#include <my_Scan.h>     
#include <Arduino.h>   
#include <my_Servo.h>

my_Servo servo(Serial3);

char flag_scan = ' ';   
my_Scan scan(13,12);

void setup() 
{
  pinMode(35, OUTPUT);
  digitalWrite(35, HIGH);
    Serial.begin(9600);
    Serial3.begin(9600);
    servo.runActionGroup(0);
}
void loop()
{
   
    if(flag_scan != ' ') //有效字符串末尾字符不是空字符  则打印该字符
       {
          Serial.println(flag_scan);
          scan.clear();
          flag_scan = ' ';
          delay(1500);
//          servo.runActionGroup(1);
//          delay(4000);
//          servo.runActionGroup(3);
//          delay(4000);
         
          //拽去对应的物体
       }
       else   //每隔0.3秒 扫码一次 直到找到有效字符串
      {
        //调整机械臂
         flag_scan= scan.get_char();
         delay(300);
       }
}
