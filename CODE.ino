
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2,4); // RX, TX 

int led1 = 6;
int led2 = 5;
int led3=7;

String state;

void setup() {

pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3,OUTPUT);
Serial.begin(9600);
mySerial.begin(38400);

}

void loop() 
{

 while (mySerial.available())
 {  
 delay(10);  
 char c = mySerial.read(); //Conduct a serial read
 state += c; //Shorthand for voice = voice + c
 Serial.println(state);
 } 

if (state.equals("LED on"))
{
digitalWrite(led1, HIGH);
Serial.println("LED On");
}

// if the state is 'LED1OFF' the led1 will turn off
else  if (state.equals("LED off")){
digitalWrite(led1, LOW); 
Serial.println("LED Of");
}

// if the state is 'LED2ON' the Led2 will turn on
else  if (state.equals("fan on")){
digitalWrite(led2, HIGH);
Serial.println("fan On");
} 

// if the state is 'LED2OFF' the led2 will turn off
else  if (state.equals("fan of")){
digitalWrite(led2, LOW);
Serial.println("fan Off");
}
//if the state is 'light on then led on
else if(state.equals("light on")){
digitalWrite(led3,HIGH);
Serial.println("light on"); 
}
else if(state.equals("light off")){
  digitalWrite(led3,LOW);
  Serial.println("light off"); 
}

// if the state is 'ALLON' the Led's will turn on
else if (state.equals("all on")) {
digitalWrite(led1, HIGH);
digitalWrite(led2, HIGH);
digitalWrite(led3,HIGH);
Serial.println("All On");
}

// if the state is 'ALLOFF' the Led's will turn off
else if (state.equals("all off")) {
digitalWrite(led1, LOW);
digitalWrite(led2, LOW);
digitalWrite(led3,LOW);
Serial.println("All Off");
}

state="";
}
