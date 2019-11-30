using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern drivetrain Drivetrain;
extern signature Eyes__RED_CUBE;
extern signature Eyes__SIG_2;
extern signature Eyes__SIG_3;
extern signature Eyes__SIG_4;
extern signature Eyes__SIG_5;
extern signature Eyes__SIG_6;
extern signature Eyes__SIG_7;
extern vision Eyes;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );