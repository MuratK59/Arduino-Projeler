int led=2; //Bağlantı şemasında led 2 numaralı pine bağlamıştık
 
void setup()
{
  pinMode(led,OUTPUT);
  Serial.begin(9600);   //Seri iletişimi başlatır
}
void loop()
{
  if(Serial.available()) // Eğer Bluetooth bağlantısı varsa...
  {
    int data = Serial.read(); //Bluetooth'dan gelen değeri oku ve data değişkenine aktar.
    Serial.println(data);  //Bluetooth'dan gelen değeri serial ekrana yaz.
     
    if(data==1)    //Eğer gelen değer 1 ise...
      digitalWrite(led,HIGH);  //Led'i yak,
    if(data==0)       //Eğer gelen değer 0 ise...
      digitalWrite(led,LOW);  //Led'i söndür.
  }
}
