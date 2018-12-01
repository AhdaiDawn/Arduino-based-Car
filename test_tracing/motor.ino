void stop_init()
{
    lcd.setCursor(0, 1);
    lcd.print("STOP      "); //输出状态
    digitalWrite(MOTOR_R1_BACK, LOW);
    digitalWrite(MOTOR_R2_BACK, LOW);
    digitalWrite(MOTOR_L1_BACK, LOW);
    digitalWrite(MOTOR_L2_BACK, LOW);

    digitalWrite(MOTOR_L1_FORWARD, LOW);
    digitalWrite(MOTOR_L2_FORWARD, LOW);
    digitalWrite(MOTOR_R1_FORWARD, LOW);
    digitalWrite(MOTOR_R2_FORWARD, LOW);
}
//前进
void forward()
{
    lcd.setCursor(0, 1);
    lcd.print("FORWARD   "); //输出状

    digitalWrite(MOTOR_R1_BACK, LOW);
    digitalWrite(MOTOR_R2_BACK, LOW);
    digitalWrite(MOTOR_L1_BACK, LOW);
    digitalWrite(MOTOR_L2_BACK, LOW);
    digitalWrite(MOTOR_L1_FORWARD, HIGH);
    digitalWrite(MOTOR_L2_FORWARD, HIGH);
    digitalWrite(MOTOR_R1_FORWARD, HIGH);
    digitalWrite(MOTOR_R2_FORWARD, HIGH);
}
//停止
void stop(int i)
{
    lcd.setCursor(0, 1);
    lcd.print("STOP      "); //输出状态
    // digitalWrite(MOTOR_R1_BACK, LOW);
    // digitalWrite(MOTOR_R2_BACK, LOW);
    // digitalWrite(MOTOR_L1_BACK, LOW);
    // digitalWrite(MOTOR_L2_BACK, LOW);

    // digitalWrite(MOTOR_L1_FORWARD, LOW);
    // digitalWrite(MOTOR_L2_FORWARD, LOW);
    // digitalWrite(MOTOR_R1_FORWARD, LOW);
    // digitalWrite(MOTOR_R2_FORWARD, LOW);
    // delay(100);
    digitalWrite(MOTOR_L1_FORWARD, LOW);
    digitalWrite(MOTOR_L2_FORWARD, LOW);
    digitalWrite(MOTOR_R1_FORWARD, LOW);
    digitalWrite(MOTOR_R2_FORWARD, LOW);

    digitalWrite(MOTOR_R1_BACK, HIGH);
    digitalWrite(MOTOR_R2_BACK, HIGH);
    digitalWrite(MOTOR_L1_BACK, HIGH);
    digitalWrite(MOTOR_L2_BACK, HIGH);

    delay(i);
    digitalWrite(MOTOR_R1_BACK, LOW);
    digitalWrite(MOTOR_R2_BACK, LOW);
    digitalWrite(MOTOR_L1_BACK, LOW);
    digitalWrite(MOTOR_L2_BACK, LOW);

    digitalWrite(MOTOR_L1_FORWARD, LOW);
    digitalWrite(MOTOR_L2_FORWARD, LOW);
    digitalWrite(MOTOR_R1_FORWARD, LOW);
    digitalWrite(MOTOR_R2_FORWARD, LOW);

}
//后退
void back(int i)
{
    digitalWrite(MOTOR_L1_FORWARD, LOW);
    digitalWrite(MOTOR_L2_FORWARD, LOW);
    digitalWrite(MOTOR_R1_FORWARD, LOW);
    digitalWrite(MOTOR_R2_FORWARD, LOW);

    digitalWrite(MOTOR_R1_BACK, HIGH);
    digitalWrite(MOTOR_R2_BACK, HIGH);
    digitalWrite(MOTOR_L1_BACK, HIGH);
    digitalWrite(MOTOR_L2_BACK, HIGH);
    delay(i);
}
//转弯
void turn(int Cmd)
{
    switch (Cmd)
    {
    case TURN_LIFT: //左转   右电机前进 左电机后退
        lcd.setCursor(0, 1);
        lcd.print("TURN_LEFT "); //输出状态
        digitalWrite(MOTOR_R1_BACK, LOW);
        digitalWrite(MOTOR_R2_BACK, LOW);
        digitalWrite(MOTOR_L1_FORWARD, LOW);
        digitalWrite(MOTOR_L2_FORWARD, LOW);

        digitalWrite(MOTOR_R1_FORWARD, HIGH);
        digitalWrite(MOTOR_R2_FORWARD, HIGH);
        digitalWrite(MOTOR_L1_BACK, HIGH);
        digitalWrite(MOTOR_L2_BACK, HIGH);

        break;

    case TURN_RIGHT: //右转   右电机后退 左电机前进
        lcd.setCursor(0, 1);
        lcd.print("TURN_RIGHT"); //输出状态
        digitalWrite(MOTOR_R1_FORWARD, LOW);
        digitalWrite(MOTOR_R2_FORWARD, LOW);
        digitalWrite(MOTOR_L1_BACK, LOW);
        digitalWrite(MOTOR_L2_BACK, LOW);

        digitalWrite(MOTOR_R1_BACK, HIGH);
        digitalWrite(MOTOR_R2_BACK, HIGH);
        digitalWrite(MOTOR_L1_FORWARD, HIGH);
        digitalWrite(MOTOR_L2_FORWARD, HIGH);


        break;

    default:
        digitalWrite(MOTOR_R1_BACK, LOW);
        digitalWrite(MOTOR_R2_BACK, LOW);
        digitalWrite(MOTOR_L1_BACK, LOW);
        digitalWrite(MOTOR_L2_BACK, LOW);
        digitalWrite(MOTOR_L1_FORWARD, HIGH);
        digitalWrite(MOTOR_L2_FORWARD, HIGH);
        digitalWrite(MOTOR_R1_FORWARD, HIGH);
        digitalWrite(MOTOR_R2_FORWARD, HIGH);

        break;
    }
}
void turn_DD(int Cmd)
{
    switch (Cmd)
    {
    case TURN_LIFT: //左转   右电机前进 左电机后退
        lcd.setCursor(0, 1);
        lcd.print("TURN_LEFT "); //输出状态
    digitalWrite(MOTOR_R1_BACK, LOW);
    digitalWrite(MOTOR_R2_BACK, LOW);
    digitalWrite(MOTOR_L1_BACK, LOW);
    digitalWrite(MOTOR_L2_BACK, LOW);
    digitalWrite(MOTOR_L1_FORWARD, LOW);
    digitalWrite(MOTOR_L2_FORWARD, LOW);
    digitalWrite(MOTOR_R1_FORWARD, HIGH);
    digitalWrite(MOTOR_R2_FORWARD, HIGH);

        break;

    case TURN_RIGHT: //右转   右电机后退 左电机前进
        lcd.setCursor(0, 1);
        lcd.print("TURN_RIGHT"); //输出状态
    digitalWrite(MOTOR_R1_BACK, LOW);
    digitalWrite(MOTOR_R2_BACK, LOW);
    digitalWrite(MOTOR_L1_BACK, LOW);
    digitalWrite(MOTOR_L2_BACK, LOW);
    digitalWrite(MOTOR_L1_FORWARD, HIGH);
    digitalWrite(MOTOR_L2_FORWARD, HIGH);
    digitalWrite(MOTOR_R1_FORWARD, LOW);
    digitalWrite(MOTOR_R2_FORWARD, LOW);


        break;

    default:
        digitalWrite(MOTOR_R1_BACK, LOW);
        digitalWrite(MOTOR_R2_BACK, LOW);
        digitalWrite(MOTOR_L1_BACK, LOW);
        digitalWrite(MOTOR_L2_BACK, LOW);
        digitalWrite(MOTOR_L1_FORWARD, HIGH);
        digitalWrite(MOTOR_L2_FORWARD, HIGH);
        digitalWrite(MOTOR_R1_FORWARD, HIGH);
        digitalWrite(MOTOR_R2_FORWARD, HIGH);

        break;
    }
}