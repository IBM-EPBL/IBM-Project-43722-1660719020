#include <LiquidCrystal.h>
LiquidCrystal 
 lcd(5,6,8,9,10,11); 
 int redled = 2; 
int yellowled = 3;
int buzzer = 4; 
int sensor = A0;
int sensorThresh = 400; 
 void setup()
 {
   pinMode(redled, OUTPUT);
   pinMode(yellowled,OUTPUT);
   pinMode(buzzer,OUTPUT); 
   pinMode(sensor,INPUT); 
   Serial.begin(9600); 
   lcd.begin(16,2); 
 }  
void loop()
{  
int analogValue = analogRead(sensor);
  Serial.print(analogValue);
  if(analogValue>sensorThresh){  
    digitalWrite(redled,HIGH); 
    digitalWrite(yellowled,LOW);
    tone(buzzer,1000,10000); 
    lcd.clear(); 
    lcd.setCursor(0,1); 
    lcd.print("ALERT");
    delay(1000);  
    lcd.clear(); 
    lcd.setCursor(0,1);
    lcd.print("EVACUATE");
    delay(1000); 
  }   
  else  
  {  
   digitalWrite(yellowled,HIGH);
    digitalWrite(redled,LOW); 
    noTone(buzzer);    
    lcd.clear();    
    lcd.setCursor(0,0);  
    lcd.print("SAFE");   
    delay(1000); 
    lcd.clear();  
    lcd.setCursor(0,1);  
    lcd.print("ALL CLEAR");  
    delay(1000);} 
 } 
