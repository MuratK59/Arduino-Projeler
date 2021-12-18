char data = 0;
int led1 = 6;
int led2 = 7;

void setup( )
{
// seri port ayarı
Serial.begin(9600);

// led pin ayarları
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
digitalWrite(led1, LOW);
digitalWrite(led2, LOW);
}

void loop()
{
// seri porttan komut bekleniyor
  if(Serial.available() > 0)
  {
    data = Serial.read();
    Serial.println(data);
    
    if(data == '1'){   // eğer komut 1 ise 1. röleyi çek
    digitalWrite(led1, HIGH);
    Serial.println("Mavi 1");}
    
    else if(data == '0'){  // eğer komut 0 ise 1. röleyi bırak
    digitalWrite(led1, LOW);
    Serial.println("Mavi 0");}
    
    if(data == '2'){  // eğer komut 2 ise 2. röleyi çek
    digitalWrite(led2, HIGH);
    Serial.println("Yeşil 1");}
    
    else if(data == '3'){  // eğer komut 3 ise 2. röleyi bırak
    digitalWrite(led2, LOW);
    Serial.println("Yeşil 0");}
  }
}
