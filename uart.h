#ifndef UART_H
#define UART_H
#include <Arduino.h>

//Command enumerations based on GS232 Protocol
//works with rotctld -m 606 command on linux 
#define CMD_R 'R'
#define CMD_L 'L'
#define CMD_U 'U'
#define CMD_D 'D'
#define CMD_STOP 'S'
#define CMD_STOP_AZ 'A'
#define CMD_STOP_EL 'E'
#define CMD_SPEED 'X'
#define CMD_SET_HOME 'F'
#define CMD_MOVETO_AZ 'M'
#define CMD_MOVETO 'W'
#define CMD_GET_AZ 'C'
#define CMD_GET_EL 'B'

#define CMD_NULL 0

//Non-Standard GS232 Commands, may or may not be implemented
#define CMD_DEBUG 'Q'
#define CMD_PARK 'P'

//Timeout in loops, if EOL char not rec'd, then cancel reception
#define CMD_TIMEOUT 20000

//EOL char '\l'
#define EOL 0x0D


char getCommand(char*);
void enableUART(void);
void readUART(void);
void outputAngle(long,bool);


#endif
