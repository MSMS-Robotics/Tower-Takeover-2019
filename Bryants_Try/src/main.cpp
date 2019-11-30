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
// Drivetrain           drivetrain    1, 10           
// Eyes                 vision        3               
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
  Brain.Screen.drawCircle(50,50,50);
  while (true) {
    
    if(Eyes.takeSnapshot(Eyes__RED_CUBE)==1){
      Brain.Screen.print("EXISST!!!");
    }
    else {
      Brain.Screen.print("bloop");
    }

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
    //Brain.Screen.clearScreen();
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

  while (true) {
    const int DRIVE_SPEED = 55; // Drivetrain speed while going to cube
    const int TURN_SPEED = 25; // Drivetrain speed while turning towards cube

    if(Eyes.takeSnapshot(Eyes__RED_CUBE) && Eyes.objects[0].width < 200){
      Brain.Screen.setCursor(1,1);
      Brain.Screen.print("RED_CUBE Location:");
      if(Eyes.objects[0].centerX > 140){
        Drivetrain.setTurnVelocity(TURN_SPEED, percent);
        Brain.Screen.setCursor(2,1);
        Brain.Screen.clearLine();
        Brain.Screen.print("Right");
        Drivetrain.turn(right);
      }
      else if (Eyes.objects[0].centerX < 80){
        Drivetrain.setTurnVelocity(TURN_SPEED, percent);
        Brain.Screen.setCursor(2,1);
        Brain.Screen.clearLine();
        Brain.Screen.print("Left");
        Drivetrain.turn(left);
      }
      else if (Eyes.objects[0].centerX > 90 && Eyes.objects[0].centerX < 130){
        Drivetrain.setDriveVelocity(DRIVE_SPEED, percent);
        Brain.Screen.setCursor(2,1);
        Brain.Screen.clearLine();
        Brain.Screen.print("Center");
        Drivetrain.drive(forward);
      }
      
    }
    else{
      Brain.Screen.setCursor(1,1);
      Brain.Screen.print("RED_CUBE Location:");
      Brain.Screen.setCursor(2,1);
      Brain.Screen.clearLine();
      Brain.Screen.print("N/A");
      Drivetrain.stop();
    }

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
    //Brain.Screen.clearLine();
  }

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
