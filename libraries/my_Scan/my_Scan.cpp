#include "my_Scan.h"

SoftwareSerial BarcodeSerial(RX,TX); //  RX TX,      PCINT

String SciString = "";         // 主控板接收扫码模块发送回来的字符串

signed char SetSeiDecMod[] = {(signed char)(0x07),(signed char)(0xC6),(signed char)(0x04),(signed char)(0x00),(signed char)(0xFF),(signed char)(0x8A),(signed char)(0x08),(signed char)(0xFD),(signed char)(0x9E)};  //扫码模块初始化协议
signed char StaDec[] = {(signed char)(0x04),(signed char)(0xE4),(signed char)(0x04),(signed char)(0x00),(signed char)(0xFF),(signed char)(0x14)};   //扫码模块扫码协议
    
boolean flag_SetSeiDecMod = true;    //扫码模块初始化标志位
boolean flag_StaDec = false;        //扫码模块扫码标志位
int i,j;
int Position = 0;            //字符在字符串里的位置
char scanflag = ' ';         //字符串最后一位字符  e.g  ZJGXDS01   返回 1

my_Scan::my_Scan(int pin0,int pin1)
{
    Serial.begin(9600);
    BarcodeSerial.begin(9600);
}

char my_Scan::get_char()
{
    char get_char = ' ';
   
   if(flag_SetSeiDecMod == true)       //模块初始化功能
   {
      for(i = 0;i < sizeof(SetSeiDecMod);i++)
      {
        BarcodeSerial.write(SetSeiDecMod[i]);
        delay(1);
      }
      flag_SetSeiDecMod = 0;
      flag_StaDec = 1;
   }

   if(flag_StaDec == 1)     //模块扫码功能
   {
      for(i = 0;i < sizeof(StaDec);i++)
      {
         BarcodeSerial.write(StaDec[i]);
         delay(1);
       }
    }
   delay(10);    
   while(BarcodeSerial.available())    //所扫的字符串返回
   {
        char inChar = (char)BarcodeSerial.read();
        delay(5);
        SciString += inChar;
   }
   
   Position = SciString.indexOf('Z');  //找到字符Z的位置  

   if(Position != -1)   //字符'Z'找到
   {
      SciString = SciString.substring(Position,SciString.length());  //截取有效字符串 e.g    sdaaf,ZJGXDS01 --------->  ZJGXDS01
                                                                     //                        返回的字符串        截取到有效的字符串                                                              
      get_char = SciString.charAt(7);  // 返回第7位字符  e.g   ZJGXDS01  ---->    1

      SciString  = ""; //接受字符串清空 

      return get_char; //返回有效字符串的最后一位字符
   }
   else   //字符'Z'未能找到   
   {
      flag_SetSeiDecMod = 1;  //初始化标志位  方便第二次扫码
      flag_StaDec   = 0;
      
      SciString  = ""; //接受字符串清空 
      
      get_char = ' ';  //返回空字符
      return get_char;
    } 
}

void my_Scan::clear()
{
    while(BarcodeSerial.read() >= 0){}
}