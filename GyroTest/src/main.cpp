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
// LFB                  motor         10              
// RFB                  motor         1               
// clawMotor            motor         13              
// leftMotor            motor         20              
// rightMotor           motor         11              
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
void LeftBottom(void) {
  //Start at bottom of A2
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
int speed = 0;
void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    
    // if (Controller1.ButtonA.pressing() == 1 and speed < 100){
    //   speed++;
    //   // Holding A will make the velocity increase per tick'
    //   Drivetrain.setDriveVelocity(speed,percent);
    //   Drivetrain.drive(forward);     
    
    // }else if (speed > 0){
    //   speed--;
    //   // Releasing will cause the robot to slow down every tick
    // }L
    // if (Controller1.ButtonB.pressing() == 1 and speed > -100){
    //   speed--;
    //   // Pressing B will make the velocity decrease (become more negative) every tick
    //   Drivetrain.setDriveVelocity(speed,percent);
    //   Drivetrain.drive(forward);
    // }
    // else if (speed < 0){
    //   speed++;
    //   // Releasing will cause the robot to slow down every tick
    // }
    Controller1.Screen.clearScreen();
    Brain.Screen.clearScreen();
    if(Controller1.Axis3.position(percent) > 20 and Controller1.Axis2.position(percent)>20){
      leftMotor.setVelocity(Controller1.Axis3.position(percent)-20,percent);
      rightMotor.setVelocity(Controller1.Axis2.position(percent)-20,percent);
    }else if(Controller1.Axis3.position(percent) < -20 and Controller1.Axis2.position(percent)<-20){
      leftMotor.setVelocity(Controller1.Axis3.position(percent)+20,percent);
      rightMotor.setVelocity(Controller1.Axis2.position(percent)+20,percent);
    }else{
      leftMotor.setVelocity(Controller1.Axis3.position(percent),percent);
      rightMotor.setVelocity(Controller1.Axis2.position(percent),percent);
    }
    

    leftMotor.spin(forward);
    rightMotor.spin(forward);
    
    if (Controller1.ButtonUp.pressing() == 1 and Controller1.ButtonDown.pressing() != 1){ // These IF statements control the motion of the four-bar
      LFB.setVelocity(70, percent);
      RFB.setVelocity(70, percent);
      ULFB.setVelocity(35,percent);
      URFB.setVelocity(35,percent);
      LFB.spin(forward);
      RFB.spin(forward);
      ULFB.spin(forward);
      URFB.spin(forward);
    }
    else if (Controller1.ButtonUp.pressing() != 1 and Controller1.ButtonDown.pressing() == 1){
      LFB.setVelocity(-30, percent);
      RFB.setVelocity(-30, percent);
      ULFB.setVelocity(-15,percent);
      URFB.setVelocity(-15,percent);
      LFB.spin(forward);
      RFB.spin(forward);
      ULFB.spin(forward);
      URFB.spin(forward);
    }
    else{
      LFB.setStopping(hold);
      RFB.setStopping(hold);
      ULFB.setStopping(hold);
      URFB.setStopping(hold);
      LFB.stop();
      RFB.stop();
      ULFB.stop();
      URFB.stop();
    }
    if (Controller1.ButtonL1.pressing() == 1 and clawMotor.position(degrees)<30){ // These IF statements control the motion of the conveyor belt
      clawMotor.setVelocity(60,rpm);
      clawMotor.spin(forward);
    }else if (Controller1.ButtonR1.pressing()==1){
      clawMotor.setVelocity(60,rpm);
      clawMotor.spin(reverse);
    }
    else{
      clawMotor.setStopping(hold);
      clawMotor.stop();
    }
    Brain.Screen.print(LFB.position(degrees));
    Brain.Screen.newLine();
    Brain.Screen.print(clawMotor.position(degrees));

    
    
    
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
