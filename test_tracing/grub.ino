int grub(int j, int jishu,int j1)                              
{
    int flag = 1;
    servo.runActionGroup(2); //扫码近处
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
                servo.runActionGroup(3); //从物料架夹取
                delay(2000);
                step(j, 0);
                servo.runActionGroup(6); //放在小车上
                delay(4000);
                step(0, j);
            }
            else if (flag_scan == a[1])
            {
                jishu++;
                servo.runActionGroup(3); //从物料架夹取
                delay(2000);
                step(j, 37);
                servo.runActionGroup(6); //放在小车上
                delay(4000);
                step(37, j);
            }
            else if (flag_scan == a[2])
            {
                jishu++;
                servo.runActionGroup(3); //从物料架夹取
                delay(2000);
                step(j, 74);
                servo.runActionGroup(6); //放在小车上
                delay(4000);
                step(74, j);
            }
            else if (flag_scan == a[3])
            {
                jishu++;
                servo.runActionGroup(3); //从物料架夹取
                delay(2000);
                step(j, 0);
                servo.runActionGroup(5); //放在小车上
                delay(1000);
                step(0, j);
            }
            else if (flag_scan == a[4])
            {
                jishu++;
                servo.runActionGroup(3); //从物料架夹取
                delay(2000);
                step(j, 37);
                servo.runActionGroup(5); //放在小车上
                delay(1000);
                step(37, j);
            }
            else if (flag_scan == a[5])
            {
                jishu++;
                servo.runActionGroup(3); //从物料架夹取
                delay(2000);
                step(j, 74);
                servo.runActionGroup(5); //放在小车上
                delay(1000);
                step(74, j);
            }
            scan.clear();
            flag_scan = ' ';
            if (jishu == 6)
            {
                delay(100);
                flag = 0;
                servo.runActionGroup(0);
                step(j, 15);
                 
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
        servo.runActionGroup(1); //扫码远处
        scan.clear();
         delay(800);
          TIME=millis()+6000;
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
                    servo.runActionGroup(4); //从物料架夹取
                    delay(2000);
                    step(j, 0);
                    servo.runActionGroup(6); //放在小车上
                    delay(4000);
                    step(0, j1);
                }
                else if (flag_scan == a[1])
                {
                    jishu++;
                    servo.runActionGroup(4); //从物料架夹取
                    delay(2000);
                    step(j, 37);
                    servo.runActionGroup(6); //放在小车上
                    delay(4000);
                    step(37, j1);
                }
                else if (flag_scan == a[2])
                {
                    jishu++;
                    servo.runActionGroup(4); //从物料架夹取
                    delay(2000);
                    step(j, 74);
                    servo.runActionGroup(6); //放在小车上
                    delay(4000);
                    step(74, j1);
                }
                else if (flag_scan == a[3])
                {
                    jishu++;
                    servo.runActionGroup(4); //从物料架夹取
                    delay(2000);
                    step(j, 0);
                    servo.runActionGroup(5); //放在小车上
                    delay(1000);
                    step(0, j1);
                }
                else if (flag_scan == a[4])
                {
                    jishu++;
                    servo.runActionGroup(4); //从物料架夹取
                    delay(2000);
                    step(j, 37);
                    servo.runActionGroup(5); //放在小车上
                    delay(1000);
                    step(37, j1);
                }
                else if (flag_scan == a[5])
                {
                    jishu++;
                    servo.runActionGroup(4); //从物料架夹取
                    delay(2000);
                    step(j, 74);
                    servo.runActionGroup(5); //放在小车上
                    delay(1000);
                    step(74, j1);
                }
                else 
                {
                    servo.runActionGroup(2); 
                    delay(1000);
                    step(j, j1);
                }
                if (jishu == 6)
                {
                    delay(100);
                     servo.runActionGroup(0);
                    step(j1, 15);
                    
                }
                scan.clear();
                flag_scan = ' ';
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