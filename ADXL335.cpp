/*
 * ADXL335.cpp - A library to easily read a ADXL335 sensor.
 * Written by MrTijn/Tijndagamer
 * Copyright (c) 2016 MrTijn/Tijndagamer
 * Released under the MIT license
 */

#include "Arduino.h"
#include "ADXL335.h"

ADXL335::ADXL335(int xpin, int ypin, int zpin, float vref)
{
    // Set global variables
    _xpin = xpin;
    _ypin = ypin;
    _zpin = zpin;
    _volts_per_unit = vref / 1024;

    // Set the pins
    pinMode(_xpin, INPUT);
    pinMode(_ypin, INPUT);
    pinMode(_zpin, INPUT);
}

float ADXL335::readVoltage(int pin)
{
    int rawVoltage = analogRead(pin);
    return rawVoltage * _volts_per_unit;
}

float ADXL335::calculateAcceleration(int pin, float zero_g_voltage, float calibration_offset)
{
    float voltage = readVoltage(pin);
    float adjusted_voltage = voltage - zero_g_voltage;
    float acceleration = (adjusted_voltage / VOLTS_PER_G);
    return acceleration + calibration_offset;
}

void ADXL335::setCalibrationOffset(float calibration_offset_x, float calibration_offset_y, float calibration_offset_z)
{
    _CALIBRATION_OFFSET_X = calibration_offset_x;
    _CALIBRATION_OFFSET_Y = calibration_offset_y;
    _CALIBRATION_OFFSET_Z = calibration_offset_z;
}

void ADXL335::setZeroGVoltage(float zero_g_voltage_x,float zero_g_voltage_y, float zero_g_voltage_z)
{
    ZERO_G_VOLTAGE_X = zero_g_voltage_x;
    ZERO_G_VOLTAGE_Y = zero_g_voltage_y;
    ZERO_G_VOLTAGE_Z = zero_g_voltage_z;
}

float ADXL335::readX()
{
    return calculateAcceleration(_xpin, ZERO_G_VOLTAGE_X, _CALIBRATION_OFFSET_X);
}

float ADXL335::readY()
{
    return calculateAcceleration(_ypin, ZERO_G_VOLTAGE_Y, _CALIBRATION_OFFSET_Y);
}

float ADXL335::readZ()
{
    return calculateAcceleration(_zpin, ZERO_G_VOLTAGE_Z, _CALIBRATION_OFFSET_Z);
}
int ADXL335::getAngle(int aixs)
{
    float tmp;
    float Ax=readX();
    float Ay=readY();
    float Az=readZ();
    switch (aixs)
    {
        case 0 :
            return limitAngle((atan(Ax / sqrt(Ay*Ay + Az*Az))) *180/PI);
        case 1 :
             return limitAngle((atan(Ay / sqrt(Ax*Ax + Az*Az))) *180/PI);
        case 2 :
             return limitAngle((atan(Az / sqrt(Ay*Ay + Ax*Ax))) *180/PI);
        default:
            return -1000;
    }
}
int ADXL335::limitAngle(int angle)
{
    int x;
    if(angle>90)x=90;
    else
    {
        if(angle<-90)x=-90;
        else x=angle;
    }
    return x;
}

