# ADXL335

A simple library to read values from an ADXL335 analog accelerometer.
Works on Arduino and Arduino-compatible devices with at least 3 analog inputs.

# Usage

The library contains one single class: ADXL335. The following methods are available to the user:
```c++
ADXL335(int xpin, int ypin, int zpin, float vref)
float readX()
float readY()
float readZ()
void setCalibrationOffset(float calibration_offset_x, float calibration_offset_y, float calibration_offset_z)
void setZeroGVoltage(float zero_g_voltage_xy, float zero_g_voltage_z)
```

Create an instance of the class, and read simply read the values using the read methods.

