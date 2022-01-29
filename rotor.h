#ifndef _ROTOR_H
#define _ROTOR_H

#include <stdint.h>
#include <Arduino.h>
#include "rotorParams.h"

//Axis definitions
#define AZI 1
#define ELE 2

//Direction
#define CCW 1
#define CW 2
#define STOP 0

//Status
#define ERR 255
#define INIT 0
#define HOME_1 1
#define HOME_2 2
#define HOME_3 3
#define HOME_4 4
#define READY 5

//Modes
#define MOVE_R_U 3
#define MOVE_L_D 2
#define MOVE_TO 1
#define MOVE_STOP 0

//speeds
#define SLOW 1
#define MED 2
#define FAST 3
#define FULL 4

//home types
#define ANALOG_HOME 2
#define DIGITAL_HOME 1
#define NO_HOME 0


class Rotor {


    public:
    Rotor(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
    Rotor(uint8_t);
    void setPos(long);
    void setMeasPos(long);
    void setSpd(int);
    void setMode(int);
    long getPos();
    long getMeasPos();
    long getTgtPos();
    int getMode();
    int getStatus();
    void goHome();
    int isHome();
    void doStep();

    
    
  private:
    uint8_t ax;
    uint8_t stepPin;
    uint8_t dirPin;
    uint8_t homePin;
    int degPerStep;
    int homeType;

    long currPos;
    long desPos;
    long measPos;
    uint8_t dir;
    uint8_t stp;

    uint8_t stat;
    uint8_t mode;

    uint8_t spd;
    uint8_t delCntr;
};


#endif
