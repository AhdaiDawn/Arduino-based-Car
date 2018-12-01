int put_down(int j, int jishu,int j1)
{
    int flag = 1;
    servo.runActionGroup(8); //扫码下层
    scan.clear();
    unsigned long TIME=millis()+4000;
    while (flag_scan == ' ')
    {
        flag_scan = scan.get_char();
        delay(200);
        if (flag_scan != ' ')
        {
            lcd.setCursor(15, 1);
            lcd.print(flag_scan);
            if (flag_scan == a[0])
            {
                jishu++;
                step(j, 0);
                servo.runActionGroup(9); //从小车上夹取
                delay(5000);
                step(0, j);
                servo.runActionGroup(12); //放在上料区
                delay(4000);
            }
            else if (flag_scan == a[1])
            {
                jishu++;
                step(j, 37);
                servo.runActionGroup(9); ///从小车上夹取
                delay(5000);
                step(37, j);
                servo.runActionGroup(12); //放在上料区
                delay(4000);
            }
            else if (flag_scan == a[2])
            {
                jishu++;
                step(j, 74);
                servo.runActionGroup(9); //从小车上夹取
                delay(5000);
                step(74, j);
                servo.runActionGroup(12); //放在上料区
                delay(4000);
            }
            else if (flag_scan == a[3])
            {
                jishu++;
                step(j, 0);
                servo.runActionGroup(10); //从小车上夹取
                delay(2000);
                step(0, j);
                servo.runActionGroup(14); //放在上料区
                delay(4000);
            }
            else if (flag_scan == a[4])
            {
                jishu++;
                step(j, 37);
                servo.runActionGroup(10); //从小车上夹取
                delay(2000);
                step(37, j);
                servo.runActionGroup(14); //放在上料区
                delay(4000);
            }
            else if (flag_scan == a[5])
            {
                jishu++;
                step(j, 74);
                servo.runActionGroup(10); //从小车上夹取
                delay(2000);
                step(74, j);
                servo.runActionGroup(14); //放在上料区
                delay(4000);
            }
            scan.clear();
            flag_scan = ' ';
            if (jishu == 6)
            {
                delay(100);
                servo.runActionGroup(0);
                step(j,15);
                flag = 0;
            }
            break;
        }
        else if((flag_scan == ' ')&&(millis()>=TIME))
        {
            break;
        }
    }
    if (flag )
    {
        servo.runActionGroup(7); //扫码上层
        delay(800);
        scan.clear();
        TIME=millis()+6000;
        while (flag_scan == ' ')
        {
            flag_scan = scan.get_char();
            delay(300);
            if (flag_scan != ' ')
            {
                lcd.setCursor(15, 1);
                lcd.print(flag_scan);
                if (flag_scan == a[0])
                {
                    jishu++;
                    step(j, 0);
                    servo.runActionGroup(9); //从小车上夹取
                    delay(5000);
                    step(0, j);
                    servo.runActionGroup(11); //放在上料区
                    delay(4000);
                }
                else if (flag_scan == a[1])
                {
                    jishu++;
                    step(j, 37);
                    servo.runActionGroup(9); ///从小车上夹取
                    delay(5000);
                    step(37, j);
                    servo.runActionGroup(11); //放在上料区
                    delay(4000);
                }
                else if (flag_scan == a[2])
                {
                    jishu++;
                    step(j, 74);
                    servo.runActionGroup(9); //从小车上夹取
                    delay(5000);
                    step(74, j);
                    servo.runActionGroup(11); //放在上料区
                    delay(4000);
                }
                else if (flag_scan == a[3])
                {
                    jishu++;
                    step(j, 0);
                    servo.runActionGroup(10); //从小车上夹取
                    delay(2000);
                    step(0, j);
                    servo.runActionGroup(13); //放在上料区
                    delay(4000);
                }
                else if (flag_scan == a[4])
                {
                    jishu++;
                    step(j, 37);
                    servo.runActionGroup(10); //从小车上夹取
                    delay(2000);
                    step(37, j);
                    servo.runActionGroup(13); //放在上料区
                    delay(4000);
                }
                else if (flag_scan == a[5])
                {
                    jishu++;
                    step(j, 74);
                    servo.runActionGroup(10); //从小车上夹取
                    delay(2000);
                    step(74, j);
                    servo.runActionGroup(13); //放在上料区
                    delay(4000);
                }
                else {
                     servo.runActionGroup(8); //扫码下层
                     delay(500);
                }
                
                step(j, j1);
                scan.clear();
                flag_scan = ' ';
                if (jishu == 6)
                {
                    delay(100);
                step(j1,15);
                 servo.runActionGroup(0);
                }
                break;
            }
            else if((flag_scan == ' ')&&(millis()>=TIME))
            {
                step(j, j1);
                break;
            }
        }
    }
    return jishu;
}
