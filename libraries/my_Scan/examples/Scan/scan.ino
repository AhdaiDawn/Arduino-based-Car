#include <my_Scan.h>
#include <Arduino.h>

char flag_scan = ' ';   
my_Scan scan(13,12);
void setup()
{
    Serial.begin(9600);
}
void loop()
{
   
    if(flag_scan != ' ') //有效字符串末尾字符不是空字符  则打印该字符
       {
          Serial.println(flag_scan);
          scan.clear();

          //拽去对应的物体
       }
       else   //每隔0.3秒 扫码一次 直到找到有效字符串
      {
        //调整机械臂
         flag_scan= scan.get_char();
         delay(500);
       }
}