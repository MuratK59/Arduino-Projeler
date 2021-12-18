#include <IRremote.h>
IRsend irsend;
const int button1 = 4;
//const int button2 = 5;
//const int button3 = 6;
void setup() {
pinMode(button1, INPUT);
//pinMode(button2, INPUT);
//pinMode(button3, INPUT);
}
void loop()
{
  if (digitalRead(button1) == HIGH)
  {
  delay(50);
  //bu lg kumandanın açma kapaması
  irsend.sendNEC(0x20DF10EF, 32);
  delay(200);
  }
  /*if (digitalRead(button2) == HIGH)
  {
  delay(50);
  irsend.sendRC5(0x821, 32);
  delay(200);
  }
  if (digitalRead(button3) == HIGH)
  {
  delay(50);
  irsend.sendRC5(0x820, 32);
  delay(200);
  }*/
}
