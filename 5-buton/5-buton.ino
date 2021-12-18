/* Hazırlayan : Levent TOPAKTAŞ
 * Butona basınca 6. pine bağlı Led'i yakan,
 * butonu bırakınca Led'i söndüren devre
*/


int led=6;
int buton=4;
boolean butonDurumu=0;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(buton,INPUT);
}

void loop()
{
  butonDurumu=digitalRead(buton);
  digitalWrite(led, butonDurumu);
  //digitalWrite(led, !butonDurumu);//varsayılan yanması istenirse
 }
