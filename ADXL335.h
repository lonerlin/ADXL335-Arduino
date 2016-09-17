/*
 * ADXL335.h - A library to easily read a ADXL335 sensor.
 * Written by MrTijn/Tijndagamer
 * Copyright (c) 2016 MrTijn/Tijndagamer
 * Released under the MIT license
 */

#ifndef ADXL335_h
#define ADXL335_h

#include "Arduino.h"

class ADXL335
{
    public:
        ADXL335(int xpin, int ypin, int zpin, float vref);
        void setCalibrationOffset(float calibration_offset_x, float calibration_offset_y, float calibration_offset_z);
        void setZeroGVoltage(float zero_g_voltage_xy, float zero_g_voltage_z); 
        float readX();
        float readY();
        float readZ();
    private:
        int _xpin;
        int _ypin;
        int _zpin;
        float _vref; // not sure if needed
        float _volts_per_unit;

        // Constants from the datasheet
        float ZERO_G_VOLTAGE_XY = 1.6;
        float ZERO_G_VOLTAGE_Z = 1.67;
        float VOLTS_PER_G = 0.330;

        // Calibration values
        float _CALIBRATION_OFFSET_X = 0.0;
        float _CALIBRATION_OFFSET_Y = 0.0;
        float _CALIBRATION_OFFSET_Z = 0.0;

        // Methods        
        float readVoltage(int pin);
        float calculateAcceleration(int pin, float zero_g_voltage, float calibration_offset);        
};

#endif
