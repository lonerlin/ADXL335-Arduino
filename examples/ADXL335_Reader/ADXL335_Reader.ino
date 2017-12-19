/*
 * ADXL335_example.ino - Example for ADXL335 library
 * Written by MrTijn/Tijndagamer
 * Copyright (c) 2016 MrTijn/Tijndagamer
 * Released under the MIT license
 */

#include <ADXL335.h>

ADXL335 adxl335(A0, A1, A2, 5);

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    Serial.print(adxl335.readX());
    Serial.print("\t");
    Serial.print(adxl335.readY());
    Serial.print("\t");
    Serial.print(adxl335.readZ());
    Serial.print("\t");
    Serial.println();
    delay(500);
}
