#pragma config(Motor,  motorA,          rightMotor,    tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          leftMotor,     tmotorNXT, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


//  NOT WORKING RIGHT!!!!



#include "JoystickDriver.c"
// Define the following macros
#define DEADBAND(n,d)           ((abs(n) >= (d))? (n): 0)  //Set n to zero if < d where d = deadzone value
#define JOYSTICK2MOTOR(n)       ((n)*100/128) //Normalize value to max 100
#define JOYSTICK_POWER(n)       JOYSTICK2MOTOR(DEADBAND(n, 15)) //15 is the deadband limit
#define BOUND(n,low,high)       (((n) < (low))? (low): ((n) > (high))? (high): (n)) // low=-100 and high=100

void ArcadeDrive(int drivePower, int turnPower) {
	motor[leftMotor] = BOUND(drivePower + turnPower, -100, 100);
	motor[rightMotor] = BOUND(drivePower - turnPower, -100, 100);
}

// Function to perform math on joystick values to smooth into an exponential function for better slow speed driving
task main()
{
	while(true) //infinite loop
	{

		getJoystickSettings(joystick); //retrieves data from the joystick

		// Scale the joystick x and y to the motor power range (-100 to 100) after applying deadband.
		if (abs(joystick.joy1_y1) > 15)  // dead zone = 15
		{
			motor[leftMotor]=joystick.joy1_y1*100/128;
		} else motor[leftMotor]=0;

		ArcadeDrive(JOYSTICK_POWER(joystick.joy1_y1), JOYSTICK_POWER(joystick.joy1_x1));

		//wait1Msec(100);
		if(abs(joystick.joy1_y1) > 5) //threshold of 5
		{
			long step1 = joystick.joy1_y1 * joystick.joy1_y1; // x^2
			long step2 = step1 * joystick.joy1_y1; 						// x^3
			long step3 = step2 * 80; 													// 80x^3
			float step4 = step3 / 16129; 											// 80x^3 / 127^2
			long step5 = step4 / abs(joystick.joy1_y1);				// 80x^3 / (127^2 * abs(x))
			int step6 = 20 * joystick.joy1_y1;								// 20x
			int step7 = step6 / abs(joystick.joy1_y1);				// 20x / abs(x)
			int final = step5 + step7;												// (80x^3 / (127^2 * abs(x))) + (20x / abs(x))

			motor[leftMotor] = final;
		}
		else
		{
			motor[leftMotor] = 0;
		}

		if(abs(joystick.joy1_y2) > 5)
		{
			long step1 = joystick.joy1_y2 * joystick.joy1_y2;
			long step2 = step1 * joystick.joy1_y2;
			long step3 = step2 * 80;
			float step4 = step3 / 16129;
			long step5 = step4 / abs(joystick.joy1_y2);
			int step6 = 20 * joystick.joy1_y2;
			int step7 = step6 / abs(joystick.joy1_y2);
			int final = step5 + step7;

			motor[rightMotor] = final;
		}
		else
		{
			motor[rightMotor] = 0;
		}
	}
}
