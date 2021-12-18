#define potpin A0 //Potansiyometreyi A0 pinine tanımlıyoruz
int deger=0; //"Değer" adlı 0 başlangıçlı bir değişken tanımlıyoruz
void setup() 
{
  Serial.begin(9600); //9600 Baund bir seri haberleşme başlatıyoruz
  Serial.println("Pot Deger Okuma"); //Seri monitörde bir kez gönderilen bir mesaj tanımlıyoruz
}
void loop() 
{
  deger  = analogRead(potpin); //"Değer" değişkeni potansiyometrenin değerini okuyup buna göre değişir
  Serial.println(deger); //Okunan değer seri monitörde mesaj olarak gönderilir
  delay(100); //Bu işlem 100 milisaniye aralıklarla yapılır
}
