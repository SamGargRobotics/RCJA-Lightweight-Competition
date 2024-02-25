#include <light_system.h> //Light system header file
#include <tssp_system.h> //tssp system header file
#include <drive_system.h> //motor system header file
#include <bno.h>
#include <camera.h>

Light_System ls_sys = Light_System(A0); //Creating Light System
Tssp_system tssp_sys = Tssp_system(30); //Creating Tssp System
Drive_system drive_sys = Drive_system();//13, 22, 23); //Initializing Drive System

void setup() {
  ls_sys.init(); //Initializing Light Sensors
  tssp_sys.init(); //Initializing Tssps
  drive_sys.init(); //Intializing Drive System
  Serial.begin(9600);
}

void loop() {
}