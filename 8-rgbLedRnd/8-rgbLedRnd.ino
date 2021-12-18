byte kLed = 11;  // Kırmızı renk
byte yLed = 10;  // Yeşil renk
byte mLed = 9;   // Mavi renk

int kDeger, mDeger, yDeger;

void setup() {
  pinMode(kLed, OUTPUT);
  pinMode(yLed, OUTPUT);
  pinMode(mLed, OUTPUT);

  Serial.begin(9600);
  randomSeed(254);
}

void loop() {
  digitalWrite(11, HIGH);
  delay(200); // kırmızı Ledi yak
  digitalWrite(11, LOW);
  delay(200); // kırmızı Ledi Söndür
  
  digitalWrite(10, HIGH);
  delay(200); // yeşil Ledi yak
  digitalWrite(10, LOW);
  delay(200); // yeşil Ledi Söndür
  
  digitalWrite(9, HIGH);
  delay(200); // mavi Ledi yak
  digitalWrite(9, LOW);
  delay(200); // mavi Ledi Söndür

  kDeger=random(1,254);
  yDeger=random(1,254);
  mDeger=random(1,254);
  analogWrite(kLed, kDeger);
  analogWrite(yLed, yDeger);
  analogWrite(mLed, mDeger);
  delay(1000); // Ledleri Karışık Yak
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  Serial.print("kDeger = ");
  Serial.println(kDeger);
  Serial.print("yDeger = ");
  Serial.println(yDeger);
  Serial.print("mDeger = ");
  Serial.println(mDeger);
  delay(500); // yeşil Ledi Söndür

}
