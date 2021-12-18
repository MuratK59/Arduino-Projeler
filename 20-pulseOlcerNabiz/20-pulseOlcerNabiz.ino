#define USE_ARDUINO_INTERRUPTS true   // En doğru ölçüm için Arduino Interruptlarının
                                      // kullanılmasını sağlar. Bu kütüphane için Arduino 
                                      // Interruptlarının kullanılması tavsiye ediliyor.

#include <PulseSensorPlayground.h>    // Kütüphaneyi ekler.

const int sensor = A0;        // Pulse (nabız) sensörünü bağladığımız pini belirler.
const int yananLED = 13;      // Nabız alındığında yanıp sönecek olan LED'in pinini belirler.
const int sonenLED = 5;       // Nabız alındığında yavaşça sönecek olan LED'in PWM pinini belirler.
const int esik = 520;         // Nabız alınmadığı zaman gürültüden kaynaklı yanlış
                              // ölçüm yapılmaması adına oluşturulan eşik değeri.


PulseSensorPlayground pulseSensor;    // Kütüphane fonksiyonlarını tanımlar.

void setup() {

  Serial.begin(9600);   // 9600 baud rate'de seri haberleşmeyi başlatır.

  pulseSensor.analogInput(sensor);      // Sensörü analog girişe (0'ıncı pin) bağlar.
  pulseSensor.blinkOnPulse(yananLED);   // Yanıp sönecek LED'in çalışma isterini gerçekleştiren kütüphane fonksiyonu.
  pulseSensor.fadeOnPulse(sonenLED);    // Sönecek LED'in çalışma isterini gerçekleştiren kütüphane fonksiyonu.
  pulseSensor.setThreshold(esik);       // Esiği tanımlayan kütüphane fonksiyonu.

  if (!pulseSensor.begin()) {     // Sensör sinyallerini okumaya başlar.
    for(;;) {     // Olası bir hata durumunda 13'üncü pindeki LED'i yanıp söndürür.
                  // Hata nedeni interrupt kaynaklıdır. Bu hatayı alıyorsanız baştaki
                  // Interrupt kodunu silip deneyin.
      digitalWrite(yananLED, LOW);
      delay(30);
      digitalWrite(yananLED, HIGH);
      delay(30);
    }
  }
}

void loop() {
  int nabiz = pulseSensor.getBeatsPerMinute();  // Sensörden okunan nabız verisini integer değerine çevirecek fonksiyon.

  if (pulseSensor.sawStartOfBeat()) {            // Sensörden gelen nabız verisi varsa çalışacak koşul. 
 
  Serial.print("Nabziniz: ");                   // Ölçülen nabzı ekrana yansıtır. 
  Serial.println(nabiz);
  }
  delay(5000);
}
