void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  
}

void loop()
{
  digitalWrite(13, HIGH);
  delay(500); // 1. Ledi yak
  digitalWrite(13, LOW);
  delay(500); // 1. Ledi Söndür
  
  digitalWrite(12, HIGH);
  delay(500); // 2. Ledi yak
  digitalWrite(12, LOW);
  delay(500); // 2. Ledi Söndür
  
  digitalWrite(11, HIGH);
  delay(500); // 3. Ledi yak
  digitalWrite(11, LOW);
  delay(500); // 3. Ledi Söndür
  
  digitalWrite(10, HIGH);
  delay(500); // 4. Ledi yak
  digitalWrite(10, LOW);
  delay(500); // 4. Ledi Söndür
}
