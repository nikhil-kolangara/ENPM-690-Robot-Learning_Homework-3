#include <webots/DistanceSensor.hpp>
#include <webots/Motor.hpp>
#include <webots/Robot.hpp>

#include <webots/Keyboard.hpp>

namespace webots {
  class Keyboard {
    enum {
      END, HOME, LEFT, UP, RIGHT, DOWN,
      PAGEUP, PAGEDOWN, NUMPAD_HOME, NUMPAD_LEFT,
      NUMPAD_UP, NUMPAD_RIGHT, NUMPAD_DOWN, NUMPAD_END,
      KEY, SHIFT, CONTROL, ALT
    };

    virtual void enable(int samplingPeriod);
    virtual void disable();
    int getSamplingPeriod() const;
    int getKey() const;
  }
}

int main(){

int pc = 0;
  wb_keyboard_enable(TIME_STEP);

 while (true) {
    step();

    int c = getkey();
    if ((c >= 0) && c != pc) {
      switch (c) {
        case WB_KEYBOARD_UP:
          printf("Go forwards\n");
          base_forwards();
          break;
        case WB_KEYBOARD_DOWN:
          printf("Go backwards\n");
          base_backwards();
          break;
        case WB_KEYBOARD_LEFT:
          printf("Strafe left\n");
          base_strafe_left();
          break;
        case WB_KEYBOARD_RIGHT:
          printf("Strafe right\n");
          base_strafe_right();
          break;
        case WB_KEYBOARD_PAGEUP:
          printf("Turn left\n");
          base_turn_left();
          break;
        case WB_KEYBOARD_PAGEDOWN:
          printf("Turn right\n");
          base_turn_right();
          break;
        case WB_KEYBOARD_END:
        case ' ':
          printf("Reset\n");
          base_reset();
          arm_reset();
          break;

}
