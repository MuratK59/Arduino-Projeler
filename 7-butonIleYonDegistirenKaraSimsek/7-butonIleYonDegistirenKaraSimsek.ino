int led[]={9,10,11,12};
int buton=5;
boolean deger=0;
void setup()
{
  for(int i=0;i<4;i++){
    pinMode(led[i],OUTPUT);
  }
  pinMode(buton,INPUT);
}

void loop()
{
 deger=digitalRead(buton);
  if (deger==0){
    for(int i=0;i<4;i++){
      digitalWrite(led[i], HIGH);
      delay(300); // Wait for 1000 millisecond(s)
      digitalWrite(led[i], LOW);
      delay(300); // Wait for 1000 millisecond(s)
    }
  }else{
    for(int i=3;i>=0;i--){
      digitalWrite(led[i], HIGH);
      delay(300); // Wait for 1000 millisecond(s)
      digitalWrite(led[i], LOW);
      delay(300); // Wait for 1000 millisecond(s)
    }
  }
}
