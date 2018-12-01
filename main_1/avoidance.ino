int getDistance()
{
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

    if ((cm >= 35)||(cm<=1))
    {
        //如果距离小于80厘米返回数据
        cm = 10000;
        return cm;
    } //如果距离小于80厘米小灯熄灭
    else
        return cm;
}

int avoidance()
{
    int i=0;
    int dis; //距离
    dis = getDistance(); //中间

    if (dis < 35)
    {
       stop(200);
        // delay(1000);
        //左转
        turn(TURN_LIFT);
        delay(500); //每个命令执行2s
        forward();
        delay(800);
        turn(TURN_RIGHT);
        delay(800);
        forward();
       
       
       while(1){
           if(get_IS1()==6){
               turn(TURN_LIFT);
               delay(400);
               break;
           }
       }
        i=1;
       
       
    }
    return i;
}