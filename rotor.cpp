/*
  Project: AZ/EL Rotator Controller
  rotor.cpp: Code that defines the Rotor class. Each axis exists as an object with the methods below.

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

#include "rotor.h"

Rotor::Rotor(uint8_t axis, uint8_t sp, uint8_t dp, uint8_t hp, uint8_t degStep)
{
  
  //Initialize instance variables
  ax = axis;
  stepPin = sp;
  dirPin = dp;
  homePin = hp;
  degPerStep = degStep;

  //Set up home type based on pin
  //TODO: Check on range for Analog and digital, better default behavior...
  if (hp == -1)
  {
    homeType = NO_HOME;
  }
  else if (hp >= A0)
  {
    homeType = ANALOG_HOME;
  }
  else
  {
    homeType = DIGITAL_HOME;
  }

  //Initialize positions to zero, other state variables as needed
  currPos = 0;
  desPos = 0;
  dir = 0;
  stp = 0;

  stat = INIT;
  mode = MOVE_STOP;
  spd = FULL;
  delCntr = FULL;

  //Set up pins
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(homePin, INPUT);
}

void Rotor::setPos(long ang)
{
  //Sets the desired angle
  desPos = ang;
}

void Rotor::setSpd(int ang)
{
  //Sets the desired speed (1-4)
  spd = ang;
}

void Rotor::setMode(int ang)
{
  //Sets the desired movement mode
  mode = ang;
}

int Rotor::getMode()
{
  //Gets the current movement mode
  return mode;
}

int Rotor::getStatus()
{
  //Gets the current status
  return stat;
}

long Rotor::getPos()
{
  //Gets the current position
  return currPos;
}

long Rotor::getTgtPos()
{
  //Gets the target position
  return desPos;
}

void Rotor::goHome()
{
  //If we are already home or dont have home switch, just take current position as home
  if (homeType = NO_HOME || isHome())
  {
    stat = READY;
    currPos = 0;
  }
  
  else
  {
    //Otherwise, start moving down/left and set HOME_1 status
    mode = MOVE_L_D;
    stat = HOME_1;
  }

}

int Rotor::isHome()
{
  //Returns analog or digital home sensor based on pin chosen and if switch is active high or low.
  bool tmp = 0;
  if (homeType = NO_HOME)
  {
    return -1;
  }
  else if (homeType == DIGITAL_HOME)
  {
    tmp = digitalRead(homePin);
  }
  else
  {
    tmp = (analogRead(homePin)> ANALOG_HOME_VAL);
  }

  if (INVERT_DIG_HOME)
  {
    tmp = !tmp;
  }
  return tmp;
}

void Rotor::doStep()
{

  if(stat==ERR)
  {
    //If we error out, we shouldn't allow movement
    return;
  }
  
  //Find the delta between desired and current
  long delPos = desPos - currPos;
  int OKToMove = 0;
 
  //Wrap angle to less than 180 for quickest path
  if (delPos > 18000)
  {
    delPos = -(36000 - delPos);
  }
  else if (delPos < -18000)
  {
    delPos = 36000 + delPos;
  }

  //if we arent ready, stay in home mode until we've had 2 loops at home, then look for the upper edge and reverse halfway
  // Homing states:
  // HOME_1: Initial Homing State
  // HOME_2: Confirm lower homing switch hit
  // HOME_3: Lower limit found, testing upper limit
  // HOME_4: Upper limit found, moving to halfway between limits
  // READY: Zeroed to middle of homing range
  if (stat < READY && stat > INIT)
  {
    switch (stat)
    {
      case HOME_1:
        if (isHome())
        {
          stat = HOME_2;
          spd=SLOW;
        }
        else
        {
          //This will prevent the homing routine from running over 90deg, which can happen if home switch not sensing
          if(currPos<(36000-HOME_MAX_MOVEMENT)&&currPos>0)
          {
            stat=ERR;
            mode = MOVE_STOP;
            Serial.println("Homing timout - reset module");
          }
        }
        break;
      case HOME_2:
       if (isHome())
        {
          stat = HOME_3;
          currPos=0;
        }
        else
        {
          stat = HOME_1;
        }
      break;
      case HOME_3:
        if (isHome())
        {
          //keep moving until we don't see home switch anymore
        }
        else
        {
          //Set our desired position to half the distance between the home switch on and switch off
          desPos=(36000-currPos)/2;
          currPos=0;
          mode = MOVE_TO;
          stat = HOME_4;
        }
      break;
      case HOME_4:
        if (abs(delPos)<POS_HYST)
        {
          //Once we reach position we are home
          mode = MOVE_STOP;
          stat = READY;
          spd=FULL;
          currPos=0;
          desPos=0;
        }
        else
        {
          //keep moving
        }
      break;
    }
  }

  //Set Direction depending on mode
  switch (mode)
  {
    case MOVE_STOP:
      break;

    case MOVE_R_U:
      dir = CW;
      OKToMove = 1;
      break;

    case MOVE_L_D:
      dir = CCW;
      OKToMove = 1;
      break;

    case MOVE_TO:
      //If positive delta, move right/CW, otherwise left
      OKToMove = abs(delPos) > POS_HYST;
      if (delPos > 0)
      {
        dir = CW;
      }
      else
      {
        dir = CCW;
      }
      break;
  }

  //set DIR pin based on direction desired
  if (dir == CW)
  {
    digitalWrite(dirPin, 1);
  }
  else
  {
    digitalWrite(dirPin, 0);
  }

  //If we are OK to move and speed delay is OK, toggle step pin
  if (((delCntr) <= (spd)) && OKToMove)
  {
    delCntr = 4;


    if (stp == 0)
    {
      digitalWrite(stepPin, 1);
      stp = 1;
    }
    else
    {
      digitalWrite(stepPin, 0);
      //calculate position on release of step pin, wrap to 0-360
      if (dir == CW)
      {
        currPos += degPerStep;
        if (currPos > 36000)
        {
          currPos -= 36000;
        }
      }
      else
      {
        currPos -= degPerStep;
        if (currPos < 0)
        {
          currPos += 36000;
        }
      }
      stp = 0;
    }
  }
  //if we're OK to move but speed delay has not expired, dec speed counter
  else if (OKToMove)
  {
    (delCntr)--;
  }

}
