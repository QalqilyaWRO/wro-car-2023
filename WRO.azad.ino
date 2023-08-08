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
#define sp 3

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
  pinMode(sp, OUTPUT);

  pinMode(sout, INPUT); // حساس الألوان

  digitalWrite(s0, HIGH);// حساس الالوان
  digitalWrite(s1, LOW);


  Serial.begin(9600);// الشاشة التي نرى عليها قراءة الألوان
delay(2000);// تأخير لمدة ثانيتين
}

void loop() {
    if(rounds != 12){
     analogWrite(sp, 140);
    }else{ analogWrite(sp , 0);}
     
  digitalWrite(moti2, LOW);
  digitalWrite(moti1, HIGH); // التحكم بسرعة السيارة0-255

  
  red = getred();
  delayMicroseconds(10);
  
  
  green = getgreen();
  delayMicroseconds(10);
 
  
  blue = getblue();
  delayMicroseconds(10);
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
  digitalWrite(moti3, LOW);
  digitalWrite(moti4, HIGH);
  delay(1300);
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
    digitalWrite(moti3, HIGH);
  digitalWrite(moti4, LOW);
  delay(1300);
  /*digitalWrite(moti3, LOW);
  digitalWrite(moti4, HIGH);
  delay(50);*/
  }
delayMicroseconds(10);
/*WhiteCheck*/
   if(red >= 47 && red <= 57
&& green >= 53 && green <= 63
&& blue >= 35 && blue <= 45){
  //degree = 90;
  //wheel.write(degree); 
  digitalWrite(moti3, LOW);
  digitalWrite(moti4, LOW);
   }
   delayMicroseconds(10);
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
