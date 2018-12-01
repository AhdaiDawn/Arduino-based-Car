int grub(int j, int jishu,int j1)                              
{
    servo.runActionGroup(2); //扫码近处
    scan.clear();
    unsigned long TIME=millis()+4500;
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
                servo.runActionGroup(5); //放在小车上
                delay(1000);
                step(0, j1);
            }
            else if (flag_scan == a[1])
            {
                jishu++;
                servo.runActionGroup(3); //从物料架夹取
                delay(2000);
                step(j, 37);
                servo.runActionGroup(5); //放在小车上
                delay(1000);
                step(37, j1);
            }
            else if (flag_scan == a[2])
            {
                jishu++;
                servo.runActionGroup(3); //从物料架夹取
                delay(2000);
                step(j, 74);
                servo.runActionGroup(5); //放在小车上
                delay(1000);
                step(74, j1);
            }
            else{
                step(j, j1);
            }
            scan.clear();
            flag_scan = ' ';
            if (jishu == 3)
            {
                delay(100);
                servo.runActionGroup(0);
                step(j1, 15);
                 
            }
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