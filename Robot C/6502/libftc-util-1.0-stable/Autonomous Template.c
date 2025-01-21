#pragma config(Sensor, S3,     ,                    sensorI2CHiTechnicGyro)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
Copyright (C) 2011 by Pope John XXIII Robotics Team

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

///////////////////////////////////////////////////////////
// CONFIG
///////////////////////////////////////////////////////////
const bool HAS_GYRO = true;
const bool HAS_ACCEL = false;
const tSensors gyroPort = S3;
const tSensors accelPort = S2;

// leftSide and rightSide are the two functions which you must create. They must be written by you, since they depend on your robot.
void leftSide(int val){
}

void rightSide(int val){
}

#include "libftc-util.c"

// This function is called before you start the match. Initalize your servos here.
void initialize(){
  libftc_init();
  // servo[servoA] = blah....
}

task main(){
  initialize();
  waitForStart();
  // Do autonomous stuff.
  // e.x: libftc_gyroForwardForTimeAndStop(power,time);
}
