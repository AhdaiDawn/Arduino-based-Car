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
// void tiaozheng()//原地调整
// {
//     while(1)
//     {
//         int flag = get_IS1();
//         if(flag==2)
//         {
//             turn(TURN_RIGHT);
//         }
//         else if(flag==4)
//         {
//             turn(TURN_LIFT);
//         }
        
//         else
//         {
//             stop_init();
//             break;
//         }

//     }
    
// }
