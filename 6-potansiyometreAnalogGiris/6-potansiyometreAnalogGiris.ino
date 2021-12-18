int pot = A0;  // pot analog girişlerden birine bağlanır
int led = 5;  // led ~PWM pinlerden birine bağlanır
int deger = 0;  // pot'un vereceği değeri alan değişken
void setup() {
  pinMode(pot, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  deger = analogRead(pot);
  
  Serial.print("Pot Sayısal Değeri : ");
  Serial.print(deger); 

  float gerilim = (5.00/1024.00)*deger; //5V gerilim, 1024 bite bölünür ve potansiyometreden gelen değer ile çarpılır; değerin eşiti olan gerilim hesaplanır
  Serial.print(". Pot Gerilim Değeri : ");
  Serial.println(gerilim); //Hesaplanan gerilim seri monitörde mesaj olarak gönderilir
  delay(100);
  
  deger = map(deger, 0, 1023, 0, 255);
  analogWrite(led, deger);
}
