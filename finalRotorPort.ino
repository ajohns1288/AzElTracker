/*
  Project: AZ/EL Rotator Controller
  finalRotorPort.ino: Code that does gets data from uart.cpp and actuates rotor axis as defined by rotor.cpp

    Copyright (C) 2021, AJohns1288@Gmail.com

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/



#include "uart.h"
#include "rotor.h"

//Define rotor objects
Rotor az = Rotor(AZI, AZ_STEP_PIN, AZ_DIR_PIN, -1, AZ_DEG_PER_STEP);
Rotor el = Rotor(ELE, EL_STEP_PIN, EL_DIR_PIN, EL_HOME_PIN_ANL, EL_DEG_PER_STEP);

//Initialize variables
long prevMillis=0;

//Task Counters
int count5ms = 0;
int count10ms = 0;
int count20ms = 0;
int count40ms = 0;
int count1s = 0;

//Task Flags
bool task5msRun = 0;
bool task10msRun = 0;
bool task15msRun = 0;
bool task20msRun = 0;
bool task40msRun = 0;
bool task1sRun = 0;

//LED variables
int ledTmr = 0;
bool ledOn = 0;


void setup()
{
  //Enable Serial, setup pins, then home EL axis.
  enableUART();

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, 0);
  
  //Change this to match your home pin setup
  pinMode(EL_HOME_PIN_ANL, INPUT);

  el.goHome();

}

void loop()
{
  //Each loop, update the timer, read Serial for any new commands, then actuate each task as needed, ensuring to clear the flag once ran.
  //Note: You can also change movement speeds by moving axis step commands into different task rates.
  getTime();
  readUART();
  if (task5msRun)
  {
    task5msRun = 0;
    el.doStep();
  }
  if (task10msRun)
  {
    task10msRun = 0;
    parseCommand();
  }
  if (task20msRun)
  {
    task20msRun = 0;
    az.doStep();
  }
  if (task1sRun)
  {
    task1sRun = 0;
    updateLED();
  }


}

void getDebug()
{
  //Responds to a command "Q" to info to serial
  Serial.print("Az Pos:");
  Serial.println(az.getPos(), DEC);
  Serial.print("El Pos:");
  Serial.println(el.getPos(), DEC);
    Serial.print("Az Tgt:");
  Serial.println(az.getTgtPos(), DEC);
  Serial.print("El Tgt:");
  Serial.println(el.getTgtPos(), DEC);
  Serial.print("Az Mode:");
  Serial.println(az.getMode(), DEC);
  Serial.print("El Mode:");
  Serial.println(el.getMode(), DEC);
    Serial.print("Az Status:");
  Serial.println(az.getStatus(), DEC);
  Serial.print("El Status:");
  Serial.println(el.getStatus(), DEC);
}

void updateLED()
{
  //Function to light the LED to display status
  //Off: Initialization
  //On Solid: Ready, stopped
  //Slow blink: In auto move mode
  //Medium blink: In homing mode
  //Fast Blink: Error
  if (el.getStatus() == ERR)
  {
    ledOn = !ledOn;
    digitalWrite(LED_BUILTIN, ledOn);
  }
  else if (az.getMode() == MOVE_STOP && el.getMode() == MOVE_STOP)
  {
    digitalWrite(LED_BUILTIN, 1);
    ledOn = true;
  }
  else if (el.getStatus() < READY)
  {
    if (ledTmr % 2 == 0)
    {
      ledOn = !ledOn;
      digitalWrite(LED_BUILTIN, ledOn);
    }
  }
  else
  {
    if (ledTmr % 8 == 0)
    {
      ledOn = !ledOn;
      digitalWrite(LED_BUILTIN, ledOn);
    }
  }
  ledTmr++;



}

void getTime()
{
  //Task scheduler, if enough time passes, set flags for functions to run.
  long curMillis = millis();
  if ((curMillis - prevMillis) >= 5)
  {
    task5msRun = 1;
    count5ms++;
    prevMillis = curMillis;


    if ((count5ms % 2) == 0)
    {
      task10msRun = 1;
      count10ms++;
    }
    if ((count5ms % 4) == 0)
    {
      task20msRun = 1;
      count20ms++;
    }
    if ((count5ms % 10) == 0)
    {
      task40msRun = 1;
      count40ms++;
    }
    if ((count5ms % 50) == 0)
    {
      task1sRun = 1;
      count1s++;
    }
  }


}


void parseCommand()
{
  char buf[31];
  char c = getCommand(buf);
  long desAz, desEl, desSpd;

  //Flag to determine if 0x0D is sent in response (GS232 Protocol)
  bool respond = false;

  //get command, if valid command, actuate command
  switch (c)
  {
      
    case CMD_MOVETO:
      //ASCII to hex
      desAz = ((100 * (buf[0] - '0')) + (10 * (buf[1] - '0')) + (buf[2] - '0'));
      desEl = ((100 * (buf[4] - '0')) + (10 * (buf[5] - '0')) + (buf[6] - '0'));
      //Scale angle to x100 for better resolution
      az.setPos(desAz * 100);
      el.setPos(desEl * 100);
      //start the move
      az.setMode(MOVE_TO);
      el.setMode(MOVE_TO);
      respond = true;
      break;
    case CMD_SPEED:
      desSpd = 100 * (buf[0] - '0');
      (desSpd > 4 | desSpd < 0) ? desSpd = 4 : desSpd;
      az.setSpd(desSpd);
      //el.setSpd(desSpd); //NOTE: GS232 Protocol only changes speed on azimuth. This can be changed
      respond = true;
      break;
    case CMD_STOP:
      az.setMode(MOVE_STOP);
      el.setMode(MOVE_STOP);
      respond = true;
      break;
    case CMD_STOP_AZ:
      az.setMode(MOVE_STOP);
      respond = true;
      break;
    case CMD_STOP_EL:
      el.setMode(MOVE_STOP);
      respond = true;
      break;
    case CMD_D:
      el.setMode(MOVE_L_D);
      respond = true;
      break;
    case CMD_L:
      az.setMode(MOVE_L_D);
      respond = true;
      break;
    case CMD_U:
      el.setMode(MOVE_R_U);
      respond = true;
      break;
    case CMD_R:
      az.setMode(MOVE_R_U);
      respond = true;
      break;
    case CMD_DEBUG:
      getDebug();
      break;
    case CMD_GET_AZ:
      if (buf[0] == '2')
      {
        //C displays just AZ, C2 is command to display both
        outputAngle(az.getPos(), false);
        outputAngle(el.getPos(), true);
      }
      else
      {
        outputAngle(az.getPos(), true);
      }
      break;
    case CMD_GET_EL:
      outputAngle(el.getPos(), true);
      break;
    case CMD_NULL:
    //Invalid command, do nothing
      break;
  }

  if (respond)
  {
    Serial.write(0x0D);
  }
}
