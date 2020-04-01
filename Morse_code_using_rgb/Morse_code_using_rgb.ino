// morse code converter and display


#include<String.h>

String morseEncode(char x);
int r, g, b;  
const int red_led = 9;
#define green_led 10
#define blue_led  11 

int unit_time = 500;


String sentence = ""; //gets input from user
String mcode = ""; //gets the mcode from the function morseEncode

String morseEncode(char x);
void morseCode(String s);

void setup() {
  // put your setup code here, to run once:
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(blue_led, OUTPUT);
  Serial.begin(9600);
  digitalWrite(red_led, HIGH);
  digitalWrite(green_led, HIGH);
  digitalWrite(blue_led, HIGH);
  
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available()==0)  
  {                                       //Wait for user input  
    
  }  
  sentence = Serial.readString();  //Reading the Input string from Serial port.
  Serial.println(sentence);
  String sent = sentence;
  morseCode(sent);  
}

String morseEncode(char x) {

  switch (x) { 
  case 'a': 
    return ".-"; 
  case 'b': 
    return "-..."; 
  case 'c': 
    return "-.-."; 
  case 'd': 
    return "-.."; 
  case 'e': 
    return "."; 
  case 'f': 
    return "..-."; 
  case 'g': 
    return "--."; 
  case 'h': 
    return "...."; 
  case 'i': 
    return ".."; 
  case 'j': 
    return ".---"; 
  case 'k': 
    return "-.-"; 
  case 'l': 
    return ".-.."; 
  case 'm': 
    return "--"; 
  case 'n': 
    return "-."; 
  case 'o': 
    return "---"; 
  case 'p': 
    return ".--."; 
  case 'q': 
    return "--.-"; 
  case 'r': 
    return ".-."; 
  case 's': 
    return "..."; 
  case 't': 
    return "-"; 
  case 'u': 
    return "..-"; 
  case 'v': 
    return "...-"; 
  case 'w': 
    return ".--"; 
  case 'x': 
    return "-..-"; 
  case 'y': 
    return "-.--"; 
  case 'z': 
    return "--.."; 
  } 
} 
//////////////////////////////////////////////////////////


void morseCode(String s) { 
  
  // character by character print  
  // Morse code 
  for (int i = 0; i < s.length(); i++){
    Serial.print("i = ");
    Serial.println(i);
    if(s[i] == ' '){   // can not use " " (doule quotes ) to check for space   
      
      delay(7 * unit_time);// for the duration between words
      
    }
    else if (s[i] != " ") {
      
      randomSeed(analogRead(5));
      r = random(0,255);
      randomSeed(analogRead(5));
      g = random(0,255);
      randomSeed(analogRead(5));
      b = random(0,255);
      
      delay(3 * unit_time); // for the letter duration 
      
      mcode = morseEncode(s[i]);//gets the morse code from the function morseEncoder
      Serial.print("mcode = ");
      Serial.println(mcode);
      
      //
      for(int j = 0; j < mcode.length(); j++){
          
    
        Serial.println(mcode[j]);
        if(mcode[j] == '.'){
          
        
          analogWrite(red_led, r);
          analogWrite(green_led, g);
          analogWrite(blue_led, b);
          delay(unit_time);
          digitalWrite(red_led, HIGH);
          digitalWrite(green_led, HIGH);
          digitalWrite(blue_led, HIGH);       
          delay(unit_time); //for the character duration
        }
        else if(mcode[j] == '-'){
          analogWrite(red_led, r);
          analogWrite(green_led, g);
          analogWrite(blue_led, b);
          delay(unit_time);
          digitalWrite(red_led, HIGH);
          digitalWrite(green_led, HIGH);
          digitalWrite(blue_led, HIGH);       
          delay(unit_time); //for the character duration
        }  
      } 
        
    }//the else(only happens for non blank characters in the sentence)
      
  } //the sentence loop
}// the function bracket 
