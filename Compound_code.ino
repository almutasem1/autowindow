#include<Servo.h>

#include <dht.h>

dht DHT;

#define DHT11_PIN 7
Servo servo1;
void setup() {
  // put your setup code here, to run once:
 servo1.attach(9);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  delay(1000);
  
  if(DHT.temperature>20.00)
  servo1.write(0);

  else if(DHT.temperature<20.00&&DHT.temperature>-20.00)
   servo1.write(180);
  
}
