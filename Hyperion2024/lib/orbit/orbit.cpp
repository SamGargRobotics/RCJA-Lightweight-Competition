#include <orbit.h>

int Orbit::calculate_Direction(int ballAngle) {
    if(ballAngle < 10 || ballAngle >= 350) {
        return 0;
    } else if (ballAngle >= 10 || ballAngle < 90) {
        return 90;
    } else if (ballAngle >= 90 || ballAngle < 135) {
        return 180;
    } else if (ballAngle >= 135 || ballAngle < 180) {
        return 270;
    } else if (ballAngle >= 180 || ballAngle < 225) {
        return 90;
    } else if (ballAngle >= 225 || ballAngle < 270) {
        return 180;
    } else if (ballAngle >= 270 || ballAngle < 350) {
        return 270;
    } else {
        return 180;
    }
}

int Orbit::calculate_Speed(int ballStrength) {
    speed = (100/-255)*ballStrength + 100;
    return int(speed);
}