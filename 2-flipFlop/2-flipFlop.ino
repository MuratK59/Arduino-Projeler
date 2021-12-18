void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);//dijital çıkış belirtiyoruz

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH);
  delay(1000); // 1000 millisaniye (1 saniye) bekle
  digitalWrite(13, LOW);
  delay(1000); // 1000 millisaniye (1 saniye) bekle
}
