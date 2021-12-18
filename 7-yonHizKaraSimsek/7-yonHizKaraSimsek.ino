/* Hazırlayan Levent TOPAKTAŞ
*/
int led[]={9,10,11,12};
int buton=3;
int butonDeger=0;
int pot=A0;
int potDeger=0;
int sure=300;
void setup()
{
  for (int i=0;i<4;i++){
  pinMode(led[i], OUTPUT);
  }
  pinMode(buton,INPUT);
  pinMode(pot,INPUT);
  Serial.begin(9600);
}

void loop()
{
  butonDeger=digitalRead(buton);
  delay(10);
  potDeger=analogRead(pot);
  delay(10);
  Serial.print("potDeger="); Serial.println(potDeger);
  delay(100);
  sure=map(potDeger,0,1024,100,1000);
  Serial.print("butonDeger="); Serial.println(butonDeger);
  delay(100);
  Serial.print("sure="); Serial.println(sure);
  if (butonDeger==0){
    for (int x=0;x<4;x++){
      digitalWrite(led[x],HIGH);
      delay(sure);
      digitalWrite(led[x],LOW);
      delay(sure);
    }
  } else {
    for (int y=3;y>=0;y--){
      digitalWrite(led[y],HIGH);
      delay(sure);
      digitalWrite(led[y],LOW);
      delay(sure);
    }
  }
}
