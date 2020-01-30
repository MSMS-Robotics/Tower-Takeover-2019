/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    20, 11, 2       
// LeftFourbar          motor         10              
// RightFourbar         motor         1               
// Claw                 motor         13              
// ULFB                 motor         3               
// URFB                 motor         9               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}


void ClawSequence(void) {
  
  
  }
  
// }
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
void LeftBottom(void) {
  Claw.setPosition(0,degrees);
  //Start at bottom of A2
  Drivetrain.setDriveVelocity(100,percent);
  Drivetrain.driveFor(forward,29,inches);
  Drivetrain.stop();

  //move forward to purple block
  //pick up purple block
  //move backwards to close to wall
  //turn 90 degrees clockwise
  //move forward to corner
  //drop cubes
}
void LeftTop(void) {
  //Start between A3 and A4
  //move forward to orange block
  //pick up orange block
  //move backwards until aligned with wall
  //rotate 90 degrees counter-clockwise
  //move forward to corner
  //drop cubes
}
void RightBottom(void) {
  //Start at bottom of F2
  //move forward to purple block
  //pick up purple block
  //move backwards to close to wall
  //turn 90 degrees counter-clockwise
  //move forward to corner
  //drop cubes
}
void RightTop(void) {
  //Start between F3 and F4
  //move forward to green block
  //pick up green block
  //move backwards until aligned with wall
  //rotate 90 degrees clockwise
  //move forward to corner
  //drop cubes
}
void autonomous(void) {
  
  LeftFourbar.spin(forward,50, pct);
  RightFourbar.spin(forward,50, pct);
  ULFB.spin(forward,50, pct);
  URFB.spin(forward,50, pct);

  wait(400,msec);
  LeftFourbar.setStopping(hold);
  RightFourbar.setStopping(hold);
  ULFB.setStopping(hold);
  URFB.setStopping(hold);
  LeftFourbar.stop();
  RightFourbar.stop();
  ULFB.stop();
  URFB.stop();
  wait(2000,msec);

  Claw.spinFor(forward,90,degrees);
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {

    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
