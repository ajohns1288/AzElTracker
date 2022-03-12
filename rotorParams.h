/*
 * These are the only things you should have to change for using it on your own design
 */

#ifndef _ROTORPARAM_H
#define _ROTORPARAM_H

//Change these to match your specific rotor
#define AZ_DEG_PER_STEP 43
#define EL_DEG_PER_STEP 6
#define AZ_STEPS_PER_DEG 2.389
#define EL_STEPS_PER_DEG 16.66

//Change these to match your electrical setup
#define AZ_STEP_PIN 9
#define AZ_DIR_PIN 4
#define EL_STEP_PIN 3
#define EL_DIR_PIN 2

//These are settings for the home sensors. You may need to change these to get homing working correctly based on the specific sensor used.
//NOTE: Hall effect sensors are sensitive to which magnetic pole is present.
#define EL_HOME_PIN_DIG 7 //Digital home pin
#define EL_HOME_PIN_ANL A0 //Analog home pin
#define INVERT_DIG_HOME 0 //Used to account for different sensor styles/pullups. 0: Home switch high when at home, 1: Home switch low when at home
#define ANALOG_HOME_VAL 700 //A2D value above which the rotor is considered "homed"


#define POS_HYST 80 //Hysteresis (deg*100), default is 0.8 deg. If the commanded position is within this amount of the actual, no movement is made.
#define HOME_MAX_MOVEMENT 7000 //Maximum movement during homing (deg*100). Default is 70 degrees. This is used to prevent the rotor from over extending if home switch is missing.


//home


#endif
