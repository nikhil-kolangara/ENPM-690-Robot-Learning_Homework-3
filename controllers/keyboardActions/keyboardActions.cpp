#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <webots/Keyboard.hpp>

#define TIME_STEP 64

// All the webots classes are defined in the "webots" namespace
using namespace webots;

// This is the main program of your controller.
// It creates an instance of your Robot instance, launches its
// function(s) and destroys it at the end of the execution.
// Note that only one instance of Robot should be created in
// a controller program.
// The arguments of the main function can be specified by the
// "controllerArgs" field of the Robot node
int main(int argc, char **argv) {
  // create the Robot instance.
  Robot *robot = new Robot();
  
  //car = robot->getKeyboard();
  
  Motor *wheels[4];
  char wheels_names[4][8] = {"wheel1", "wheel2", "wheel3", "wheel4"};
  for (int i = 0; i < 4; i++) {
    wheels[i] = robot->getMotor(wheels_names[i]);
    wheels[i]->setPosition(INFINITY);
    wheels[i]->setVelocity(0.0);
  }
  // get the time step of the current world.
  int timeStep = (int)robot->getBasicTimeStep();

  // You should insert a getDevice-like function in order to get the
  // instance of a device of the robot. Something like:
  //  Motor *motor = robot->getMotor("motorname");
  //  DistanceSensor *ds = robot->getDistanceSensor("dsname");
  //  ds->enable(timeStep);

  // Main loop:
  // - perform simulation steps until Webots is stopping the controller
  Keyboard *enteredKeys = new Keyboard();
  enteredKeys->enable(TIME_STEP);

  while (robot->step(timeStep) != -1) {  
   
  switch (enteredKeys->getKey()) {
        case Keyboard.UP:
          { double leftSpeed = 1.0;
            double rightSpeed = 1.0;
            wheels[0]->setVelocity(leftSpeed);
            wheels[1]->setVelocity(rightSpeed);
            break;
          }
         case Keyboard.DOWN:
          { double leftSpeed = -1.0;
            double rightSpeed = -1.0;
            wheels[2]->setVelocity(leftSpeed);
            wheels[3]->setVelocity(rightSpeed);
            break;
          }
          case Keyboard.LEFT:
          { double leftSpeed = -1.0;
            double rightSpeed = 1.0;
            wheels[0]->setVelocity(leftSpeed);
            wheels[2]->setVelocity(leftSpeed);
            wheels[3]->setVelocity(rightSpeed);
            wheels[1]->setVelocity(rightSpeed);
            break;
          }
          case Keyboard.RIGHT:
          { double leftSpeed = 1.0;
            double rightSpeed = -1.0;
            wheels[0]->setVelocity(leftSpeed);
            wheels[2]->setVelocity(leftSpeed);
            wheels[3]->setVelocity(rightSpeed);
            wheels[1]->setVelocity(rightSpeed);
            break;
          }
          default:
           { double leftSpeed = 0.0;
            double rightSpeed = 0.0;
            wheels[0]->setVelocity(leftSpeed);
            wheels[1]->setVelocity(rightSpeed);
            wheels[2]->setVelocity(leftSpeed);
            wheels[3]->setVelocity(rightSpeed);
            break;  
           }      
   } 
   
   enteredKeys->disable();
   //logic to move front 
   /* */
    
    //logic to go back
   /* */
    
    
    
    //wheels[2]->setVelocity(leftSpeed);
    //wheels[3]->setVelocity(rightSpeed);
  
    // Read the sensors:
    // Enter here functions to read sensor data, like:
    //  double val = ds->getValue();

    // Process sensor data here.

    // Enter here functions to send actuator commands, like:
    //  motor->setPosition(10.0);
  };

  // Enter here exit cleanup code.

  delete robot;
  return 0;
}
