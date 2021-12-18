#include <SPI.h>
#include <MFRC522.h>
int SdaPin=10;
int RstPin=9;
int buzzerPin=2;
int ledPin=3;
MFRC522 rfid(SdaPin, RstPin); //RFID nesnesi oluşturup bağlantı pinlerini tanımladık.
 
void setup() {
  Serial.begin(9600);
  SPI.begin(); //SPI haberleşmesini başlattık.
  rfid.PCD_Init(); //RFID Kart okuyucuyu başlattık.
  pinMode(ledPin, OUTPUT);
  
}
 
void loop() {
  if (rfid.PICC_IsNewCardPresent()) {
    if (rfid.PICC_ReadCardSerial()) {
      Serial.print("Kart Tespit Edildi-Kart ID: ");
      Serial.print(rfid.uid.uidByte[0]);
      Serial.print(",");
      Serial.print(rfid.uid.uidByte[1]);
      Serial.print(",");
      Serial.print(rfid.uid.uidByte[2]);
      Serial.print(",");
      Serial.println(rfid.uid.uidByte[3]);

      tone(buzzerPin, 392);
      digitalWrite(ledPin, HIGH);
      delay(500);
      noTone(buzzerPin);
      digitalWrite(ledPin, LOW);
      delay(20);

    }
    rfid.PICC_HaltA();
  }
}
