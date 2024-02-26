#include <light_system.h> //Light system header file
#include <tssp_system.h> //tssp system header file
#include <drive_system.h> //motor system header file
#include <bno.h> //bno or imu (compass) header file
#include <camera.h> //camera header file

Light_System ls_sys = Light_System(A0); //Creating Light System
Tssp_system tssp_sys = Tssp_system(30); //Creating Tssp System
Drive_system drive_sys = Drive_system(); //Initializing Drive System
bno comp = bno(20, 21); //Initialzing BNO or IMU (Compass)

void setup() {
  ls_sys.init(); //Initializing Light Sensors
  tssp_sys.init(); //Initializing Tssps
  drive_sys.init(); //Intializing Drive System
  comp.init(); //Initialize Compass
  Serial.begin(9600);
}

void loop() {
}