#pragma config(Motor,  port2,           BackMotorLeft, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           BackMotorRight, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           FrontMotorLeft, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           FrontMotorRight, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           LiftLeft,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           LiftRight,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           ClawLeft,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           ClawRight,     tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//Yeah I know you suck. JKJKJKJKJKJKJK ggggggggggggg hahahahahahahahahahah
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
	startMotor(BackMotorLeft);
	startMotor(BackMotorRight);
	startMotor(FrontMotorLeft);
	startMotor(FrontMotorRight);
	wait(15);

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
	// User control code here, inside the loop

	while (true)
	{


		motor[BackMotorLeft]  = (vexRT[Ch2] + vexRT[Ch1])/2;  // (y + x)/2
		motor[BackMotorRight] = (vexRT[Ch2] - vexRT[Ch1])/2;  // (y - x)/2
		motor[FrontMotorRight]  = (vexRT[Ch2] + vexRT[Ch1])/2;  // (y + x)/2
		motor[FrontMotorLeft] = (vexRT[Ch2] - vexRT[Ch1])/2;  // (y - x)/2
		motor[LiftLeft] = (vexRT[Ch3]);
		motor(LiftRight) = (vexRT[Ch3]);

		if (Btn7R == 1)
		{
			motor[ClawLeft]=127;
			motor[ClawRight]=127;
		}
		else if (Btn7L ==1)
		{
			motor[ClawLeft]=-127;
			motor[ClawRight]=-127;
		}
		else
		{
			motor[ClawLeft]=0;
			motor[ClawRight]=0;
		}


	}
}
