# Robotik-dersi
Deprem Alarmı
Ad:Batıkan Ege Sayın
Sınıf:10/B
Numara:2600

Amacı:
Son zamanlarda çok fazla deprem olduğu için bu projede insanları herhangi bir sarsıntıda ses ve ışık çıkararak insanları uyarmasını sağlıyor.

Kullanılan Malzemeler:
Jumper Kablo
Arduino Uno
Buzzer
Led
Mpu6050
Direnç
Breadboard

Devrenin Kodları:
#include <MPU6050.h> //Mpu6050 Kütüphanesi
#include <Wire.h> // wire.h Kütüphanesi
MPU6050 MPU;
int GyroX , GyroY , GyroZ; //İnt değer olduğunu gösteriyoruz
int buzzer = 10; // buzzer a 10 sayısında bir int değer atıyoruz
void setup() {
  pinMode(11,OUTPUT);  //11 e çıkış pinini giriyoruz
  Serial.begin(9600);
  Wire.begin();
  MPU.initialize();
}
void loop() {
  MPU.getRotation(&GyroX, &GyroY, &GyroZ); 
  if(GyroX< -1000 ||GyroX> 1000 || GyroY>1000 || GyroY< -1000 || GyroZ >1000 || GyroZ < -1000 ) {  //eğer verdiğimiz rotasyonlardan bir sarsıntı algılarsa
  tone(buzzer,1000); // buzzer a ses veriyoruz
  digitalWrite(11,HIGH); // 11 e yüksek değerini veriyoruz
  delay(1000); // 1 saniye arayla 
  digitalWrite(11,LOW); //11 e düşük değerini veriyoruz
  } else { //değilse
  noTone(buzzer); // buzzer a ses vermiyoruz
  digitalWrite(11,LOW); // 11 e düşük pinini veriyoruz
  }
}



Devrenin Şeması:
[https://wokwi.com/projects/new/arduino-uno](https://wokwi.com/projects/366981500045211649)

Projenin Sunumları:
Word:[ROBOTİK VE KODLAMA.docx](https://github.com/BatikanEge/Robotik-dersi/files/11690855/ROBOTIK.VE.KODLAMA.docx)


PowerPoint:[ROBOTİK VE KODLAMA.pptx](https://github.com/BatikanEge/Robotik-dersi/files/11690851/ROBOTIK.VE.KODLAMA.pptx)

Kaynak:https://maker.robotistan.com/deprem-alarmi-yapimi/
