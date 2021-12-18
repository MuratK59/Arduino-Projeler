void setup() {
  pinMode(13, OUTPUT); // 13 numaralı pini çıkış olarak ayarla
}

void loop() {
  digitalWrite(13, HIGH);
  delay(1000); // 1000 millisaniye (1 saniye) bekle
  digitalWrite(13, LOW);
  delay(1000); // 1000 millisaniye (1 saniye) bekle
}
