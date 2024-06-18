#ifndef MPU_H
#define MPU_H

#include <I2C.h>
#include <Common.h>

class MPU {
public:
    MPU() {};
    void init();
    void update();
    float floatMod(float x, float y);
    float heading;
private:
    void readGyroscope(float gyroData[3]);
    void calibrate();
    float convertRawGyro(int raw);
    long previousTimeGyro;
    long previousDrift;
    float calibrationGyro;
    float drift = 0;
};

#endif
