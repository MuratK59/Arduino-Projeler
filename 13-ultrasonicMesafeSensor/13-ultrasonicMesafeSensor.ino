/* Önemli Not : Mesafe sensörünü bağlarken önce GND sonra VCC
 * bağlantısını yapınız. Bazı modüller gnd öncesi elektriksel
 * bağlantı sebebi ile kolay bozulabilmektedir. */

const int trig =7;
const int echo= 6;

int sure=0;
int mesafe=0;

void setup() {
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
Serial.begin(9600);
}

void loop() {
digitalWrite(trig, HIGH);
delayMicroseconds(1000);
digitalWrite(trig, LOW);
sure = pulseIn(echo, HIGH);
mesafe = (sure/2) / 29.1; 
/* Ses hem gidip hem döndüğü için süre 2'ye bölünür. 
 * 29.1 ise ses hızına göre cm'ye dönüşüm için kullanılır.
 * Bazı kaynaklar formülü süre/58 (cm) veya süre/140 (inch) 
 * olarak vermektedir.*/
Serial.print("Mesafe: ");
Serial.print(mesafe);
Serial.println(" cm");
delay(250);
}
