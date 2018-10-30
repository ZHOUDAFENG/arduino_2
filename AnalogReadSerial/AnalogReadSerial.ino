int servopin=9;//设置舵机驱动脚到数字口9
int myangle;//定义角度变量
int pulsewidth;//定义脉宽变量
int val;
void servopulse(int servopin,int myangle)/*定义一个脉冲函数，用来模拟方式产生PWM值*/
{
  pulsewidth=(myangle*11)+500;//将角度转化为500-2480 的脉宽值
  digitalWrite(servopin,HIGH);//将舵机接口电平置高
  delayMicroseconds(pulsewidth);//延时脉宽值的微秒数
  digitalWrite(servopin,LOW);//将舵机接口电平置低
  delay(20-pulsewidth/1000);//延时周期内剩余时间
}
void setup()
{
  pinMode(servopin,OUTPUT);//设定舵机接口为输出接口
  Serial.begin(9600);//设置波特率为9600
  Serial.println("servo=o_seral_simple ready" ) ;
}
void loop()
{
  int val=0;
  while(1){
    
    servopulse(servopin,val);
    val+=1;
    if(val>=180){
      val=0;
      }
  }
}
