#include <orbit.h>
#include <common.h>

int Orbit::calculate_Direction(int ballAngle) {
    if(ballAngle < 10 || ballAngle >= 350) {
        return orbitDirections[1];
    } else if (ballAngle >= 10 || ballAngle < 90) {
        return orbitDirections[2];
    } else if (ballAngle >= 90 || ballAngle < 135) {
        return orbitDirections[3];
    } else if (ballAngle >= 135 || ballAngle < 180) {
        return orbitDirections[4];
    } else if (ballAngle >= 180 || ballAngle < 225) {
        return orbitDirections[5];
    } else if (ballAngle >= 225 || ballAngle < 270) {
        return orbitDirections[6];
    } else if (ballAngle >= 270 || ballAngle < 350) {
        return orbitDirections[7];
    } else {
        return orbitDirections[8];
    }
}

int Orbit::calculate_Speed(int ballStrength) {
    speed = (100/-255)*ballStrength + 100;
    return int(speed);
}