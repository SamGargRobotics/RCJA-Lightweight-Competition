#include "camera.h"

void Camera::init() {
    Serial3.begin(115200);
}

int Camera::read() {
    while(Serial3.available() >= 1) {}
}

//0.70833333333333333333333333333333 Degrees to analog
//1.4117647058823529411764705882353 Analog to degrees
