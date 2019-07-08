//
// Created by Silvina on 29.05.2019.
//

#include "RobotController.h"


char t;
RobotController::RobotController(){

}
void RobotController::setup() {

    pinMode(in1,OUTPUT);  //left motors forward
    pinMode(in2,OUTPUT); //left motors reverse
    pinMode(in3,OUTPUT); //right motors forward
    pinMode(in4,OUTPUT); //right motors reverse
    Serial.begin(9600);

    pinMode(51,INPUT_PULLUP); //Controlador principal

}

void RobotController::loop() {
    while(digitalRead(51) != LOW && Serial.available())
    {
        t = Serial.read();
        Serial.println(t);

        if(t == '1')
        {   Serial.println("Foward");
            //move forward(all motors rotate in forward direction)
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);
        }
        else if(t == '2')
        { //move reverse (all motors rotate in reverse direction)
            Serial.println("Reverse");
            digitalWrite(in1,LOW);
            digitalWrite(in2,HIGH);
            digitalWrite(in3,LOW);
            digitalWrite(in4,HIGH);
        }
        else if(t == '3')
        {
            //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
            Serial.println("Right");

            digitalWrite(in1,LOW);
            digitalWrite(in2,LOW);
            digitalWrite(in3,HIGH);
            digitalWrite(in4,LOW);
        }
        else if(t == '4')
        {
            //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
            Serial.println("Left");
            digitalWrite(in1,HIGH);
            digitalWrite(in2,LOW);
            digitalWrite(in3,LOW);
            digitalWrite(in4,LOW);
        }
        else if(t == '5') {
            Serial.println("Stop");
            //STOP (all motors stop)
            digitalWrite(in1, LOW);
            digitalWrite(in2, LOW);
            digitalWrite(in3, LOW);
            digitalWrite(in4,LOW);
        }
    }
    delay(100);
}





