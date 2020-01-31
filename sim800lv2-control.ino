#include <WiFi.h>

// SIM800L Modem Pins
#define MODEM_RST       5

char c = ' ';

void setup() 
{
  // start th serial communication with the host computer
  Serial.begin(115200);
  while(!Serial);
  Serial.println("Arduino with SIM800L is ready");

  // start communication with the SIM800L in 9600
  // Set modem reset
  pinMode(MODEM_RST, OUTPUT);
  digitalWrite(MODEM_RST, HIGH);
  
  Serial2.begin(38400);  
  Serial.println("SIM800L started at 9600");
  delay(1000);
  Serial.println("Setup Complete! SIM800L is Ready!");
}
 
void loop()
{
  // Keep reading from SIM800 and send to Arduino Serial Monitor
  if (Serial2.available()) {
    c = Serial2.read();
    Serial.write(c);
  }
  
  // Keep reading from Arduino Serial Monitor and send to SIM800L
  if (Serial.available()){
    c = Serial.read();
    Serial2.write(c);  
  }
}
