#ifndef ORBIT_H
#define ORBIT_H

class Orbit {
public:
    Orbit() {};
    int calculate_Direction(int ballAngle);
    int calculate_Speed(int ballStrength);
    int calculate_Direction2(int ballAngle2);
    float moving_angle = 0;
private:
    int speed = 0;
    int orbitDirections[8] = {0, 90, 180, 270, 90, 180, 270, 0};
};

#endif