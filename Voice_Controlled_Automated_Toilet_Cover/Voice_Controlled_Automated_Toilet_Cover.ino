#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>             //Servo library


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "tyAyZQnflP3qdq-sUMKOX2ZWoAW9aCVz";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "D";
char pass[] = "danth2000";

 
Servo servo_test;        //initialize a servo object for the connected servo                  
int angle = 0;    
 

void setup()
{
  servo_test.attach(15);      // attach the signal pin of servo to D8 of nodemcu
  
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}
BLYNK_WRITE(V0){
  int data = param.asInt();  
  if (data == 1){
    for(angle = 90; angle <= 300; angle += 10)    // command to move from 0 degrees to 180 degrees 
      {                                  
        servo_test.write(angle);                 //command to rotate the servo to the specified angle        
        digitalWrite(2, ~digitalRead(2));
      }
  }
  else if(data == 0){
    for(angle = 300; angle >= 90; angle -= 10)    // command to move from 0 degrees to 180 degrees 
      {                                  
        servo_test.write(angle);                 //command to rotate the servo to the specified angle
      }
  }      
}


void loop()
{
  
  Blynk.run();
}
