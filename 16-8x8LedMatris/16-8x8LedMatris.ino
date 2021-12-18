//maker.robotistan.com 
#include <LedControl.h> //Kütüphanemizi dahil edelim 

//Pin numaralarını tanımlıyoruz 
#define CLK 5 
#define CS 6 
#define DIN 7 
#define MaxSayisi 1  //Bağlı olan dot matrix sayısı 

const long delay_suresi = 750; //Kodda kullanacağımız delay süresi 

LedControl led = LedControl(DIN, CLK, CS, MaxSayisi); 

//Kullanacağımız ifadeler için byte tipinde bir dizi tanımlıyoruz
byte images[][8] =
 {{
     0,          //kalp
     B01100110,
     B11111111,
     B11111111,
     B01111110,
     B00111100,
     B00011000
   },
   {
     B00111100,  //uzgun ifade
     B01000010,
     B10100101,
     B10000001,
     B10011001,
     B10100101,
     B01000010,
     B00111100
   },
   {
     B00111100,  //normal ifade
     B01000010,
     B10100101,
     B10000001,
     B10111101,
     B10000001,
     B01000010,
     B00111100
   },
   {
     B00111100,  //gulen ifade
     B01000010,
     B10100101,
     B10000001,
     B10100101,
     B10011001,
     B01000010,
     B00111100
   },
   {
      B00011000,//İ
      B00011000,
      B00000000,
      B00011000,
      B00011000,
      B00011000,
      B00011000,
      B00011000
    },
    {
      B11111100,//P
      B11001100,
      B11001100,
      B11111100,
      B11111100,
      B11000000,
      B11000000,
      B11000000
    },
    {
      B11111100,//E
      B11111100,
      B11000000,
      B11111100,
      B11111100,
      B11000000,
      B11111100,
      B11111100
    },
    {
      B11000110,//K
      B11001100,
      B11011000,
      B11110000,
      B11110000,
      B11011000,
      B11001100,
      B11000110
    }
 };
 void MatrixeYazdir(byte* ch)
 {
   for (int i = 0; i < 8; i++)
   {
     led.setRow(0, i, ch[i]);
   }
 }
 void setup()
 {
   led.setIntensity(0, 5);  //Parlaklık ayarı
   led.shutdown(0, false);   //Led matrixi aktif hale getirme
   led.clearDisplay(0);
 }
 void loop()
 {
 for (int j = 0; j < 8; j++)  //Tüm şekilleri yazdırma
   {
     MatrixeYazdir(images[j]);
     delay(delay_suresi);
   }
 for (int i = 0; i < 15; i++) //Azdan çoğa parlaklık
   {
     led.setIntensity(0, i);
     delay(100);
   }
 }
