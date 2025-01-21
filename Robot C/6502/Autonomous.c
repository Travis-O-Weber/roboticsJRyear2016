#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  HTMotor)
#pragma config(Sensor, S2,     Autonomous_Switch, sensorTouch)
#pragma config(Sensor, S3,     turnSensor,     sensorI2CHiTechnicGyro)
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
  // This must be included for the waitToStart() function to work since it is located in the JoystickDriver file!!!

void initializeRobot()
{
	servo[Gripper] = 110;   // Move Gripper to closed position
	return;
}

void turnRobot(int Power, int degreesToTurn) {
	// take initial reading from gyro
	float degreesSoFar = 0;
	int initialTurnReading = SensorValue[turnSensor];
	// start turning
	motor[rightMotor] = -Power * sgn(degreesToTurn);
	motor[leftMotor] = Power * sgn(degreesToTurn);
	// check if we have turned enough
	while (abs(degreesSoFar) < abs(degreesToTurn)) // Use absolute value so this works for negative degreesToTurn
	{
		// update degreesSoFar
		wait1Msec(10);  // wait 10 milliseconds or .01 seconds
		int currentGyroReading = SensorValue[turnSensor] - initialTurnReading;
		degreesSoFar = degreesSoFar + currentGyroReading * .01;
	}
	// stop turning
	motor[rightMotor] = 0;
	motor[leftMotor] = 0;
}

task main()
{
	initializeRobot();

	waitForStart(); // Wait for the beginning of autonomous phase.

	// Drive forward towards the basket
	motor[rightMotor] = 50;
	motor[leftMotor] = 50;
	wait1Msec(500);  // Drive forward for .5 seconds then stop
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
	motor[Arm] = 0;
	// Backup a little
	motor[rightMotor] = -50;
	motor[leftMotor] = -50;
	wait1Msec(200);

	// Turns right or left depending on the touch sensor
	if(SensorValue[sensorTouch] == 1) { // If switch is pressed, turn right which is a positive degree number
		turnRobot(25,50);  // First number is motor power; second number is degrees
		// Goes forward until robot is in front of the ramp
		motor[rightMotor] = 50;
		motor[leftMotor] = 50;
		wait1Msec(1500);
		// Turn left towards ramp
		turnRobot(25,-120);  // Negative degrees means turn left
		// Drive onto the ramp
		motor[rightMotor] = 50;
		motor[leftMotor] = 50;
		wait1Msec(1000);
		// Stop on the ramp
		motor[rightMotor] = 0;
		motor[leftMotor] = 0;
	}
	else { // turn left
		turnRobot(25,-50);  // Nagative second number (degrees) means turn left
		// Goes forward until robot is in front of the ramp
		motor[rightMotor] = 50;
		motor[leftMotor] = 50;
		wait1Msec(1400);
		// Turn right towards ramp
		turnRobot(25,120);
		// Drive onto the ramp
		motor[rightMotor] = 50;
		motor[leftMotor] = 50;
		wait1Msec(1000);
		motor[rightMotor] = 0;
		motor[leftMotor] = 0;
	}
}
