#include <Wire.h>
#include <LiquidCrystal.h>
#include <dht.h> 
#define dht_dpin 2
dht DHT;   
const int SLAVE_ADDRESS = 1;
char buffer[255];

volatile int temp;
volatile int hum;

void setup(){
pinMode(13, OUTPUT);
Serial.begin(9600);
Serial.println("Humidity and temperature\n");  
digitalWrite(4, HIGH);
digitalWrite(7, LOW);

Wire.begin(SLAVE_ADDRESS); // join I2C bus as a slave with addres
Wire.onRequest(requestEvent); // register event
}

void loop() { 
DHT.read11(dht_dpin); //讀取DHT-11

delay(500);            //每500ms更新一次   
temp = (int) DHT.temperature;
hum = (int) DHT.humidity;
Serial.print(temp);  
Serial.print("  ");
Serial.print(hum); 
Serial.print("\n");
}
void requestEvent() {
//digitalWrite(13,HIGH);

sprintf(buffer,"%d-%d", temp, hum);//將溫濕度讀值輸出

Wire.write(buffer); //將溫濕度讀值輸出
}

