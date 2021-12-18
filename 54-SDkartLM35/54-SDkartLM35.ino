#include <SPI.h>
#include <SD.h>

File dosya;
float derece;
#define CSpin 10
#define LM35Pin A0
int sayac = 1;
void setup() {
  Serial.begin(9600); // serial açılıyor
  if (!SD.begin(CSpin)) {// SD kart başlatılıyor
    Serial.println("SD Kart yok yada baglanti basarisiz.");
    return;
  }
  Serial.println("SD Kart baglandi.");
}


void loop() {
  derece = sicaklikOlc();
  dosya = SD.open("Log.txt", FILE_WRITE); // Dosya açılıyor. Yok ise yeni oluşturulur.
  if (SD.exists("Log.txt")) { // Dosya var mı? kontrolü.
    dosya.print(sayac); // dosyaya yazılıyor.
    dosya.print(". Dakika Sıcaklık Değeri : ");
    dosya.println(derece);
    dosya.close(); // dosyayı kapat.
    Serial.println("Sicaklik bilgisi kaydedildi.");
  }else{
    Serial.println("Dosya yok yada yazma başarisiz!");
  }
  sayac++; // sayacı bir arttırıyoruz.
  delay(6000); // 6 saniye bekle
}


float sicaklikOlc()
{
float temp;
temp = analogRead(LM35Pin);
temp = (5.0 * temp * 100.0)/1024.0;//lm35 sıcaklık hesaplama bölümü
return temp;
}
