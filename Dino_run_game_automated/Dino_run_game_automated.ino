//A servo motor is generally used in Robotic to rotate a mechanical arm.
//It consists of a motor and a potentiometer connected via a feedback system.
//The angle that the arm should be at is stored which is continuously checked against the motor angle.
//This is done by the use of a potentiometer.
//As the motor rotates, the pot rotates leading to a change in output voltage from the pot.
//This value is compared with already stored values of voltage(corresponding to different angles) and feedback is applied.
//
//The value which should be compared with is given by the programmer.
//Usually a current with a pulsewidth of 1ms =      0 degrees
//                                       1.5ms =   90 degrees
//                                       2ms =     180 degrees
// Total time period is usually 20ms.
// The current is given to a digital pwm pin.  I think it can be given to a normal digital pin also.
// Special functions are there like servo.write which converts angles to current and sends this to the digital pin

#include <Servo.h>             //Servo library
 
Servo servo_test;        //initialize a servo object for the connected servo  
                
int angle = 45;

int ldr_in = 14; //A0 pin no for ldr input    
int servo_motor_out = 9;

 
void setup() 
{ 
  Serial.begin(9600);
  pinMode(A0, INPUT); 
  servo_test.attach(servo_motor_out);      // attach the signal pin of servo to pin9 of arduino

} 

void jump(){
  servo_test.write(150       );   
  delay(200);
  servo_test.write(45);
  delay(200);
  
}
  
void loop() 
{ 
  Serial.println(analogRead(ldr_in));
  if(analogRead(ldr_in) < 333 && analogRead(ldr_in) > 320 ){
    jump();
  }
  else if(analogRead(ldr_in) < 342 && analogRead(ldr_in) >= 333 ){
    
  }
}
