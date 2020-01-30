using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor LFB;
extern motor RFB;
extern motor clawMotor;
extern motor leftMotor;
extern motor rightMotor;
extern motor ULFB;
extern motor URFB;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );