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
    int trac0 = 8; //从车头方向的最左边开始排序
    int trac1 = 9;
    int trac2 = 10;
    int trac3 = 11;
    int trac4 = 7; //车右前后排序
    int trac5 = 6;
    int trac6 = 5; 
    int trac7 = 4;
void setup() {
    Serial.begin(9600);
    pinMode(trac0, INPUT);
    pinMode(trac1, INPUT);
    pinMode(trac2, INPUT);
    pinMode(trac3, INPUT);
    pinMode(trac4, INPUT);
    pinMode(trac5, INPUT);
    pinMode(trac6, INPUT);
    pinMode(trac7, INPUT);
}
void loop()
{
    int a=get_IS1();
    Serial.print("a=");
    Serial.print(a);
     int b=get_IS2();
    Serial.print("b=");
    Serial.print(b);
    Serial.print("\n");

}
int get_IS1()
{
	int IS_value = 0,s1 = 0,s2 = 0,s3 = 0,s4 = 0;
	
	s1 = digitalRead(trac0);
	s2 = digitalRead(trac1);
	s3 = digitalRead(trac2);
	s4 = digitalRead(trac3);
	
	IS_value = (s1 << 3) + (s2 << 2) + (s3 << 1) + s4;
	

	return IS_value;
}
int get_IS2()
{
	int IS_value = 0,s1 = 0,s2 = 0,s3 = 0,s4 = 0;
	
	s1 = digitalRead(trac4);
	s2 = digitalRead(trac5);
	s3 = digitalRead(trac6);
	s4 = digitalRead(trac7);
	
	IS_value = (s1 << 3) + (s2 << 2) + (s3 << 1) + s4;
	

	return IS_value;
}

