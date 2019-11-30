#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LeftDriveSmart = motor(PORT1, ratio18_1, false);
motor RightDriveSmart = motor(PORT10, ratio18_1, true);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 130, mm, 1);
/*vex-vision-config:begin*/
signature Eyes__RED_CUBE = signature (1, 12393, 13353, 12874, -3475, -3065, -3270, 3, 0);
signature Eyes__SIG_2 = signature (2, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Eyes__SIG_3 = signature (3, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Eyes__SIG_4 = signature (4, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Eyes__SIG_5 = signature (5, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Eyes__SIG_6 = signature (6, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Eyes__SIG_7 = signature (7, 0, 0, 0, 0, 0, 0, 2.5, 0);
vision Eyes = vision (PORT3, 50, Eyes__RED_CUBE, Eyes__SIG_2, Eyes__SIG_3, Eyes__SIG_4, Eyes__SIG_5, Eyes__SIG_6, Eyes__SIG_7);
/*vex-vision-config:end*/

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}