int esikDegeri = 200;               //Gaz eşik değerini belirliyoruz.    
int buzzerPin = 9;                  //Buzzerın takılacağı pin
int deger;                          //Sensörden okunan değer

void setup() {
  pinMode(buzzerPin, OUTPUT);       //Buzzer pinimizi çıkış olarak ayarlıyoruz.
  Serial.begin(9600);
}

void loop() {
  delay(100);
  deger = analogRead(A0);           //Sensörden analog değer okuyoruz.
  Serial.print("Okunan Değer : ");
  Serial.println(deger);
  if(deger > esikDegeri){           //Sensörden okunan değer eşik değerinden büyükse çalışır.
    tone(buzzerPin, 262);
    delay(200);
    noTone(buzzerPin);
    delay(20);
  }
  else{                             //Sensörden okunan değer eşik değerinin altındaysa çalışır.
    digitalWrite(buzzerPin, LOW);
  }
}
