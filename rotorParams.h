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

#define EL_HOME_PIN_DIG 7 //Digital home pin
#define EL_HOME_PIN_ANL A0 //Analog home pin
#define INVERT_DIG_HOME 0 //0: Home switch high when at home, 1: Home switch low when at home
#define ANALOG_HOME_VAL 700


#define POS_HYST 80 //Hysteresis (deg*100)
#define HOME_MAX_MOVEMENT 7000 //Maximum movement during homing (deg*100)


//home


#endif
