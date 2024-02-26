#include "bno.h"

bno::bno(int sda_pin, int sdl_pin) {
    sda = sda_pin;
    sdl = sdl_pin;
}

void bno::init() {
    pinMode(sda, INPUT);
    pinMode(sdl, INPUT);
}