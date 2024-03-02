#ifndef CAMERA_H
#define CAMERA_H
#include <Arduino.h>

class Camera {
public:
    Camera() {};
    void init();
    int read();
private:
};
#endif