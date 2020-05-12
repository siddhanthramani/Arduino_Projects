
const int echoPin  = 
const int triggerPin = 

const int pin1 = 
const int pin2 = 
const int pin3 = 

void setup() {
  // put your setup code here, to run once:
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);

  digitalWrite(triggerPin, LOW);
  
}

void deviceOn(pinout){
  pinMode(pinout,HIGH);
}
void deviceOff(pinout){
  pinMode(pinout,LOW);
}

void loop() {

    digitalWrite(triggrPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    duration = pulseIn(HIGH);
    distance_in_cm = (duration / 2) * 0.034;

    if(distance_in_cm < threshold_for_1){
      if(device1 == 1){
        deviceOff(pin1)  
        device1 ^= 1;
      }
      else{
        deviceOn(pin1)  
        device1 ^= 1;
      }
                     
    }
    else if ( threshold_for_1 < distance_in_cm < threshold_for_2){
      if(device2 == 1){
        deviceOff(pin2)
        device2 ^= 1;  
      }
      else{
        deviceOn(pin2)  
        device2 ^= 1;
      }
    }
    else if ( threshold_for_2 < distance_in_cm < threshold_for_3){
      if(device3 == 1){
        deviceOff(pin3)
        device3 ^= 1;  
      }
      else{
        deviceOn(pin3)  
        device3 ^= 1;
      }
    }
  
  
}
