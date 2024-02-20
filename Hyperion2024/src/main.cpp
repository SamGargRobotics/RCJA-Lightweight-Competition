#include <light_system.h> //Light system header file
#include <tssp_system.h> //tssp system header file
#include <Motor.h>

Light_System ls_sys = light_system(A0); //Creating Light System
Tssp_system tssp_sys = Tssp_system(30); //Creating Tssp System
Motor motor_1 = Motor(13, 22, 23); //Creating motor objects
Motor motor_2 = Motor(12, 24, 25);
Motor motor_3 = Motor(11, 26, 27);
Motor motor_4 = Motor(10, 28, 29);




void setup() {
  ls_sys.init(); //Initializing Light Sensors
  tssp_sys.init(); //Initializing Tssps
  motor_1.init(); //Initializing Motors
  motor_2.init();
  motor_3.init();
  motor_4.init();
  Serial.begin(9600);
}

void loop() {
  int ls_value_1 = ls_1.read(); //reading light sensor consistantly
  Serial.println(ls_value_1);
}