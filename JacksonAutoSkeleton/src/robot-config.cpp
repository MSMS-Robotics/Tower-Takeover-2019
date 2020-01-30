#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LeftDriveSmart = motor(PORT20, ratio18_1, false);
motor RightDriveSmart = motor(PORT11, ratio18_1, true);
inertial TurnGyroSmart = inertial(PORT2);
smartdrive Drivetrain= smartdrive(LeftDriveSmart, RightDriveSmart, TurnGyroSmart,319.19, 320, 165, mm, 1);
motor LeftFourbar = motor(PORT10, ratio36_1, true);
motor RightFourbar = motor(PORT1, ratio36_1, false);
motor Claw = motor(PORT13, ratio18_1, false);
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
  Brain.Screen.print("Device initialization...");
  Brain.Screen.setCursor(2, 1);
  // calibrate the drivetrain gyro
  wait(200, msec);
  TurnGyroSmart.calibrate();
  Brain.Screen.print("Calibrating Gyro for Drivetrain");
  // wait for the gyro calibration process to finish
  while (TurnGyroSmart.isCalibrating()) {
    wait(25, msec);
  }
  // reset the screen now that the calibration is complete
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1,1);
  wait(50, msec);
  Brain.Screen.clearScreen();
}