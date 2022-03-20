
#include <webots/robot.h>
#include <stdio.h>

#define TIME_STEP 64

int main() {
  
  wb_robot_init();
  
  while (wb_robot_step(TIME_STEP) != -1) {
  
  printf("Hello World!!!\n");
   
  };

  wb_robot_cleanup();

  return 0;
}
