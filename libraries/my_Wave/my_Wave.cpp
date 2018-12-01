#include "my_Wave.h"
my_Wave::my_Wave(int pin0,int pin1)
{
    Serial.begin(9600);
    pinMode(pin0, OUTPUT);
    pinMode(pin1, INPUT);
}
int my_Wave:: getDistance()
{
    float cm;      //距离变量
    float temp;    //
    digitalWrite(Trig, LOW);           //给Trig发送一个低电平
    delayMicroseconds(2);              //等待 2微妙
    digitalWrite(Trig, HIGH);          //给Trig发送一个高电平
    delayMicroseconds(10);             //等待 10微妙
    digitalWrite(Trig, LOW);           //给Trig发送一个低电平
    temp = float(pulseIn(Echo, HIGH)); // 读出脉冲时间
    cm = (temp * 17) / 1000;           // 将脉冲时间转化为距离（单位：厘米）
    Serial.print("Echo =");
    Serial.print(temp); //串口输出等待时间的原始数据
    Serial.print(" | | Distance = ");
    Serial.print(cm); //串口输出距离换算成cm的结果
    Serial.println("cm");
    // delay(100);

    if (cm >= 45 || cm <= 1)
    {
        //如果距离小于45厘米返回数据***其中的cm<=1是为了防止超声波第一次读数为0
        cm = 10000;
        return cm;
    } //如果距离小于45厘米小灯熄灭
    else
        return cm;
}