int sensor_pin = A0;                  //Sensörün takılacağı pin
int output_value = 0;

void setup() {
   pinMode(sensor_pin, INPUT);        //Sensörün takılacağı pini INPUT olarak ayarlıyoruz.
   Serial.begin(9600);
   Serial.println("Reading From the Sensor ...");
   delay(2000);
}
void loop() {
   output_value= analogRead(sensor_pin);
   output_value = map(output_value,1023,0,0,100);
   Serial.print("Mositure : ");
   Serial.print(output_value);
   Serial.println("%");
   delay(1000);
}
