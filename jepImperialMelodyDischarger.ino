//Star Wars Legion
//Storm Tropper Helmet
//by John Edgar Park jpixl.net
// this code controls the Storm Trooper helmet/music box art project I created named Imperial Melody Discharger.


//some code samples thanks to:
// Sweep - BARRAGAN <http://barraganstudio.com> 
 //and
// http://adafruit.com/forums/viewtopic.php?f=25&p=170965


#include <Servo.h> 
 
const int ledGreenPin =  11;    //  number of the green LED pin
const int ledRedPin =  12;      //  number of the red LED pin
const int ledPowerPin = 13;     //  number of the chin LED pin
int speakerPin = 6;             //  number of the piezo buzzer/speaker pin
int powerOffPin = 3;            //  number of the power switch power off pin

Servo myservoR;  // create servo object to control  right one on storm trooper face
Servo myservoL;  // create servo object to control left on on storm trooper face

int sRclosed = 148;     // variable to store closed position value of servo on right
int sRopened = 120;     // variable to store opened position value of servo on right
int sLclosed = 18;      // variable to store closed position value of servo on left
int sLopened = 50;      // variable to store closed position value of servo on left 
int posR = sRclosed;    // variable to store the servo position initially, the closed position for Storm Trooper
int posL = sLclosed;    // variable to store the servo position initially, the closed position for Storm Trooper
 
const int openDelay=25;  // speed of the servos when opening
const int closeDelay=15; // speed of the servos when closing
 
//tone frequencies http://home.(m-eye-t).bme.hu/~bako/tonecalc/tonecalc.htm
#define c 261
#define d 294
#define e 329
#define f 349
#define g 391
#define gS 415
#define a 440
#define aS 455
#define b 466
#define cH 523
#define cSH 554
#define dH 587
#define dSH 622
#define eH 659
#define fH 698
#define fSH 740
#define gH 784
#define gSH 830
#define aH 880 
///////////////////////////// end includes

  
void setup() { 
    
    pinMode(ledGreenPin, OUTPUT);      
    pinMode(ledRedPin, OUTPUT);
    pinMode(ledPowerPin, OUTPUT);    
    digitalWrite(ledGreenPin, HIGH);
    digitalWrite(ledRedPin, HIGH);
    pinMode(speakerPin, OUTPUT);
    pinMode(powerOffPin, OUTPUT);
    myservoR.attach(9);  // attaches the servo on pin 9 to the servo object 
    myservoL.attach(10);  // attaches the servo on pin 10 to the servo object 
    myservoR.write(sRclosed); //closes the servo
    myservoL.write(sLclosed); //closes the servo
} 
///////////////////////////// end void setup 
 
 
void loop() { 
//turn on power chin LED and green LED  
     digitalWrite(ledGreenPin, HIGH);
     digitalWrite(ledRedPin, LOW);
     digitalWrite(ledPowerPin, HIGH);

delay(1000);

//OPEN UP Right
  for(posR = sRclosed; posR >= sRopened; posR -= 1)  // goes from closed to opened 
  {                                  // in steps of 1 degree 
    myservoR.write(posR);              // tell servo to go to position in variable 'pos' 
    
    delay(openDelay);                       // waits 15ms for the servo to reach the position 
  }
      
   delay(1500);   //wait a moment
      
      digitalWrite(ledGreenPin, LOW);
      digitalWrite(ledRedPin, HIGH);
      
      
//OPEN UP Left
  for(posL = sLclosed; posL <= sLopened; posL += 1)  // goes from closed to open 
  {                                  // in steps of 1 degree 
    myservoL.write(posL);              // tell servo to go to position in variable 'pos' 
    
    delay(openDelay);                       // waits 15ms for the servo to reach the position 
  }
  
  delay(1500); //wait a moment
  
     digitalWrite(ledGreenPin, HIGH);
     digitalWrite(ledRedPin, HIGH);
  
  //PLAY MUSIC
  march();
  
 //CLOSE UP Right
     digitalWrite(ledGreenPin, HIGH);
     digitalWrite(ledRedPin, LOW);
 
  for(posR = sRopened; posR <= sRclosed; posR+=1)     // goes from opened to closed 
  {                                
    myservoR.write(posR);              // tell servo to go to position in variable 'pos' 
    
    delay(closeDelay);                       // waits 15ms for the servo to reach the position 
  } 
   delay(1500); //wait a moment
     
     digitalWrite(ledGreenPin, LOW);
     digitalWrite(ledRedPin, HIGH);
 //Close Up Left
  for(posL = sLopened; posL >= sLclosed; posL-=1)     // goes from opened to closed 
  {                                
    myservoL.write(posL);              // tell servo to go to position in variable 'pos' 
    
    delay(closeDelay);                       // waits 15ms for the servo to reach the position 
  }  
  
      digitalWrite(ledGreenPin, LOW);
      digitalWrite(ledRedPin, LOW);
  
  delay(1500);
  
  //turn off the Arduino
  digitalWrite(powerOffPin, HIGH);
} 
//////////////////////////////END void loop


void beep (unsigned char speakerPin, int frequencyInHertz, long timeInMilliseconds)
{ 

    
    int x;     
    long delayAmount = (long)(1000000/frequencyInHertz);
    long loopTime = (long)((timeInMilliseconds*1000)/(delayAmount*2));
    for (x=0;x<loopTime;x++)     
    {     
        digitalWrite(speakerPin,HIGH);
        delayMicroseconds(delayAmount);
        digitalWrite(speakerPin,LOW);
        delayMicroseconds(delayAmount);
    }  
      //delay to separate notes
    delay(20);
} 
/////////////////////////////END void beep


void march()
{     
    //Sheet music http://www.musicnotes.com/sheetmusic/mtd.asp?ppn=MN0016254
    //time in ms
    //500 ms for a quart note
    beep(speakerPin, a, 500); 
    beep(speakerPin, a, 500);     
    beep(speakerPin, a, 500); 
    beep(speakerPin, f, 350); 
    beep(speakerPin, cH, 150);
    
    beep(speakerPin, a, 500);
    beep(speakerPin, f, 350);
    beep(speakerPin, cH, 150);
    beep(speakerPin, a, 1000);
    
    beep(speakerPin, eH, 500);
    beep(speakerPin, eH, 500);
    beep(speakerPin, eH, 500);    
    beep(speakerPin, fH, 350); 
    beep(speakerPin, cH, 150);
    
    beep(speakerPin, gS, 500);
    beep(speakerPin, f, 350);
    beep(speakerPin, cH, 150);
    beep(speakerPin, a, 1000);
    /* uncomment if you would like the whole song
    beep(speakerPin, aH, 500);
    beep(speakerPin, a, 350); 
    beep(speakerPin, a, 150);
    beep(speakerPin, aH, 500);
    beep(speakerPin, gSH, 250); 
    beep(speakerPin, gH, 250);
    
    beep(speakerPin, fSH, 125);
    beep(speakerPin, fH, 125);    
    beep(speakerPin, fSH, 250);
    delay(250);
    beep(speakerPin, aS, 250);    
    beep(speakerPin, dSH, 500);  
    beep(speakerPin, dH, 250);  
    beep(speakerPin, cSH, 250);
    
    beep(speakerPin, cH, 125);  
    beep(speakerPin, b, 125);  
    beep(speakerPin, cH, 250);      
    delay(250);
    beep(speakerPin, f, 125);  
    beep(speakerPin, gS, 500);  
    beep(speakerPin, f, 375);  
    beep(speakerPin, a, 125); 
    
    beep(speakerPin, cH, 500); 
    beep(speakerPin, a, 375);  
    beep(speakerPin, cH, 125); 
    beep(speakerPin, eH, 1000);
    
    beep(speakerPin, aH, 500);
    beep(speakerPin, a, 350); 
    beep(speakerPin, a, 150);
    beep(speakerPin, aH, 500);
    beep(speakerPin, gSH, 250); 
    beep(speakerPin, gH, 250);
    
    beep(speakerPin, fSH, 125);
    beep(speakerPin, fH, 125);    
    beep(speakerPin, fSH, 250);
    delay(250);
    beep(speakerPin, aS, 250);    
    beep(speakerPin, dSH, 500);  
    beep(speakerPin, dH, 250);  
    beep(speakerPin, cSH, 250);
    
    beep(speakerPin, cH, 125);  
    beep(speakerPin, b, 125);  
    beep(speakerPin, cH, 250);      
    delay(250);
    beep(speakerPin, f, 250);  
    beep(speakerPin, gS, 500);  
    beep(speakerPin, f, 375);  
    beep(speakerPin, cH, 125); 
           
    beep(speakerPin, a, 500);            
    beep(speakerPin, f, 375);            
    beep(speakerPin, c, 125);            
    beep(speakerPin, a, 1000); 
 */   
}
/////////////////////////////END void march    
    
    
 
