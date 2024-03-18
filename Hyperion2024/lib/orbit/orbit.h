#ifndef ORBIT_H
#define ORBIT_H

class Orbit {
public:
    Orbit() {};
    int calculate_Direction(int ballAngle);
    int calculate_Speed(int ballStrength);
private:
    int speed = 0;
};

#endif