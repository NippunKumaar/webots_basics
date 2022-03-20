#include <stdio.h>
#include <webots/robot.h>
#include <webots/motor.h>
#include <webots/distance_sensor.h>




#define TIME_STEP 64
#define OBS_THRES 100


int main() {
  wb_robot_init();
  WbDeviceTag wheels[4];// Wheel reference variable
  WbDeviceTag sensor;// Sensor reference variable
  double sensor_val;
  double left_speed;
  double right_speed;
  int obstacle_counter = 0;
  
  sensor = wb_robot_get_device("sensor 1"); //Linking simulated distance ensor
  wb_distance_sensor_enable(sensor, TIME_STEP); // Enabling the sensor with TIME_STEP as the data rate
  
  wheels[0] = wb_robot_get_device("Wheel 1");//Linking simulated wheel
  wheels[1] = wb_robot_get_device("Wheel 2");
  wheels[2] = wb_robot_get_device("Wheel 3");
  wheels[3] = wb_robot_get_device("Wheel 4"); 

  wb_motor_set_position(wheels[0], INFINITY);//This will kepp the sheel rotatin infinitely
  wb_motor_set_position(wheels[1], INFINITY);
  wb_motor_set_position(wheels[2], INFINITY);
  wb_motor_set_position(wheels[3], INFINITY);


  while (wb_robot_step(TIME_STEP) != -1) {
  left_speed = 1;
  right_speed = 1;
  if(obstacle_counter > 0) {//Turning right
      left_speed = -1;
      right_speed = 1;
      obstacle_counter--;
    }
    else{//Checking for obstacle
        sensor_val = wb_distance_sensor_get_value(sensor);
        printf("Sensor Value:%f\n",sensor_val);      
        if(sensor_val >= OBS_THRES)
          obstacle_counter = 150;
    }     

  wb_motor_set_velocity(wheels[0], left_speed);//This will kepp the sheel rotatin infinitely
  wb_motor_set_velocity(wheels[1], left_speed);
  wb_motor_set_velocity(wheels[2], right_speed);
  wb_motor_set_velocity(wheels[3], right_speed);
  
  
  };


  /* This is necessary to cleanup webots resources */
  wb_robot_cleanup();

  return 0;
}