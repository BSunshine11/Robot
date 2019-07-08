//
// Created by Silvina on 29.05.2019.
//

#ifndef ROBOT_LINE_H
#define ROBOT_LINE_H
#include <QTRSensors.h>
#include <Adafruit_NeoPixel.h>

class line {
public:

    Adafruit_NeoPixel pixels = Adafruit_NeoPixel(8, 10); // NumPixels, Pin

// Arduino Mega - connect QTR wires to Analog pins 0 - 7
    QTRSensors qtr; // Mega code


//(char[]) ({54, 55, 56, 57, 58, 59}), 5


// Arduino Uno - connect QTR wires to Analog pins 0 - 5
// QTRSensorsRC qtr((char[]) {14, 15, 16, 17, 18, 19}, 6); // Uno code

    unsigned int sensor[6];  // used to store the value each sensor reads
    // change these to set the the threshold for each sensor to detect a line
    int Threshold[5] = {700, 700, 700, 700, 700};

    int in1;
    int in2;
    int in3;
    int in4;
    int enA;
    int enB;

    line (int in1, int in2, int in3, int in4, int enA, int enB);
    void Forward (int LeftSpeed, int RightSpeed);
    void Reverse(int,int);
    void SetPixelsToSensors();
public:
    void Stop();

    void setup();
    void loop() ;

};


#endif //ROBOT_LINE_H
