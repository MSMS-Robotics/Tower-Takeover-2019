using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern signature Eyes__SIG_1;
extern signature Eyes__SIG_2;
extern signature Eyes__SIG_3;
extern signature Eyes__SIG_4;
extern signature Eyes__SIG_5;
extern signature Eyes__SIG_6;
extern signature Eyes__SIG_7;
extern vision Eyes;
extern motor RMotor;
extern motor LMotor;
extern motor LArmMotor;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );