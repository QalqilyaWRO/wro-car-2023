#include <SPI.h>
#include <Pixy2.h>
Pixy2 pixy;

//#include<Servo.h>

//Servo wheel;
//int degree = 90;

#define s0 9
#define s1 10
#define s2 11
#define s3 12

#define moti1 4
#define moti2 5
#define moti3 6
#define moti4 7
#define ena1 3
#define ena2 2
float deadZone = 0.5;

int cont = 0;
int signature, x, y, width, height;
float cx, cy, area;

#define sout 13
int rounds = 0;

int red = 0;
int green = 0;
int blue = 0;


void setup() {
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);// حساس الألوان
  pinMode(s3, OUTPUT);

  pinMode(moti1, OUTPUT);
  pinMode(moti2, OUTPUT);
  pinMode(moti3, OUTPUT);// الدرايفر
  pinMode(moti4, OUTPUT);
  pinMode(ena1, OUTPUT);
  pinMode(ena2, OUTPUT);
  pinMode(sout, INPUT); // حساس الألوان

  digitalWrite(s0, HIGH);// حساس الالوان
  digitalWrite(s1, LOW);


  Serial.begin(9600);// الشاشة التي نرى عليها قراءة الألوان
  pixy.init();
delay(2000);// تأخير لمدة ثانيتين
}

void loop() {
if(rounds != 12){
     analogWrite(ena1, 100);
    }else{ analogWrite(ena1 , 0);}
     
  digitalWrite(moti2, 0);
  digitalWrite(moti1, 1); // التحكم بسرعة السيارة0-255

   red = getred();
  delayMicroseconds(10);
  
  
  green = getgreen();
  delayMicroseconds(10);
 
  
  blue = getblue();
  delayMicroseconds(10);
  
  //pixy
float turn = pixyCheck();
delayMicroseconds(10);

 
  if (signature == 2 && height >= 100) {
    analogWrite(ena2, 255);
   digitalWrite(moti3, 1);
   digitalWrite(moti4, 0);
   delay(500);
   digitalWrite(moti3, 0);
   digitalWrite(moti4, 1);
   delay(500);
   signature = 0;
   analogWrite(ena2, 255);
    digitalWrite(moti3, 0);
   digitalWrite(moti4, 0);
  }delayMicroseconds(1000);
  
   if (signature == 1 && height >= 100) {
   analogWrite(ena2, 255);
    digitalWrite(moti3, 0);
   digitalWrite(moti4, 1);
   delay(500);
    digitalWrite(moti3, 1);
   digitalWrite(moti4, 0);
   delay(500);
   
   signature = 0;
   analogWrite(ena2, 255);
    digitalWrite(moti3, 0);
   digitalWrite(moti4, 0);
  }delayMicroseconds(1000);
  /*if (signature == 0){
   digitalWrite(ena2, 1);
    digitalWrite(moti3, 0);
   digitalWrite(moti4, 0);
   
  }
  delayMicroseconds(1000);*/
  //pixy

  
    

  
 
  //delay(500);

  /*Serial.print("Red = ");
  Serial.print(red);
  Serial.print(" - Green = "); // قراءة الألوان
  Serial.print(green);
  Serial.print(" - Blue = ");  //   red = 50 - green = 30 - blue = 70
  Serial.println(blue);
  delay(250);*/
 

  /*OrangeCheck*/if(red >= 56 && red <= 66
&& green >= 90 && green <= 100
&& blue >= 70 && blue <= 80){
 // degree = 45;
  //wheel.write(degree);
  analogWrite(ena2, 255);
  digitalWrite(moti3, 0);
  digitalWrite(moti4, 1);
  delay(1300);
  rounds++;
  /*digitalWrite(moti3, HIGH);
  digitalWrite(moti4, LOW);
  delay(50);*/
}
delayMicroseconds(10);
     /*BlueCheck*/if(red >= 85 && red <= 95
&& green >= 85 && green <= 95
&& blue >= 47 && blue <= 58)
   //degree = 135;
  {//wheel.write(degree);
    analogWrite(ena2, 255);
    digitalWrite(moti3, 1);
  digitalWrite(moti4, 0);
  delay(1300);
  rounds++;
  /*digitalWrite(moti3, LOW);
  digitalWrite(moti4, HIGH);
  delay(50);*/
  }
delayMicroseconds(10);
/*WhiteCheck*/
  /* if(red >= 47 && red <= 57
&& green >= 53 && green <= 63
&& blue >= 35 && blue <= 45){
  //degree = 90;
  //wheel.write(degree); 
  analogWrite(ena2, 255);
  digitalWrite(moti3, 0);
  digitalWrite(moti4, 0);
   }
   delayMicroseconds(10);*/
}



int getred(){
digitalWrite(s2, LOW);
digitalWrite(s3, LOW);
int pw;
pw = pulseIn(sout, LOW);
return pw;
}

int getgreen(){
digitalWrite(s2, HIGH);
digitalWrite(s3, HIGH);
int pw;
pw = pulseIn(sout, LOW);
return pw;
}

int getblue(){
digitalWrite(s2, LOW);
digitalWrite(s3, HIGH);
int pw;
pw = pulseIn(sout, LOW);
return pw;
}

float pixyCheck() {
  static int i = 0;
  int j;
  uint16_t blocks;
  char buf[32];
  // grab blocks!
  blocks = pixy.ccc.getBlocks();

  // If there are detect blocks, print them!
  if (blocks)
  {
    signature = pixy.ccc.blocks[0].m_signature;
    height = pixy.ccc.blocks[0].m_height;
    width = pixy.ccc.blocks[0].m_width;
    x = pixy.ccc.blocks[0].m_x;
    y = pixy.ccc.blocks[0].m_y;
    cx = (x + (width / 2));
    cy = (y + (height / 2));
    cx = mapfloat(cx, 0, 320, -1, 1);
    cy = mapfloat(cy, 0, 200, 1, -1);
    area = width * height;

          /*  Serial.print("sig: ");
            Serial.print(signature);
            Serial.print(" x:");
            Serial.print(x);
            Serial.print(" y:");
            Serial.print(y);
            Serial.print(" width: ");
            Serial.print(width);
            Serial.print(" height: ");
            Serial.print(height);
            Serial.print(" cx: ");
            Serial.print(cx);
            Serial.print(" cy: ");
            Serial.println(cy);*/

  }
  else {
    cont += 1;
    if (cont == 100) {
      cont = 0;
      cx = 0;
    }
  }
  return cx;
}

float mapfloat(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (float)(x - in_min) * (out_max - out_min) / (float)(in_max - in_min) + out_min;
}
