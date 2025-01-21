#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftgripper,   tmotorServoStandard, openLoop)
#pragma config(Motor,  port4,           rightgripper,  tmotorServoStandard, openLoop)
#pragma config(Motor,  port6,           armMotor,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port9,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                                - ADVANCED Single Joystick Control -                                *|
|*                                      ROBOTC on VEX 2.0 Cortex                                      *|
|*                                                                                                    *|
|*  This program uses a single joystick, either right or left (this is configurable below) to drive   *|
|*  the robot.                                                                                        *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Ch1 is the X axis and Ch2 is the Y axis for the RIGHT joystick.                             *|
|*    2)  Ch3 is the Y axis and Ch4 is the X axis for the LEFT joystick.                              *|
|*    3)  'abs(z)' is the ABSOLUTE VALUE of 'z'.                                                      *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]              [Name]              [Type]              [Description]                   *|
|*    Motor - Port 2          rightMotor           VEX Motor           Right motor                    *|
|*    Motor - Port 9          leftMotor            VEX Motor           Left motor                     *|
\*----------------------------------------------------------------------------------------------------*/

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main ()
{
  //int joy_x;            // will hold the X value of the analog stick (choices below)
  //int joy_y;            // will hold the Y value of the analog stick (choices below)
  int threshold = 10;   // helps to eliminate 'noise' from a joystick that isn't perfectly at (0,0)

  while(1 == 1)
  {

    if(abs(vexRT[Ch3]) > threshold)         // If the left joystick is greater than or less than the threshold:
    {
      motor[leftMotor]  = (vexRT[Ch3])/2;   // Left Joystick Y value / 2.
    }
    else                                    // If the left joystick is within the threshold:
    {
      motor[leftMotor]  = 0;                // Stop the left motor (cancel noise)
    }

    if(abs(vexRT[Ch2]) > threshold)         // If the right joystick is greater than or less than the threshold:
    {
      motor[rightMotor] = (vexRT[Ch2])/2;   // Right Joystick Y value / 2.
    }
    else                                    // If the right joystick is within the threshold:
    {
      motor[rightMotor] = 0;                // Stop the right motor (cancel noise) }
  }

    //Gripper Control

		if(vexRT[Btn5U] == 1)  // open corn biggest
		{
			motor[leftgripper] = 270;
			motor[rightgripper] = -270;
		}
		if(vexRT[Btn5D] == 1) // close corn
		{
			motor[leftgripper] = 0;
			motor[rightgripper] = 0;
		}
		if(vexRT[Btn8U] == 1) // open tomato
		{
			motor[leftgripper] = 80;
			motor[rightgripper] = -80;
		}
		if(vexRT[Btn8D] == 1) // close tomato
		{
			motor[leftgripper] = 30;
			motor[rightgripper] = -30;
		}



		//Arm Control
		if(vexRT[Btn6U] == 1)
		{
			motor[armMotor] = 60;
		}
		else if(vexRT[Btn6D] == 1)
		{
			motor[armMotor] = -60;
		}
		else
		{
			motor[armMotor] = 0;  //stop moving
		}
  }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
