#include <SoftwareSerial.h>
 
SoftwareSerial BTSerial(10, 11); // TX | RX
int STATE=9;  // STATE pin arduino bağlantısı
 
void setup()
{
  pinMode(9, OUTPUT);   // STATE pini çıkış pini olarak atandı
  digitalWrite(STATE, HIGH); // STATE pine güç verdik
  Serial.begin(9600);
  Serial.println("Konfigürasyon Modu Açık:");
  BTSerial.begin(9600);  
}
 
void loop()
{
   if (BTSerial.available())
    Serial.write(BTSerial.read());
 
  if (Serial.available())
    BTSerial.write(Serial.read());
}
