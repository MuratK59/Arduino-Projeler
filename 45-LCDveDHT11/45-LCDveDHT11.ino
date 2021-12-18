#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#include <dht11.h> // dht11 kütüphanesini ekliyoruz.
#define DHT11PIN 6 // DHT11PIN olarak Dijital 6"yi belirliyoruz.

dht11 DHT11;

void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600); // Seri iletişimi başlatıyoruz.
  Serial.println("Arduinoturkiye.com DHT11 Test Programi");
}

void loop()
{
  // Bir satır boşluk bırakıyoruz serial monitörde.
  Serial.println();
  // Sensörün okunup okunmadığını konrol ediyoruz. 
  // chk 0 ise sorunsuz okunuyor demektir. Sorun yaşarsanız
  // chk değerini serial monitörde yazdırıp kontrol edebilirsiniz.
  int chk = DHT11.read(DHT11PIN);

  // Sensörden gelen verileri serial monitörde yazdırıyoruz.
  Serial.print("Nem (%): ");
  Serial.println((float)DHT11.humidity, 2);

  Serial.print("Sicaklik (Celcius): ");
  Serial.println((float)DHT11.temperature, 2);

  Serial.print("Sicaklik (Fahrenheit): ");
  Serial.println(DHT11.fahrenheit(), 2);

  Serial.print("Sicaklik (Kelvin): ");
  Serial.println(DHT11.kelvin(), 2);

  // Çiğ Oluşma Noktası, Dew Point
  Serial.print("Cig Olusma Noktasi: ");
  Serial.println(DHT11.dewPoint(), 2);
  
  lcd.print("Sicaklik(C):");
  lcd.print((float)DHT11.temperature, 2);
  lcd.setCursor(0, 2);
  lcd.print("Nem (%): ");
  lcd.print((float)DHT11.humidity, 2);
  // 2 saniye bekliyoruz. 2 saniyede bir veriler ekrana yazdırılacak.
  delay(2000);
  lcd.clear();
}
