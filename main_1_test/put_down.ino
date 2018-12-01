int put_down(int j, int jishu,int j1)
{
        servo.runActionGroup(7); //扫码上层
        scan.clear();
        delay(500);
        unsigned long TIME=millis()+5000;
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
                    servo.runActionGroup(10); //从小车上夹取
                    delay(1000);
                    step(0, j);
                    servo.runActionGroup(13); //放在上料区
                    delay(1500);
                }
                else if (flag_scan == a[1])
                {
                    jishu++;
                    step(j, 37);
                    servo.runActionGroup(10); //从小车上夹取
                    delay(1000);
                    step(37, j);
                    servo.runActionGroup(13); //放在上料区
                    delay(1500);
                }
                else if (flag_scan == a[2])
                {
                    jishu++;
                    step(j, 74);
                    servo.runActionGroup(10); //从小车上夹取
                    delay(1000);
                    step(74, j);
                    servo.runActionGroup(13); //放在上料区
                    delay(1500);
                }

                if (jishu == 3)
                {
                    delay(100);
                step(j,15);
                 servo.runActionGroup(0);
                }
                else
                {
                step(j, j1);
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
    return jishu;
}
