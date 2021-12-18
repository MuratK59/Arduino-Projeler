byte led = 9;
byte LDR = A0;
int LDRDeger = 0;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(LDR, INPUT);
  Serial.begin(9600);
}
void loop() {
  LDRDeger = 255 - map(analogRead(LDR), 0, 1023, 255, 0);

  Serial.print("LDRDeger :");
  Serial.println(LDRDeger);
  
  analogWrite(led, LDRDeger);
}
