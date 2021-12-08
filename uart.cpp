/*
  Project: AZ/EL Rotator Controller
  uart.cpp: Code that deals with UART/Serial transmissions. Code is seprated so other protocls could be added. 

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

#include "Arduino.h"
#include "uart.h"


static char strBuf[32];
static int strIndex;
static boolean dataRecd;
static boolean dataComplete;



void enableUART()
{
  dataRecd = false;
  dataComplete = false;
  strIndex = 0;
  Serial.begin(9600);
}


char getCommand(char* b)
{
  char tmpCmd = CMD_NULL;

  //If we rec'd EOL, set command to first char, clear flag, load UART buffer into b, otherwise return null.
  if (dataComplete)
  {
    
    
    tmpCmd = strBuf[0];
    dataComplete = false;
    for (int i = 0; i < 32; i++)
    {
      b[i] = strBuf[i + 1];
      if (strBuf[i + 1] == EOL)
      {
        break;
      }
    }

  }
  return tmpCmd;
}

void readUART()
{
  while (Serial.available())
  {
    char tmp;
    
    // Get receive input
    tmp = Serial.read();
    strBuf[strIndex] = tmp;
    dataRecd = true;
    //Terminal will send carraige return, this marks end of data.
    if (tmp == EOL)
    {
      strIndex = 0;
      //Ensure buffer is clear
      Serial.read();
      Serial.read();
      //Clear flags
      dataRecd = false;
      dataComplete = true;
    }
    else if(strIndex>30)
    {
      strBuf[0]=CMD_NULL;
      strIndex=1;
    }
    else
    {
      strIndex++;
    }

  }

}

void outputAngle(long ang,bool newline)
{
  //transmit ang in ASCII in format +000
  
  ang=ang/100; //rescale

  Serial.print('+');
  Serial.print('0');
  if(ang<10)
  {
    Serial.print('0');
  }
  if(ang<100)
  {
    Serial.print('0');
  }

  Serial.print(ang,DEC);
  
  if(newline)
  {
    Serial.write(EOL);
    Serial.write(0x0A);
  }

}
