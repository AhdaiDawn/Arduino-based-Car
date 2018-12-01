/**************************
 * 0000 0 stop
 * 0001 1 right1
 * 0010 2 right3
 * 0011 3 right2
 * 0100 4 left3
 * 0110 6 FORWARD
 * 0111 7 flag2
 * 1000 8 left1
 * 1100 12  left2
 * 1111 15  flag1
 ********/ 
 
//红外1
int get_IS1()
{
    int IS_value = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0;

    s1 = digitalRead(trac0);
    s2 = digitalRead(trac1);
    s3 = digitalRead(trac2);
    s4 = digitalRead(trac3);

    IS_value = (s1 << 3) + (s2 << 2) + (s3 << 1) + s4;

    return IS_value;
}
//红外2
int get_IS2()
{
    int IS_value = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0;

    s1 = digitalRead(trac4);
    s2 = digitalRead(trac5);
    s3 = digitalRead(trac6);
    s4 = digitalRead(trac7);

    IS_value = (s1 << 3) + (s2 << 2) + (s3 << 1) + s4;

    return IS_value;
}