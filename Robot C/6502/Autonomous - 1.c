#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  HTMotor)
#pragma config(Sensor, S2,     Autonomous_Switch, sensorTouch)
#pragma config(Motor,  mtr_S1_C1_1,     rightMotor,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     leftMotor,     tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     Flag,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     Arm,           tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     Lift,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     motorI,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C3_1,    Gripper,              tServoStandard)
#pragma config(Servo,  srvo_S1_C3_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.

void initializeRobot()
{
	servo[Gripper] = 110;   // Move Gripper to closed position
	return;
}

task main()
{
	initializeRobot();

	waitForStart(); // Wait for the beginning of autonomous phase.

	  // Drive forward towards the basket
		motor[rightMotor] = 50;
		motor[leftMotor] = 50;
		wait1Msec(500);  // Drive forward for .5 seconds
		motor[rightMotor] = 0;
		motor[leftMotor] = 0;
		// Move Arm toward basket
		motor[Arm] = 30;
		wait1Msec(600);
		motor[Arm] = 0;
		// Release the block in the basket
		servo[Gripper] = 150;
		wait1Msec(200);
		motor[Arm] = -30;
		wait1Msec(300);
		// Backup a little
		motor[rightMotor] = -50;
		motor[leftMotor] = -50;
		wait1Msec(200);
		// Turns right or left depending on the touch sensor
		if(SensorValue[sensorTouch] == 1) { // If switch is pressed, turn right
			motor[rightMotor] = -50;
			motor[leftMotor] = 50;
			wait1Msec(500);
			// Goes forward until robot is in front of the ramp
			motor[rightMotor] = 50;
			motor[leftMotor] = 50;
			wait1Msec(1100);
			// Turn left towards ramp
			motor[rightMotor] = 50;
			motor[leftMotor] = -50;
			wait1Msec(1200);
			// Drive onto the ramp
			motor[rightMotor] = 50;
			motor[leftMotor] = 50;
			wait1Msec(1000);
			motor[rightMotor] = 0;
			motor[leftMotor] = 0;
		}
		else { // turn left
			motor[leftMotor] = -50;
			motor[rightMotor] = 50;
			wait1Msec(400);

			// Goes forward until robot is in front of the ramp
			motor[rightMotor] = 50;
			motor[leftMotor] = 50;
			wait1Msec(1400);
			// Turn right towards ramp
			motor[rightMotor] = -50;
			motor[leftMotor] = 50;
			wait1Msec(1200);
			// Drive onto the ramp
			motor[rightMotor] = 50;
			motor[leftMotor] = 50;
			wait1Msec(1000);
			motor[rightMotor] = 0;
			motor[leftMotor] = 0;
		}

}
