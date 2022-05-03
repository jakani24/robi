/*
 * powered by Jakach (jakach.w3spaces.com)
 * copyright Janis Steiner & Jakach
 * written and debuged by Janis Steiner 
 * description:
 * The Programm is designed to drive a simple roboter with two touch sensors 
 * and a random turning loop.
 * Feel free to use and change the full code :)
 * The targeting microcontroller is a ESP32
 */
#define mot_one_left 13
#define mot_one_right 12
#define mot_two_left 14
#define mot_two_right 27

#define start_pin 34
int s_l_l,s_l_r,s_r_r,s_r_l,cnt,buf,start_=0;
void forward_()
{
  stop_();
  digitalWrite(mot_one_left,HIGH);
  digitalWrite(mot_two_right,HIGH);
}

void backward_()
{
  stop_();
  digitalWrite(mot_one_right,HIGH);
  digitalWrite(mot_two_left,HIGH);  
}
void left_()
{
  stop_();
  digitalWrite(mot_two_right,HIGH);
}
void right_()
{
  stop_();
  digitalWrite(mot_one_left,HIGH);
}
void stop_()
{
  digitalWrite(mot_one_left,LOW);
  digitalWrite(mot_one_right,LOW);
  digitalWrite(mot_two_left,LOW);
  digitalWrite(mot_two_right,LOW);
}
void start_d()
{
  Serial.println("start");
  forward_();
  delay(1000);
  stop_();
  left_();
  delay(100);
  forward_();
  delay(200);
  Serial.println("/start");
}
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(mot_one_left,OUTPUT);
  pinMode(mot_one_right,OUTPUT);
  pinMode(mot_two_left,OUTPUT);
  pinMode(mot_two_right,OUTPUT);


  pinMode(start_pin,INPUT);
  start_=0;
  cnt=470;
  while(true)
    test();
}

void loop() {

//  while((digitalRead(start_pin))==LOW)
 // {
   // delay(100);
  //}
  // put your main code here, to run repeatedly:
  if(start_<100)
  {
  start_++;
  }
 // Serial.println(start_);
  if(start_==15)
  {
    start_d();
  }
  cnt++;
  delay(10);
    //Serial.println(start_);
    //Serial.println(cnt);
    //Serial.println();
    if(cnt>=300&&start_>20)
    {
      cnt=0;
      //Serial.println(cnt);
      buf=random(1,4);
      switch(buf)
      {
        case 1:
          left_();
          delay(1000);
          forward_();
          Serial.println("lt");
        break;
        case 2:
          right_();
          delay(1000);
          forward_();
          Serial.println("rt");
        break;
        case 3:
          backward_();
          delay(2000);
          forward_();
          Serial.println("bw");
        break;
      }
      Serial.println(buf);
    }
}

void test()
{
  Serial.println("forward");
  forward_();
  delay(3000);
  backward_();
  Serial.println("backward");
  delay(3000);
  left_();
  Serial.println("left");
  delay(3000);
  right_();
  Serial.println("right");
  delay(3000);
  Serial.println("test ended");
}
