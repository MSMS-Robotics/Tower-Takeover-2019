#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LFB = motor(PORT10, ratio18_1, true);
motor RFB = motor(PORT1, ratio18_1, false);
motor clawMotor = motor(PORT13, ratio18_1, true);
motor leftMotor = motor(PORT20, ratio36_1, false);
motor rightMotor = motor(PORT11, ratio36_1, true);
motor ULFB = motor(PORT3, ratio18_1, true);
motor URFB = motor(PORT9, ratio18_1, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}