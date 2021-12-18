/*
   Hazırlayan Levent TOPAKTAŞ
   Bu uygulamamız RGB led ile araç trafik ışığı
   kırmızı ve yeşil led ile de yaya trafik ışığı
   kontrol ettiğimiz bir çalışma
*/

// Önce led pinlerini tanımlayalım.
const byte kRgb = 13;
const byte mRgb = 12;
const byte yRgb = 10;
const byte kLed = 6;
const byte yLed = 3;

void setup() {
  pinMode(kRgb, OUTPUT);
  pinMode(mRgb, OUTPUT);
  pinMode(yRgb, OUTPUT);
  pinMode(kLed, OUTPUT);
  pinMode(yLed, OUTPUT);
  // mavi renge ihtiyacımız olmayacak
  digitalWrite(mRgb, 0);
}

void loop() {
/* Trafik ışığı için süre ayarlamamız gerekiyor.
 * Araçlara kırmızı 5sn, sarı 2 sn, yeşil 5sn yansın7.
 * Bu durumda yayalara da kırmızı 7 sn, yeşil 5sn kadar yanacak.*/
digitalWrite(kLed,HIGH); //Yaya kırmızı
digitalWrite(yRgb,HIGH); //Araç yeşil
digitalWrite(kRgb,LOW);
delay(5000);
digitalWrite(kRgb,HIGH); // Araç sarı
delay(2000);
digitalWrite(yRgb,LOW); //Araç kımızı
digitalWrite(kLed,LOW); // Yaya yeşil
digitalWrite(yLed,HIGH);
delay(5000);
digitalWrite(yLed,LOW); //Araç sarı
digitalWrite(kLed,HIGH); //Yaya kırmızı
digitalWrite(yRgb,HIGH);
digitalWrite(kRgb,HIGH);
delay(2000);
}