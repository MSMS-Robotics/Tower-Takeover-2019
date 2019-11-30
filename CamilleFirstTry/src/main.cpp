/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
#include "math.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Eyes                 vision        9               
// RMotor               motor         1               
// LMotor               motor         11              
// LArmMotor            motor         20              
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----


using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
//                         Functions

// Makes the program go to sleep
void Sleep (int time) {
  vex::task::sleep(time);
}

void DriveForward (int distance, float wheelDiameter = 4, float speed = 50) {
  float circumference = M_PI * wheelDiameter;
  float degrees = circumference / 360;
  LMotor.setVelocity(speed, pct);
  
}

/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
LMotor.spin(vex::directionType::fwd, 50, pct);
RMotor.spin(vex::directionType::fwd, 50, pct);
Sleep(1000);
LMotor.spin(vex::directionType::fwd, 50, pct);
RMotor.spin(vex::directionType::rev, 50, pct);
Sleep(550);
LMotor.spin(vex::directionType::fwd, 50, pct);
RMotor.spin(vex::directionType::fwd, 50, pct);
Sleep(1000);
LMotor.spin(vex::directionType::fwd, 50, pct);
RMotor.spin(vex::directionType::rev, 50, pct);
Sleep(550);
LMotor.spin(vex::directionType::fwd, 50, pct);
RMotor.spin(vex::directionType::fwd, 50, pct);
Sleep(1000);
LMotor.spin(vex::directionType::fwd, 50, pct);
RMotor.spin(vex::directionType::rev, 50, pct);
Sleep(550);
LMotor.spin(vex::directionType::fwd, 50, pct);
RMotor.spin(vex::directionType::fwd, 50, pct);
Sleep(1000);
LMotor.spin(vex::directionType::fwd, 50, pct);
RMotor.spin(vex::directionType::rev, 50, pct);
Sleep(550);
LMotor.stop();
RMotor.stop();



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
  Brain.Screen.print("Not Gonna make it to dinner");  
  while (1) {
    //drivecontrol set to joysticks
    LMotor.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
    RMotor.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);

      //sets the tail to d-pad controls left and right 
    if (Controller1.ButtonRight.pressing()){
      LArmMotor.spin(fwd, 50, pct);
    }
    else if (Controller1.ButtonLeft.pressing()) {
      LArmMotor.spin(directionType::rev, 50, pct); 
    }
    else {
     LArmMotor.stop(); 
    }
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
