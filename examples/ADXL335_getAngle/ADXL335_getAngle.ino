/*
 * ADXL335_example.ino - Example for ADXL335 library
 * Written by LIN
 * Copyright (c) 2017 LIN
 * Released under the MIT license
 */

#include <ADXL335.h>

ADXL335 adxl335(A0, A1, A2, 3.3);

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    Serial.print(adxl335.getAngle(X));
    Serial.print("\t");
    Serial.print(adxl335.getAngle(Y));
    Serial.print("\t");
    Serial.print(adxl335.getAngle(Z));
    Serial.print("\t");
    Serial.println();
    delay(500); 
}
