#include <dht.h>   
#define dht_dpin 2 //定義訊號要從Pin進來  
#include <LiquidCrystal.h>
#include <Wire.h>
const int SLAVE_ADDRESS = 1;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
dht DHT;  
char incomingByte = 0;
  
void setup(){ 
Wire.begin(); 
lcd.begin(20, 2); 
Serial.begin(9600);  //Let system settle   
delay(300);           
}
  
void loop(){
Wire.requestFrom(SLAVE_ADDRESS, 255);

//DHT.read11(dht_dpin);   //去library裡面找DHT.read11  
//Serial.print("Humidity = ");   
//Serial.print(DHT.humidity);  
//Serial.print("% ");   
//Serial.print("temperature = ");   
//Serial.print(DHT.temperature);   
//Serial.println("C ");

while (Wire.available()) {
  incomingByte = Wire.read(); // receive a byte
  lcd.print(incomingByte);  // Display at LCD 
}
delay(500);
lcd.clear();
}  
