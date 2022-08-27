/*
 * These are the only things you should have to change for using it on your own design
 *
 * To determine the degrees per step, take the degrees per step for the motor (usually 1.8 degrees for a 200 step/rev
 * motor) and multiply it by the gear ratio. In my case, it was 1.8*(1/4.1) which gives 0.43 steps per degree.
 * To avoid floats, the code uses hundredths of degrees (ie 1 degree would be 100).
 */

#ifndef _ROTORPARAM_H
#define _ROTORPARAM_H

//Change these to match your specific rotor/steppers
//To avoid floats this is in 100th of a degree (deg*100)
#define AZ_DEG_PER_STEP 43 //(deg*100)
#define EL_DEG_PER_STEP 6 //(deg*100)

//Currently not used, however this is simply 1/(x/100) of the above
#define AZ_STEPS_PER_DEG 2.389
#define EL_STEPS_PER_DEG 16.66



//Change these to match your electrical setup
#define AZ_STEP_PIN 9
#define AZ_DIR_PIN 4

#define EL_STEP_PIN 3
#define EL_DIR_PIN 2

#define EL_HOME_PIN_DIG 7 //Digital home pin
#define EL_HOME_PIN_ANL A0 //Analog home pin

#define AZ_HOME_PIN_DIG 8  //Digital home pin
#define AZ_HOME_PIN_ANL A1 //Analog home pin

#define INVERT_DIG_HOME 0 //0: Home switch high when at home, 1: Home switch low when at home
#define ANALOG_HOME_VAL 700 // A2D value above which the sensor is considered at home

#define POS_HYST 80 //Hysteresis (deg*100)
#define HOME_MAX_MOVEMENT 7000 //Maximum movement during homing (deg*100)

//For future development
#define USE_ACCEL_4_ELE 0 //Use i2c accelerometer for elevation
#define USE_COMP_4_AZI 0 //Use i2c compass for azimuth


//home


#endif
