 const int buzzer = 8;
const int trig = 7;
const int echo = 6;

void get_threshold();
int send_ultrasonic();


int threshold_value ,value ;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(trig, LOW);
  
  get_threshold();
  
}


void get_threshold(){
  int i_max = 10;
  int max_variation = 2;
  int count_threshold = 0;  
  int value = 0; 
  
  for(int i = 0; i <= i_max; i++){
    if(i == 0){
      value = send_ultrasonic();
    }
    
    if(send_ultrasonic()  > value-3    && send_ultrasonic()  < value+3 ){
      count_threshold ++;
    }
    else{
      
    }
    if(i == i_max ){
      if(count_threshold > i_max-max_variation){       
        threshold_value = value;  
        Serial.print("Threshold is  ");
        Serial.println(threshold_value);
             
      }      
      else{
        i = 0;
      }      
    }

    delay(20);
  }
}

int send_ultrasonic(){
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  int distance;
  int duration = pulseIn(echo, HIGH);
  return distance = (duration / 2) * 0.034;
}


void loop() {
  int current_distance = send_ultrasonic();
  Serial.print("current distance is ");
  Serial.println(current_distance);
  
  if(current_distance < (threshold_value - 100)){
    //Serial.println("Inside the threshold loop");
    unsigned long start_time = millis(); // VERY IMPORTANT, millis should always be of type unsigned long, otherwise logic errors might occur
    while(1){
      digitalWrite(buzzer, HIGH);
      delay(2);//wait for 2ms        
      digitalWrite(buzzer,LOW);
      delay(2);//wait for 2ms         
      if(millis() > (start_time + 10000)){
        break;
      }
      
    }
    get_threshold();
      
  }
    
}
