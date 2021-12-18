//Arduino bluetooth controller uygulamasında ki yapıları görmek için yazıldı.
char data = 0;

void setup( )
{
// seri port ayarı
Serial.begin(9600);
}

void loop()
{
// seri porttan komut bekleniyor
  if(Serial.available() > 0)
  {
    data = Serial.read();
    Serial.println(data);

  }
}
//ugulama içerisinde her bir kontrol için istediğimiz tanımlamayı yapabiliyoruz.
