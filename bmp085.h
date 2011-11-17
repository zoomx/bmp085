
#ifndef bmp085_h
#define bmp085_h

#include "WProgram.h"


class bmp085
{
 public:
  float temperature;
  float pressure;
  float atm;
  float altitude;
  void refresh();
  bmp085();
  void Calibrate();

 private:
  // Calculate temperature in deg C
  float GetTemperature(unsigned int ut);
  // Calculate pressure given up
  // calibration values must be known
  // b5 is also required so GetTemperature(...) must be called first.
  // Value returned will be pressure in units of Pa.
  long GetPressure(unsigned long up);


  // default constructor
  // Stores all of the bmp085's calibration values into global variables
  // Calibration values are required to calculate temp and pressure
  // This function should be called at the beginning of the program

  char Read(unsigned char address);
  // Read 2 bytes from the BMP085
  // First byte will be from 'address'
  // Second byte will be from 'address'+1
  int ReadInt(unsigned char address);

  // Read the uncompensated temperature value
  unsigned int ReadUT();
  // Read the uncompensated pressure value
  unsigned long ReadUP();
  //void writeRegister(int deviceAddress, byte address, byte val);
  //int readRegister(int deviceAddress, byte address);
  float calcAltitude(float pressure);

  // Calibration values
  int ac1;
  int ac2;
  int ac3;
  unsigned int ac4;
  unsigned int ac5;
  unsigned int ac6;
  int b1;
  int b2;
  int mb;
  int mc;
  int md;
  // b5 is calculated in GetTemperature(...), this variable is also used in GetPressure(...)
  // so ...Temperature(...) must be called before ...Pressure(...).
  long b5;
};


#endif
