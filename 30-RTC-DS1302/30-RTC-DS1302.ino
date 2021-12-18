#include <virtuabotixRTC.h>

int CLK_PIN = 6;//6. pini clock pini olarak tanımladık
int DAT_PIN = 7;//7. pini data pini olarak tanımladık
int RST_PIN = 8;//8. pini reset pini olarak tanımladık.
virtuabotixRTC myRTC(CLK_PIN, DAT_PIN, RST_PIN);// Kütüphanemizi pinlere atıyoruz

void setup() {
  Serial.begin(9600);
  // Set the current date, and time in the following format:
  // seconds, minutes, hours, day of the week, day of the month, month, year
  //myRTC.setDS1302Time(00, 59, 23, 6, 10, 1, 2014);//bu örneğe bakarak yap
  myRTC.setDS1302Time(00, 35, 8, 1, 8, 9, 2020);
  //zamanı bir kere set edip bir daha set etmemek gerekiyor.
}

void loop() {
  
  myRTC.updateTime();//RTC'den zamanı okuyoruz
  Serial.print(myRTC.dayofmonth);//Günü ekrana bastırıyoruz.
  Serial.print("/");
  Serial.print(myRTC.month);//Ayı ekrana bastırıyoruz.
  Serial.print("/");
  Serial.print(myRTC.year);//Yılı ekrana bastırıyoruz
  Serial.print(" - ");
  Serial.print(myRTC.hours);//Saati ekrana bastırıyoruz.
  Serial.print(":");
  Serial.print(myRTC.minutes);//Dakikayi ekrana bastırıyoruz.   
  Serial.print(":");
  Serial.println(myRTC.seconds);//Saniyeyi ekrana bastırıyoruz.
  delay(1000);//1 saniye bekleme.
}
