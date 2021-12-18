int pirState = 0;

void setup()
{
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  pirState = digitalRead(2);
  if (pirState == HIGH) {
    digitalWrite(13, HIGH);
    Serial.println("Pir Aktif!!!");
  } else {
    digitalWrite(13, LOW);
    Serial.println("KİMSE YOK....");
  }
  delay(10);
}
