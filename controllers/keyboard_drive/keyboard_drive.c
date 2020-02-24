#include <webots/keyboard.h>
#include <webots/distance_sensor.h>
#include <webots/motor.h>
#include <webots/robot.h>

#define TIME_STEP 64

enum {
  WB_KEYBOARD_END,
  WB_KEYBOARD_HOME,
  WB_KEYBOARD_LEFT,
  WB_KEYBOARD_UP,
  WB_KEYBOARD_RIGHT,
  WB_KEYBOARD_DOWN,
  WB_KEYBOARD_PAGEUP,
  WB_KEYBOARD_PAGEDOWN,
  WB_KEYBOARD_NUMPAD_HOME,
  WB_KEYBOARD_NUMPAD_LEFT,
  WB_KEYBOARD_NUMPAD_UP,
  WB_KEYBOARD_NUMPAD_RIGHT,
  WB_KEYBOARD_NUMPAD_DOWN,
  WB_KEYBOARD_NUMPAD_END,
  WB_KEYBOARD_KEY,
  WB_KEYBOARD_SHIFT,
  WB_KEYBOARD_CONTROL,
  WB_KEYBOARD_ALT
};

void wb_keyboard_enable(int sampling_period);
void wb_keyboard_disable();
int wb_keyboard_get_sampling_period();
int wb_keyboard_get_key();

int main(int argc, char **argv) {
  wb_robot_init();
  int i;
  WbDeviceTag wheels[4];
  char wheels_names[4][8] = {"wheel1", "wheel2", "wheel3", "wheel4"};
  for (i = 0; i < 4; i++) {
    wheels[i] = wb_robot_get_device(wheels_names[i]);
    wb_motor_set_position(wheels[i], INFINITY);
  }
  while (wb_robot_step(TIME_STEP) != -1) {
    double left_speed = 0.0;
    double right_speed = 0.0;
	int c = wb_keyboard_get_key();

if ((c >= 0) && c != pc) {
      switch (c) {
        case WB_KEYBOARD_UP:
          printf("Go forwards\n");
		  left_speed = 1.0;
          right_speed = 1.0;
          break;
        case WB_KEYBOARD_DOWN:
          printf("Go backwards\n");
		  left_speed = 1.0;
          right_speed = -1.0;
          break;
        case WB_KEYBOARD_LEFT:
          printf("Strafe left\n");
		  left_speed = 1.0;
          right_speed = -1.0;
          break;
        case WB_KEYBOARD_RIGHT:
          printf("Strafe right\n");
		  left_speed = -1.0;
          right_speed = 1.0;
          break;
        case WB_KEYBOARD_END:
        case ' ':
          printf("Reset\n");
		  wb_robot_cleanup();

}
    if (avoid_obstacle_counter > 0) {
      avoid_obstacle_counter--;
      left_speed = 1.0;
      right_speed = -1.0;
    } else { // read sensors
      double ds_values[2];
      for (i = 0; i < 2; i++)
        ds_values[i] = wb_distance_sensor_get_value(ds[i]);
      if (ds_values[0] < 950.0 || ds_values[1] < 950.0)
        avoid_obstacle_counter = 100;
    }
    wb_motor_set_velocity(wheels[0], left_speed);
    wb_motor_set_velocity(wheels[1], right_speed);
    wb_motor_set_velocity(wheels[2], left_speed);
    wb_motor_set_velocity(wheels[3], right_speed);
  }
  wb_robot_cleanup();
  return 0;  // EXIT_SUCCESS
}

