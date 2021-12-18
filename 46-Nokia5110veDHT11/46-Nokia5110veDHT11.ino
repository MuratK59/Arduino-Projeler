#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

// Declare LCD object for software SPI
// Adafruit_PCD8544(CLK,DIN,D/C,CE,RST);
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

#include <dht11.h> // dht11 kütüphanesini ekliyoruz.
#define DHT11PIN 9 // DHT11PIN olarak Dijital 6"yi belirliyoruz.
dht11 DHT11;

void setup()
{
  Serial.begin(9600); // Seri iletişimi başlatıyoruz.

  //Initialize Display
  display.begin();

  // you can change the contrast around to adapt the display for the best viewing!
  display.setContrast(57);
}

void loop()
{
  // Display Text
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("Sicaklik:");
  display.setCursor(55,0);
  display.println((float)DHT11.temperature, 1);
  display.println("Nem(%):");
  display.setCursor(55,8);
  display.println((float)DHT11.humidity, 1);

  display.setTextSize(2);
  display.setTextColor(BLACK);
  display.println((float)DHT11.temperature, 1);
  display.setCursor(50,15);
  display.println(" C");
  display.println((float)DHT11.humidity, 1);
  display.setCursor(50,29);
  display.println(" %");
  
  display.display();
  delay(2000);
  display.clearDisplay();
  
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
  
  // 2 saniye bekliyoruz. 2 saniyede bir veriler ekrana yazdırılacak.
  //delay(2000);
}
