//StepMotor Sürme
#include <StepperMotor.h>
 
StepperMotor motor(8,9,10,11);
 
void setup(){
  Serial.begin(9600);
  motor.setStepDuration(1);
}
 
void loop(){
  motor.step(1000);
  delay(2000);
  motor.step(-1000);
  delay(2000);
}
