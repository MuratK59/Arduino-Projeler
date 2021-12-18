boolean durum=0;
void setup() {
  pinMode(9, OUTPUT);
  pinMode(3,INPUT);
  Serial.begin(9600);
}

void loop() {
  durum=digitalRead(3);
  digitalWrite(9,durum);
  delay(250);
  
  Serial.print("Buton durumu :");
  Serial.println(durum);
  Serial.print("Led Durumu:");
  Serial.println(!durum);
}
