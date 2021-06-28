#include "DHT.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27 ,2,1,0,4,5,6,7,3, POSITIVE);
#define DHTPIN 2
#define DHTTYPE 22
const int Relay=7;
DHT dht(DHTPIN,DHTTYPE);
void setup()
{
  pinMode(Relay,OUTPUT);
  Serial.begin(9600);
   lcd.begin (16,2);
  dht.begin();
}
void loop()
{
  float t=dht.readTemperature();
  float h=dht.readHumidity();

  Serial.print("Temp: ");
  Serial.println(t);
  Serial.print("Hum: ");
  Serial.println(h);
  delay(1000);
  lcd.setCursor(0, 0); //baris pertama   
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print("C");    
  lcd.setCursor(0, 1); //baris kedua   
  lcd.print("Hum: ");
  lcd.print(h);
  lcd.print("%");
  if(t>=35)
  {
    digitalWrite(Relay,LOW);
    Serial.print("WARM");
    delay(1000);
  }
  else if(t<35)
  {
    digitalWrite(Relay,HIGH);
    Serial.print("HOT");
    delay(1000);
  }
  
}
