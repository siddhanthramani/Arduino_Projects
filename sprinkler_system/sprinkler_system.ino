
// We use a HC-SR04 ultrasonic sensor for this project.
/*
When we send a pulse of width 10microseconds to the trigger pin, the sensor would send out 8 pulses at 40KHZ(ultrasonic as >20KHz).
At the same time, the echo pin goes high.
When the reflected wave is received, the echo pin goes low and thus the pulse width of the echo signal equals the time taken by the wave.

If no reflection occurs, the time returned is 38 ms (max range).

The math used for distance is speed (0.034cm/us) x (time/2)

CONNECT VIN to +5V (NOT +3V)


*/ 
#include <Servo.h>             //Servo library
 
Servo servo_test;        //initialize a servo object for the connected servo                  
int angle = 0;    

//pin 9 is used to connect servo motor(orange wire from servo)
const int gate=11; //for the humidity and temp sensor
const int triggerPin = 7;
const int echoPin = 6; 
const int ledPin = 5;

int led_value = 0;
long distance;

volatile unsigned long duration=0;
unsigned char i[5];
unsigned int j[40];
unsigned char value=0;
unsigned answer=0;
int z=0;

int ultrasonic_distance(){
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  int ultra_duration = pulseIn(echoPin, HIGH);
  //the pulseIn measures the time it takes for a signal to transition from HIGH to LOW(If the parameter is HIGH, vice-versa if param LOW)

 
  distance = (ultra_duration/2) * 0.034;

  if(distance > 40){
    distance = 40; //this is the maximuk distance of sprinkler water
  }
  
  Serial.print(" The distance is ");
  Serial.print(distance);
  Serial.println(" cm");

  //return distance; NO NEED to return as it distance is declared as a global variable
  
}


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo_test.attach(9);  
}

void loop() {
  // put your main code here, to run repeatedly:
   delay(1000);
 while(1)
 {
  delay(1000);
  pinMode(gate,OUTPUT);
  digitalWrite(gate,LOW);//we make it low for min of 18ms
  delay(20);
  digitalWrite(gate,HIGH);//we then make it high
  pinMode(gate,INPUT_PULLUP);//by default it will become high due to internal pull up
 // delayMicroseconds(40);

  
  duration=pulseIn(gate, LOW); //we measure the duration for which pin remains low before turning high
  if(duration >= 72 && duration <= 84)//should be >=54, dont know why this is different
  {
      while(1)
      {
        duration=pulseIn(gate, HIGH);//we measure for how long pin remains high before turning low
        
        if(duration >= 20 && duration <= 26){
        value=0;}//signifies bit 0
        
        else if(duration >= 65 && duration <= 74){
        value=1;}//signifies bit 1
        
        else if(z==40){
        break;}
        
        i[z/8] |= value << (7- (z%8)); // every time we go to the loop, we left shift the value by the no.of spaces and or it to get the final 8 bit number
        j[z] = value;//stores all 80 bits in an array
        z++;  
      }
    }
answer=i[0]+i[1]+i[2]+i[3];

if(answer==i[4] && answer!=0) //checks parity 
{
  while(1){
    if(i[0] >= 25 || i[2] >= 50){
      for(angle = 0; angle < 180; angle += 1)    // command to move from 0 degrees to 180 degrees 
      {                                  
        servo_test.write(angle);                 //command to rotate the servo to the specified angle
        delay(15);                       
        ultrasonic_distance();
        led_value = distance * 6.375; //because 40(max_distance) *6.375 is 255 (max_pwm_value) and we want output proportional to distance
        analogWrite(ledPin,led_value);
      } 
      digitalWrite(ledPin, LOW);// to ensure that while returning back to start position, no water is released
      delay(1000);
      for(angle = 180; angle>=1; angle-=5)     // command to move from 180 degrees to 0 degrees 
      {                                
        servo_test.write(angle);              //command to rotate the servo to the specified angle
        delay(5);                       
      } 
        delay(1000);       
    } 
  }
}

z=0;
i[0]=i[1]=i[2]=i[3]=i[4]=0;


  }
} 
  /////////////////////////////////
  
