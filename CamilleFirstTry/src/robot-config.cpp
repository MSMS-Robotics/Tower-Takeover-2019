#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
/*vex-vision-config:begin*/
signature Eyes__SIG_1 = signature (1, -2979, -2103, -2540, 5385, 6937, 6162, 2.5, 0);
signature Eyes__SIG_2 = signature (2, 0, 0, 0, 0, 0, 0, 3, 0);
signature Eyes__SIG_3 = signature (3, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Eyes__SIG_4 = signature (4, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Eyes__SIG_5 = signature (5, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Eyes__SIG_6 = signature (6, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Eyes__SIG_7 = signature (7, 0, 0, 0, 0, 0, 0, 2.5, 0);
vision Eyes = vision (PORT9, 50, Eyes__SIG_1, Eyes__SIG_2, Eyes__SIG_3, Eyes__SIG_4, Eyes__SIG_5, Eyes__SIG_6, Eyes__SIG_7);
/*vex-vision-config:end*/
motor RMotor = motor(PORT1, ratio18_1, false);
motor LMotor = motor(PORT11, ratio18_1, true);
motor LArmMotor = motor(PORT20, ratio18_1, false);
controller Controller1 = controller(primary);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}