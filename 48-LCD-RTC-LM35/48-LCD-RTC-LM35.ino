#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#include <virtuabotixRTC.h>
int CLK_PIN = 6;//6. pini clock pini olarak tanımladık
int DAT_PIN = 7;//7. pini data pini olarak tanımladık
int RST_PIN = 8;//8. pini reset pini olarak tanımladık.
virtuabotixRTC myRTC(CLK_PIN, DAT_PIN, RST_PIN);// Kütüphanemizi pinlere atıyoruz

float sicaklik; //Analog değeri dönüştüreceğimiz sıcaklık 
float olculendeger; //Ölçeceğimiz analog değer
int sicaklikpin=1;  //Analog değer girişi

void setup() {
  lcd.begin(16, 2);
  // Set the current date, and time in the following format:
  // seconds, minutes, hours, day of the week, day of the month, month, year
  //myRTC.setDS1302Time(00, 59, 23, 6, 10, 1, 2014);//bu örneğe bakarak yap
  myRTC.setDS1302Time(00, 20, 00, 3, 17, 9, 2020);
  //zamanı bir kere set edip bir daha set etmemek gerekiyor.
}

void loop() {
  
  myRTC.updateTime();//RTC'den zamanı okuyoruz
  lcd.print(myRTC.dayofmonth);lcd.print("/");lcd.print(myRTC.month);lcd.print("/");lcd.print(myRTC.year);
  lcd.setCursor(0, 1);
  lcd.print(myRTC.hours);lcd.print(":");lcd.print(myRTC.minutes);lcd.print(":");lcd.print(myRTC.seconds);

  olculendeger = analogRead(sicaklikpin); //A1'den değeri alacak
  olculendeger = (olculendeger/1023)*5000;//değeri mV'a dönüştürecek 
  sicaklik = olculendeger /10,0; // mV'u sicakliğa dönüştürecek
  lcd.print(" Isi:");lcd.print(sicaklik);
  
  delay(1000);//1 saniye bekleme.
  lcd.clear();
}
