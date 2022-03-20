
#include <webots/robot.h>
#include <webots/distance_sensor.h>
#include <stdio.h>

#define TIME_STEP 64

int main(int argc, char **argv) {
  wb_robot_init();
  WbDeviceTag sensor;
  double sensor_val;
  
  sensor = wb_robot_get_device("sensor 1");
  wb_distance_sensor_enable(sensor, TIME_STEP);


  while (wb_robot_step(TIME_STEP) != -1) {
  sensor_val = wb_distance_sensor_get_value(sensor);
  printf("Sensor Value:%f\n",sensor_val);

  };


  wb_robot_cleanup();

  return 0;
}
