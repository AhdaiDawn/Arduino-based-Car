//转弯方向定义

#include "rgb_lcd.h"
rgb_lcd lcd;
#define TURN_LIFT 0
#define TURN_RIGHT 1
//左边电机接口定义
#define MOTOR_L1_FORWARD 30
#define MOTOR_L1_BACK 31
#define MOTOR_L2_FORWARD 32
#define MOTOR_L2_BACK 33
//右边电机接口定义
#define MOTOR_R1_FORWARD 42
#define MOTOR_R1_BACK 43
#define MOTOR_R2_FORWARD 44
#define MOTOR_R2_BACK 45

int GD = 2; //光电开关

void setup()
{
  Serial.begin(9600);

  //光电开关
  pinMode(GD, INPUT);

  //直流电机
  pinMode(MOTOR_L1_FORWARD, OUTPUT);
  pinMode(MOTOR_L1_BACK, OUTPUT);
  pinMode(MOTOR_L2_FORWARD, OUTPUT);
  pinMode(MOTOR_L2_BACK, OUTPUT);


  pinMode(MOTOR_R1_FORWARD, OUTPUT);
  pinMode(MOTOR_R1_BACK, OUTPUT);
  pinMode(MOTOR_R2_FORWARD, OUTPUT);
  pinMode(MOTOR_R2_BACK, OUTPUT);

  //显示屏
  lcd.begin(16, 2);
  lcd.setRGB(255, 255, 255);

}

void loop()
{
  turn(TURN_LIFT);
delay(500);
forward();
     delay(800);
     turn(TURN_RIGHT);
        delay(800);
  stop(100);
  while(1);
}










void tiaozheng()
{
  int i = digitalRead(GD);
  i = digitalRead(GD);
  if (i == 1)
  {
    while (1) {
      back(20);
      stop_init();
      delay(100);
      if ((digitalRead(GD)) == 0)
        break;
    }
  } else if (i == 0)
  {
    while (1) {
      forward();
      delay(20);
      stop_init();
      delay(100);
      if ((digitalRead(GD)) == 1)
        break;
    }
  }
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
  //  digitalWrite(MOTOR_R1_BACK, LOW);
  //  digitalWrite(MOTOR_R2_BACK, LOW);
  //  digitalWrite(MOTOR_L1_BACK, LOW);
  //  digitalWrite(MOTOR_L2_BACK, LOW);
  //
  //  digitalWrite(MOTOR_L1_FORWARD, LOW);
  //  digitalWrite(MOTOR_L2_FORWARD, LOW);
  //  digitalWrite(MOTOR_R1_FORWARD, LOW);
  //  digitalWrite(MOTOR_R2_FORWARD, LOW);
  //  delay(10);
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

      // analogWrite(MOTOR_L_SPEED, 255);
      // analogWrite(MOTOR_R_SPEED, 255);
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

      // analogWrite(MOTOR_L_SPEED, 255);
      // analogWrite(MOTOR_R_SPEED, 255);
      break;
  }
}
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
