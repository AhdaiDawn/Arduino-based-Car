//调整  有 0 无1
void tiaozheng()//
{
    int i=digitalRead(GD);
    i=digitalRead(GD);
    if(i==1)
    {
        while(1)
        {
            back(15);
            stop_init();
            delay(100);
            if((digitalRead(GD))==0)
                break;
        }
    }
    else if(i==0)
    {
        while(1)
        {
            forward();
            delay(15);
            stop_init();
            delay(100);
            if((digitalRead(GD))==1)
                break;
        }
    }
}
void tiaozheng_4()//上料区第四个
{
    int s3 = digitalRead(trac6);
    int s4 = digitalRead(trac7);
    if((s3==0)&&(s4==1))
    {
        while(1)
        {
            back(15);
            stop_init();
            delay(100);
            s3 = digitalRead(trac6);
            if((s3==1))
                break;
        }
    }
    else if((s3==1)&&(s4==0))
    {
        while(1)
        {
            forward();
            delay(15);
            stop_init();
            delay(100);
            s4 = digitalRead(trac7);
            if(s4==1)
                break;
        }
    }
}


//下料
void tiaozheng_1()//下料料区第1个
{
    int s = digitalRead(trac4);
    if(s==0)
    {
        while(1)
        {
            back(15);
            stop_init();
            delay(100);
            s = digitalRead(trac4);
            if(s==1)
            {
            forward();
            delay(35);
            stop_init();
                break;
            }
        }
    }
    else if(s==1)
    {
        while(1)
        {
            forward();
            delay(15);
            stop_init();
            delay(100);
            s = digitalRead(trac4);
            if(s==0)
            {
            forward();
            delay(35);
            stop_init();
                break;
            }
                
        }
    }
}
void tiaozheng_2()//下料料区第2个
{
    int s = digitalRead(trac4);
    if(s==0)
    {
        while(1)
        {
            back(15);
            stop_init();
            delay(100);
            s = digitalRead(trac4);
            if(s==1)
            {
    
                break;
            }
        }
    }
    else if(s==1)
    {
        while(1)
        {
            forward();
            delay(15);
            stop_init();
            delay(100);
            s = digitalRead(trac4);
            if(s==0)
            {
                break;
            }
                
        }
    }
}
void tiaozheng_3()//下料区第3个
{
    int s3 = digitalRead(trac6);
    int s4 = digitalRead(trac7);
    if((s3==0)&&(s4==1))
    {
        while(1)
        {
            back(15);
            stop_init();
            delay(100);
            s3 = digitalRead(trac6);
            if((s3==1))
            {
                forward();
                delay(50);
                stop(0);

            }
                break;
        }
    }
    else if((s3==1)&&(s4==0))
    {
        while(1)
        {
            forward();
            delay(15);
            stop_init();
            delay(100);
            s4 = digitalRead(trac7);
            if((s4==1))
            {
                forward();
                delay(50);
                stop(0);

            }
        }
    }
}
int tracing()//消除动态误差
{
    int flag = get_IS1();
    switch (flag)
    {
    case 0:
    {
        turn(TURN_LIFT);

    }
    break;
    case 1:
    {
        turn(TURN_RIGHT);
    }
    break;
    
    case 3:
    {
        turn(TURN_RIGHT);
    }
    break;
    case 2:
    {
         
       turn(TURN_RIGHT);
       forward();
    }
    break;
    case 8:
    {
        turn(TURN_LIFT);
    }
    break;
    case 12:
    {
        turn(TURN_LIFT);
    }
    break;
    case 4:
    {
        
         turn(TURN_LIFT);
         forward();
    }
    break;
    default:
        forward();
        break;
    }
    return flag;
}

int tracing_p()//爬坡
{
    int flag = get_IS1();
    switch (flag)
    {
    case 2:
    {
         
       turn(TURN_RIGHT);
        forward();
    }
    break;
    case 4:
    {
        
         turn(TURN_LIFT);
        forward();
    }
    break;
    default:
        forward();
        break;
    }
    return flag;
}
void tracing_time(unsigned long time)
{
  unsigned long TIME=millis()+time;
  while(1)
  {
      tracing();
      if(millis()>=TIME)
      {
          break;
      }
  }
}
