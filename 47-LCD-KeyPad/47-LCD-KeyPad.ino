/*KeyPad üzerinden şifre girilecektir. 
'*' karakteri şifreyi onaylar. Şifre ise "1A7C"
arduino uno üzerinde ki giriş pin sayısı yetersiz olduğundan 0 ve 1 numaralı 
seri haberleşme pinlerini de kullandım bundan dolayı "4,5,6,B" satırı çalışmadı.*/
#include <Keypad.h>  // keypad kütüphanesini programa dahil ediyoruz.
const byte Satir= 4;  // keypad satır sayısı
const byte Sutun= 4;  // keypad sütün sayısı
String Sifre;     // girilen şifre 

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

 
// Keypad tuş yapısını hazırlıyoruz.
char key[Satir][Sutun]= 
{
{'1', '2', '3', 'A'}, 
{'4', '5', '6', 'B'}, 
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};
 
// Arduino bağlantı bacaklarını belirliyoruz
byte SatirPinleri[Satir] = {0,1,6,7}; 
byte SutunPinleri[Sutun]= {8,9,10,13}; 
 
// Keypade TusTakimi ismini verip arduino bağlantılarını ve karakterleri 
// bu TusTakimi keypad nesnesine tanımlıyoruz.
Keypad TusTakimi= Keypad(makeKeymap(key), SatirPinleri, SutunPinleri, Satir, Sutun);
 
void setup()
{
  lcd.begin(16, 2);
  lcd.print("Sifreyi Giriniz");
}
 
void loop()
{
  lcd.cursor();
  delay(150);
  char basilanTus = TusTakimi.getKey();  // Keyped basılan tuş değerini alıyoruz.
  if (basilanTus != NO_KEY && basilanTus != '*') {
    Sifre = Sifre + basilanTus;
    lcd.clear();
    lcd.print("Sifreyi Giriniz");
    lcd.setCursor(2, 1);
    lcd.print(Sifre);
  }
  if(basilanTus == '*'){
    lcd.clear();
    if(Sifre == "1A7C"){
      lcd.print("Gecerli Sifre!!!"); 
    }else{
      lcd.print("Yanlis Sifre!!!"); 
    }
    Sifre="";
    delay(2000);
    lcd.clear();
    lcd.print("Sifreyi Giriniz");
  }
  lcd.noCursor();
  delay(150);

}
