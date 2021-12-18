int xPin = A0; // A0-A5 analog pinlerinden herhangi birine bağlanabilir.
int yPin = A1; // A0-A5 analog pinlerinden herhangi birine bağlanabilir.
int butonPin = 2; // Joystick buton pini arduino bağlantısı (Joystick SW çıkışı)
 
int xPozisyonu = 0;
int yPozisyonu = 0;
int butonDurum = 0;
 
void setup() {
Serial.begin(9600);
pinMode(xPin, INPUT);
pinMode(yPin, INPUT);
pinMode(butonPin, INPUT_PULLUP);
 
 
}
 
void loop() {
xPozisyonu = analogRead(xPin);
yPozisyonu = analogRead(yPin);
butonDurum = digitalRead(butonPin);
 
Serial.print("X Pozisyonu: ");
Serial.print(xPozisyonu);
Serial.print(" | Y Pozisyonu: ");
Serial.print(yPozisyonu);
Serial.print(" | Buton Durum: ");
Serial.println(butonDurum);
 
delay(100);
}
