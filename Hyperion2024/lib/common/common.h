#include <math.h>

#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105
#define EULER 2.718281828459045235360287471352
#define CIRCLE_DEGREES 360
#define SEMI_CIRCLE_DEGREES 180

#define PID_p 0 //how fast it goes towards the point that you want - tune this
#define PID_i 0
#define PID_d 0 //how fast it slows down once it gets close to the 'p' point - tune this
#define PID_abs_max 100 //The cap value that the PID can produce from the numbers given

#define ANALOG_DIV_100 2.55
#define SPEED_GRADIENT 100/-255
#define NEGATIVE_SPEED_GRADIENT 100/255
#define SPEED_Y_INTERCEPT 100

#define line_avoidance_thresh 800

#define TSSP1 30
#define TSSP2 36
#define TSSP3 38
#define TSSP4 41
#define TSSP5 
#define TSSP6 35
#define TSSP7 36
#define TSSP8 37
#define TSSP9 38
#define TSSP10 39
#define TSSP11 40
#define TSSP12 41