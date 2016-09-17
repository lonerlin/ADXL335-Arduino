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

void ADXL335::setZeroGVoltage(float zero_g_voltage_xy, float zero_g_voltage_z)
{
    ZERO_G_VOLTAGE_XY = zero_g_voltage_xy;
    ZERO_G_VOLTAGE_Z = zero_g_voltage_z;
}

float ADXL335::readX()
{
    return calculateAcceleration(_xpin, ZERO_G_VOLTAGE_XY, _CALIBRATION_OFFSET_X);
}

float ADXL335::readY()
{
    return calculateAcceleration(_ypin, ZERO_G_VOLTAGE_XY, _CALIBRATION_OFFSET_Y);
}

float ADXL335::readZ()
{
    return calculateAcceleration(_zpin, ZERO_G_VOLTAGE_Z, _CALIBRATION_OFFSET_Z);
}

