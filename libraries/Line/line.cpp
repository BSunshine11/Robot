//
// Created by Silvina on 29.05.2019.
//

#include "line.h"

line :: line (int in1, int in2, int in3, int in4, int enA, int enB) { //perguntar ao prof sobre isso.
// connect motor controller pins to Arduino digital pins
    qtr.setTypeRC();
    const uint8_t array[6] ={54, 55, 56, 57, 58, 59};
    qtr.setSensorPins(array, 5);
    this->enA = 2;
    this->in1 = 3;
    this->in2 = 4;   // motor 1
    this->in3 = 5;
    this->in4 = 6;
    this->enB = 7;   // motor 2

}

void line:: Stop()   // stop robot
{
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}

void line::Forward (int LeftSpeed, int RightSpeed) // range 0 - 255
{
    digitalWrite(in1, HIGH); // turn on left motor to forward
    digitalWrite(in2, LOW);
    analogWrite(enA, LeftSpeed);
    digitalWrite(in3, HIGH); // turn on right motor to forward
    digitalWrite(in4, LOW);
    analogWrite(enB, RightSpeed);
}
void line::Reverse (int LeftSpeed, int RightSpeed) // range 0-255
{
    digitalWrite(in1, LOW); // turn on left motor to forward
    digitalWrite(in2, HIGH);
    analogWrite(enA, LeftSpeed);
    digitalWrite(in3, LOW); // turn on right motor to forward
    digitalWrite(in4, HIGH);
    analogWrite(enB, RightSpeed);
}

void line::SetPixelsToSensors() // turn on NeoPixels that are less than threshold value
{
    for (int n=0; n<5; n++)
    {
        if (sensor[n] < Threshold[n])
            pixels.setPixelColor(4-n, pixels.Color(40,40,40));
        else
            pixels.setPixelColor(4-n, pixels.Color(171,116,14));
        pixels.show();
    }
}

void line::setup()
{
    // set all the motor control pins to outputs
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);

    Serial.begin(9600); // used to write to serial monitor
    pixels.begin();     // initialize NeoPixels

    // set up pushbutton
    pinMode(53,INPUT_PULLUP); //Controlador principal



}

void line::loop()
{
    while (digitalRead(53) != LOW) // loop until pushbutton is pressed
    {
        //for testing QTR, print out sensor value to Serial Monitor
        qtr.read(sensor);
        SetPixelsToSensors();
        if (sensor[0] < Threshold[0]) {
            Forward(10, 60);
        } else if (sensor[4] < Threshold[4]) {
            Forward(60, 10);
        } else if (sensor[1] < Threshold[1]) {
            Forward(25, 60);
        } else if (sensor[3] < Threshold[3]) {
            Forward(60, 25);
        } else if (sensor[2] < Threshold[2]) {
            Forward(60, 60);
        } else
            Forward(60, 60);
        Serial.print(sensor[0]);
        Serial.print(" ");
        Serial.print(sensor[1]);
        Serial.print(" ");
        Serial.print(sensor[2]);
        Serial.print(" ");
        Serial.print(sensor[3]);
        Serial.print(" ");
        Serial.print(sensor[4]);
        Serial.print("\n");

        delay(10);
    }
}
