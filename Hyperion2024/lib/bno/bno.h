#ifndef BNO_H
#define BNO_H

#include <Arduino.h>

class bno {
public:
    bno(int sda_pin, int sdl_pin);
    void init();
private:
    int sda;
    int sdl;
}
#endif