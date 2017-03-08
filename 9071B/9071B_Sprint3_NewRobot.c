#pragma config(Motor,  port1,           PincerL,       tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           frontLeft,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           frontRight,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           backLeft,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           backRight,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           pillarBottomL, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           pillarBottomR, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           pillarTopL,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           pillarTopR,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          PincerR,       tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/
int PillU = 100;
int PillD = -100;
int PinOpen = 100;
int PinClose = -100;

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
	// ..........................................................................
	// Insert user code here.
	// ..........................................................................

	// Remove this function call once you have "real" code.
	AutonomousCodePlaceholderForTesting();
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
	while (true)
	{
		motor[frontRight] = vexRT[Ch2];
		motor[backRight]  = vexRT[Ch2];
		motor[frontLeft] = vexRT[Ch3];
		motor[backLeft]  = vexRT[Ch3];

		if(vexRT[Btn5U] == 1)
		{
			motor[pillarBottomL] = PillU;
			motor[pillarBottomR] = PillU;
			motor[pillarTopL] = PillU;
			motor[pillarTopR]= PillU;
		}
		else if (vexRT[Btn5D] == 1)
		{
			motor[pillarBottomL] = PillD;
			motor[pillarBottomR] = PillD;
			motor[pillarTopL] = PillD;
			motor[pillarTopR]= PillD;
		}
		else
		{
			motor[pillarBottomL] = 0;
			motor[pillarBottomR] = 0;
			motor[pillarTopL] = 0;
			motor[pillarTopR]= 0;
		}
		//Pincer Control
		if(vexRT[Btn6U] == 1)
		{
			motor[PincerL] = PinOpen;
			motor[PincerR] = PinOpen;
		}
		else if (vexRT[Btn6D] == 1)
		{
			motor[PincerL] = PinClose;
			motor[PincerR] = PinClose;
		}
		else
		{
			motor[PincerL] = 0;
			motor[PincerR] = 0;
		}
	}
}
