#include <MPU6050.h>
#include <Wire.h>
MPU6050 MPU;
int GyroX , GyroY , GyroZ;
int buzzer = 10;
void setup() {
  pinMode(11,OUTPUT); 
  Serial.begin(9600);
  Wire.begin();
  MPU.initialize();
}
void loop() {
  MPU.getRotation(&GyroX, &GyroY, &GyroZ);
  if(GyroX< -1000 ||GyroX> 1000 || GyroY>1000 || GyroY< -1000 || GyroZ >1000 || GyroZ < -1000 ) {
  tone(buzzer,1000);
  digitalWrite(11,HIGH);
  delay(1000);
  digitalWrite(11,LOW);
  } else {
  noTone(buzzer);
  digitalWrite(11,LOW);
  }
}
