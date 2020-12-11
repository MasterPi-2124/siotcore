// Sensor.h

#ifndef _SENSOR_h
#define _SENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#define SHT_dataPin  21
#define SHT_clockPin 22

#define Dust_Serial Serial
#define Dust_baudrate 9600

struct __sensor {
	int sensor_status;
	float *sensor_value;
};

class Sensor {
private:	
public:
	__sensor _sensor;
	virtual void setup()=0;
	virtual int read()=0;
	virtual void calibrate() = 0;
  virtual void read_calib() = 0;
	float read_value(int _add);
  int write_value(float _value, int _add);
};

class Dust : public Sensor {
public:
	float aPm25, bPm25, aPm10, bPm10;
	Dust();
	~Dust();
	void setup();
  void read_calib();
	int read();
	void calibrate();
};

class SHT : public Sensor {
public:
	float oTemp, oHum;
	SHT();
	~SHT();
	void setup();
  void read_calib();
	int read();
	void calibrate();
};


#endif
