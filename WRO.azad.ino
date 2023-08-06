#include<Servo.h>

 Servo wheel;

#define s0 9
#define s1 10
#define s2 11
#define s3 12
#define sout 13

 #define moti1 4
 #define moti2 5
 #define moti3 6
 #define moti4 7



  int redmin =21;
  int redmax =111;
  int greenmin = 27;
  int greenmax = 172;
  int bluemin = 20;
  int bluemax = 144;

  int red = 0;
  int green = 0;
  int blue = 0;

  int redv;
  int greenv;
  int bluev;

void setup() {
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(sout, INPUT);
  
   pinMode(moti1, OUTPUT);
   pinMode(moti2, OUTPUT);
   pinMode(moti3, OUTPUT);
   pinMode(moti4, OUTPUT);

    digitalWrite(s0, HIGH);
    digitalWrite(s1, LOW);

     wheel.attach(8);
     wheel.write(90);

Serial.begin(9600);
delay(2000);
}

void loop() {
  digitalWrite(moti1, LOW);
  analogWrite(moti2, 200);
  
    red = getred();
    redv= map(red, redmin, redmax,255,0);
    delayMicroseconds(10);
  
      green = getgreen();
      greenv = map(green, greenmin, greenmax,255,0);
      delayMicroseconds(10);
  
         blue = getblue();
         bluev = map(blue, bluemin,bluemax,255,0);
         delayMicroseconds(10);

 
              
  if((redv >= 221) && (redv <= 239)
     && (greenv >= 183) && (greenv <= 209)
     && (bluev >= 171) && (bluev <= 210)){
       wheel.write(10);
       delay(1750);
  
  }
                  
     else if((redv >= 165) && (redv <= 205)
             && (greenv >= 220) && (greenv <= 235)
             && (bluev >= 220) && (bluev <= 250))
               {wheel.write(170);
                delay(1750);
      }
       else if(redv > 245 && greenv > 245 && bluev > 245){
             wheel.write(90);  
        }
 

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
#include<Servo.h>

Servo wheel;
int degree = 90;

#define s0 9
#define s1 10
#define s2 11
#define s3 12

#define moti1 4
#define moti2 5
#define moti3 6
#define moti4 7

#define sout 13

int redmin =52;
int redmax =419;
int greenmin = 58;
int greenmax = 556;
int bluemin = 38;
int bluemax = 382;

int red = 0;
int green = 0;
int blue = 0;

int redv;
int greenv;
int bluev;


void setup() {
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);

  pinMode(moti1, OUTPUT);
  pinMode(moti2, OUTPUT);
  pinMode(moti3, OUTPUT);
  pinMode(moti4, OUTPUT);

  pinMode(sout, INPUT);

  digitalWrite(s0, HIGH);
  digitalWrite(s1, LOW);

  wheel.attach(8);
  wheel.write(90);

  Serial.begin(9600);
delay(2000);
}

void loop() {
  digitalWrite(moti2, LOW);
  analogWrite(moti1, 0);
  
  red = getred();
  redv= map(red, redmin, redmax,255,0);
  delayMicroseconds(10);
  
  
  green = getgreen();
  greenv = map(green, greenmin, greenmax,255,0);
  delayMicroseconds(10);
 
  
  blue = getblue();
  bluev = map(blue, bluemin,bluemax,255,0);
  delayMicroseconds(10);
  //delay(500);

  Serial.print("Red = ");
  Serial.print(red);
  Serial.print(" - Green = ");
  Serial.print(green);
  Serial.print(" - Blue = ");
  Serial.println(blue);
  delay(500);
 


  /*OrangeCheck*/if(red >= 50 && red <= 70
&& green >= 80 && green <= 100
&& blue >= 60 && blue <= 80 && degree == 90){
  degree = 45;
  wheel.write(degree);
  delay(750);
}
delayMicroseconds(10);
     /*BlueCheck*/if(red >= 90 && red <= 110
&& green >= 90 && green <= 110
&& blue >= 50 && blue <= 70 && degree == 90)
   degree = 135;
  {wheel.write(degree);
  delay(750);
  }
delayMicroseconds(10);
   if(red >= 40 && red <= 60
&& green >= 50 && green <= 70
&& blue >= 30 && blue <= 50 && degree != 90){
  degree = 90;
  wheel.write(degree); 
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
