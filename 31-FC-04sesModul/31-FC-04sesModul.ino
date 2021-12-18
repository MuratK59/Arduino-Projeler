// FC-04 Sound Sensor
const int SenOut = A0;
const int LED1 = 2;
const int LED2 = 3;
int sensorValue = 0;

void setup()
{
pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(SenOut, INPUT);
Serial.begin(9600);
}

void loop()
{
  sensorValue = analogRead(SenOut);
  if (sensorValue > 650)
  {
    Serial.print("Yüksek - ");
    Serial.println(sensorValue);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    delay(300);
  }
  else
  {
    Serial.print("Düşük - ");
    Serial.println(sensorValue);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED1, LOW);
    delay(300);
  }
  
  delay(300);
}
