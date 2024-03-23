#ifndef ORBIT_H
#define ORBIT_H

class Orbit {
public:
    Orbit() {};
    int calculate_Direction(int ballAngle);
    int calculate_Speed(int ballStrength);
    int calculate_Direction2(int ballAngle2);
private:
    int speed = 0;
};

#endif