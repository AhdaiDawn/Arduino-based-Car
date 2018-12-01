void step(int a, int C)//步进电机,a为当前位置,b为执行完位置
{
  int x;
  x = C - a;
  stepper.rotate(90 * (x));
}
void step_init()//步进电机初始化
{
  
  digitalWrite(DIR, LOW); // 电机前进

  for (int x = 0; x < (100 * 50); x++) // Loop 2000 times
  {
    digitalWrite(STEP, HIGH); // Output high
    delayMicroseconds(500);  // Wait 1/2 a ms
    digitalWrite(STEP, LOW);  // Output low
    delayMicroseconds(500);  // Wait 1/2 a ms
    if (digitalRead(KEY) == LOW)
      x = 100 * 50;
  }
}
