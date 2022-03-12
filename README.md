# AzElTracker
Arduino firmware to control https://www.thingiverse.com/thing:4664558, designed by jbyrns

This project started as a class project and was designed to be compatible (enough) to work with gPredict/rotctrld. It seems to run pretty well.

## Items Needed
1x Arduino Nano or equivalent

2x A4988 Stepper Boards

2x Stepper Motors

1x Small Magnet

1x Hall effect switch


## How it works
1: At startup, the azimuth is assumed to be due north (0deg) and the elevation runs a homing routine

2: Once homed, serial port is polled for commands from external program.

3: Rotors can be moved indepentently as well as together. Each can rotate continously or to a set position.

See section below for implemented commands

## Hardware adaptation

Since different people might want to use the same logic but for different hardware, the hardware specific values are in the rotorParams.h file. This way, you can tailor the code to your specific application without having to change mulitple variables all over the place

## Commands
Command enumerations based on GS232 Protocol; works with 'rotctld -m 606 -r /dev/xxx' on RaspPi

CMD_R 'R' - Move right continously

CMD_L 'L' - Move left continously

CMD_U 'U' - Move up continously

CMD_D 'D' - Move down continously

CMD_STOP 'S' - Stop all axes

CMD_STOP_AZ 'A' - Stop azimuth only

CMD_STOP_EL 'E' - Stop elevation only

CMD_SPEED 'X' - Xs - Set speed to x (Azimuth only, 4: fast 1: slow)

CMD_MOVETO_AZ 'M' - Mxxx  - Moves to azimuth xxx

CMD_MOVETO 'W' - Wxxx yyy - Moves to azimuth xxx, elevation yyy

CMD_GET_AZ 'C' - Display azimuth position only (NOTE: C2 will display both axes)

CMD_GET_EL 'B' - Display elevation position only

//Non-Standard GS232 Commands

CMD_DEBUG 'Q' - Displays current positions/status/modes of rotor

CMD_SET_HOME 'F' - Unimplmented, may be used to set current position as home in future release


## Drawbacks
Stepper motors do not have feedback. If the motor stalls or skips, your position will be off

## Future Work
Implement compass/accelerometer as position sensor input.
