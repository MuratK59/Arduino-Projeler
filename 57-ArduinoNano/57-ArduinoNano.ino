byte deger=0;
void setup() {
  pinMode(3, OUTPUT);
}
void loop() {
  delay(100);
  analogWrite(3, deger); // deger 0-255 arasında olabilir.
  delay(250); 
  deger+=10;
  if (deger>250){
    deger=0;
    delay(2000);
  }
}
