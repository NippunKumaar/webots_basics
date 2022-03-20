
#include <webots/robot.h>
#include <webots/motor.h>


#define TIME_STEP 64


int main(int argc, char **argv) {
  wb_robot_init();
  WbDeviceTag wheels[4];
  double left_speed;
  double right_speed;
  
  wheels[0] = wb_robot_get_device("Wheel 1");
  wheels[1] = wb_robot_get_device("Wheel 2");
  wheels[2] = wb_robot_get_device("Wheel 3");
  wheels[3] = wb_robot_get_device("Wheel 4"); 
  
  wb_motor_set_position(wheels[0], INFINITY);//This will kepp the wheel rotating infinitely
  wb_motor_set_position(wheels[1], INFINITY);
  wb_motor_set_position(wheels[2], INFINITY);
  wb_motor_set_position(wheels[3], INFINITY);
 
  
  while (wb_robot_step(TIME_STEP) != -1) {
  left_speed = 1;
  right_speed = 1;
  wb_motor_set_velocity(wheels[0], left_speed);
  wb_motor_set_velocity(wheels[1], left_speed);
  wb_motor_set_velocity(wheels[2], right_speed);
  wb_motor_set_velocity(wheels[3], right_speed);

  };


  wb_robot_cleanup();

  return 0;
}
