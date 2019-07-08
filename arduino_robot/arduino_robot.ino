


#include <RobotController.h>

RobotController robot;
    
line  ln(3,4,5,6,2,7);
void setup() {
  // put your setup code here, to run once:
  ln.setup();
  robot.setup();

}

void loop() {
  // put your main code here, to run repeatedly:
   if( digitalRead(51) == HIGH){
  robot.loop();  
   }else if(digitalRead(51) != HIGH && digitalRead(53) != LOW)
   {
    ln.Stop();
    }
   else if(digitalRead(53) == HIGH){
  ln.loop();
   }
}
