#pragma config(Sensor, in7,    ,               sensorPotentiometer)
#pragma config(Sensor, in8,    Gyroauto,       sensorGyro)
#pragma config(Sensor, dgtl1,  sonarSensor,    sensorSONAR_inch)
#pragma config(Motor,  port1,           Hook,          tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           frontLeft,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           frontRight,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           backLeft,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           backRight,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           leftUp,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           leftUpt,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           rightUp,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           rightUpt,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          Meta,          tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int X2 = 0, Y1 = 0, X1 = 0, threshold = 15;

int leftArmSpeed = 0;
int rightArmSpeed = 0;
int degree = 0;
int error = 10;

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
	//Completely clear out any previous sensor readings by setting the port to "sensorNone"
	SensorType[in8] = sensorNone;
	wait1Msec(1000);
	//Reconfigure Analog Port 8 as a Gyro sensor and allow time for ROBOTC to calibrate it
	SensorType[in8] = sensorGyro;
	wait1Msec(2000);
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
	/*while(!(SensorValue[dgtl1] == 1 && SensorValue[dgtl2] == 1))
	{
	if (SensorValue[in8] > degree-error && SensorValue[in8] < degree - error)
	{
	motor[backLeft] = 100;
	motor[backRight] = 100;
	motor[frontLeft] = 100;
	motor[frontRight] = 100;
	}
	else if (SensorValue[in8] <degree-error)
	{
	motor[backLeft] = -50;
	motor[backRight] = 50;
	motor[frontRight] = 50;
	motor[frontLeft] = -50;
	}
	else
	{
	motor[backLeft] = 50;
	motor[backRight] = -50;
	motor[frontLeft] = 50;
	motor[frontRight] = -50;
	}

	/*untilTouch(FrontButton);
	startMotor(frontLeft, 127);
	startMotor(frontRight, 127);
	startMotor(backLeft, -127);
	startMotor(backRight, -127);
	startMotor(Meta, 127);
	wait(5);
	*/
	//
	//Run with one jumper clip in Digital 12 port.
	//
	if (SensorValue[dgtl11]==1 && SensorValue[dgtl12] == 0) {
		while(SensorValue(sonarSensor) > 7  || SensorValue(sonarSensor) == -1)		// Loop while robot's Ultrasonic sensor is further than 20 inches away from an object
		{                                                                         // || (or) it is '-1'.  (-1 is the value returned when nothing is in it's visable range)
			startMotor(backLeft, -127);
			startMotor(backRight, -127);
			startMotor(frontLeft, -127);
			startMotor(frontRight, -127);
		}
		startMotor(backLeft, 15);
		startMotor(backRight, 15);
		startMotor(frontLeft, 15);
		startMotor(frontRight, 15);
		wait(.25);
		stopMotor(backLeft);
		stopMotor(backRight);
		stopMotor(frontRight);
		stopMotor(frontLeft);

		motor[Meta] = -127;
		wait(1);
		motor[Meta] = 127;
	}
	//
	//Run with one jumper clip in Digital 11 port.
	//
	else if (SensorValue[dgtl11]==0 && SensorValue[dgtl12] == 1)
	{
		while(SensorValue(sonarSensor) > 7  || SensorValue(sonarSensor) == -1)		// Loop while robot's Ultrasonic sensor is further than 20 inches away from an object
		{                                                                         // || (or) it is '-1'.  (-1 is the value returned when nothing is in it's visable range)
			startMotor(backLeft, -127);
			startMotor(backRight, -127);
			startMotor(frontLeft, -127);
			startMotor(frontRight, -127);
		}
		stopMotor(backLeft);
		stopMotor(backRight);
		stopMotor(frontLeft);
		stopMotor(frontRight);
		startMotor(backLeft, 15);
		startMotor(backRight, 15);
		startMotor(frontLeft, 15);
		startMotor(frontRight, 15);
		wait(.5);
		startMotor(leftUp, 127);
		//startMotor(leftUpt, 127);
		startMotor(rightUp, 127);
		//startMotor(rightUpt, 127);
	}
	//
	//Run with jumper clips in Digital 11 and Digital 12. TRUE Meta on RIGHT Side
	//
	else if (SensorValue[dgtl11]==0 && SensorValue[dgtl12] == 0)
	{
		while(SensorValue(sonarSensor) > 5  || SensorValue(sonarSensor) == -1)
		{
		// Loop while robot's Ultrasonic sensor is further than 20 inches away from an object                                                                        // || (or) it is '-1'.  (-1 is the value returned when nothing is in it's visable range)
		startMotor(backLeft, -90);
		startMotor(backRight, -90);
		startMotor(frontLeft, -90);
		startMotor(frontRight, -90);

			/*if (SensorValue[in8] > degree-error && SensorValue[in8] < degree + error)
			{
				motor[backLeft] = -100;
				motor[backRight] = -100;
				motor[frontLeft] = -100;
				motor[frontRight] = -100;
			}
			else if (SensorValue[in8] <degree-error)
			{
				motor[backLeft] = -50;
				motor[backRight] = 50;
				motor[frontRight] = 50;
				motor[frontLeft] = -50;
			}
			else
			{
				motor[backLeft] = 50;
				motor[backRight] = -50;
				motor[frontLeft] = 50;
				motor[frontRight] = -50;
			}*/
		}
		//	startMotor(backLeft, -127);
		//	startMotor(backRight, -127);
		//	startMotor(frontLeft, -127);
		//startMotor(frontRight, -127);
		//	wait(2.3);
		startMotor(backLeft, 15);
		startMotor(backRight, 15);
		startMotor(frontLeft, 15);
		startMotor(frontRight, 15);
		wait(.25);
		stopMotor(backLeft);
		stopMotor(backRight);
		stopMotor(frontRight);
		stopMotor(frontLeft);
		motor[Meta] = -127;
		wait(1);
		motor[Meta] = -127;
		startMotor(frontLeft, 127);
		startMotor(frontRight, -127);
		startMotor(backLeft, -127);
		startMotor(backRight, 127);
		startMotor(Meta, -127);
		wait(2);
		stopMotor(Meta);
		stopMotor(frontLeft);
		stopMotor(frontRight);
		stopMotor(backLeft);
		stopMotor(backRight);
	}
	//
	//Run code when no jumper clips are present. DEFAULT.
	//
	else
	{
		wait(3);
	}
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
	{		/*+++++++++++++++++++++++++++++++++++++++++++++| Notes |++++++++++++++++++++++++++++++++++++++++++++
		Mecanum Drive with Deadzone Thresholds
		- This program allows you to remotely control a robot with mecanum wheels.
		- The left joystick Y-axis controls the robot's forward and backward movement.
		- The left joystick X-axis controls the robot's left and right movement.
		- The right joystick X-axis controls the robot's rotation.
		- This program incorportes a threshold/deadzone that allows very low Joystick values to be ignored.
		This allows the robot to ignore values from the Joysticks when they fail to center at 0,
		and provides a margin of error for the driver when they only want the robot to move in one axis.

		[I/O Port]          [Name]              [Type]                [Description]
		Motor Port 2        frontRight          VEX Motor             Front Right motor
		Motor Port 3        backRight           VEX Motor             Back Right motor
		Motor Port 4        frontLeft           VEX Motor             Front Left motor
		Motor Port 5        backLeft            VEX Motor             Back Left motor
		--------------------------------------------------------------------------------------------------*/


		//Create "deadzone" for Y1/Ch3
		if(abs(vexRT[Ch3]) > threshold)
			Y1 = vexRT[Ch3];
		else
			Y1 = 0;
		//Create "deadzone" for X1/Ch4
		if(abs(vexRT[Ch4]) > threshold)
			X1 = vexRT[Ch4];
		else
			X1 = 0;
		//Create "deadzone" for X2/Ch1
		if(abs(vexRT[Ch1]) > threshold)
			X2 = vexRT[Ch1];
		else
			X2 = 0;

		//Remote Control Commands
		motor[frontRight] = Y1 - X2 - X1;
		motor[backRight] =  Y1 - X2 + X1;
		motor[frontLeft] = Y1 + X2 + X1;
		motor[backLeft] =  Y1 + X2 - X1;

		if(vexRT[Btn5D] == 1)				//Left Arms
		{
			motor[port6] = -127;
			//motor[port7] = -127;
			motor[port8] = 127;
			//motor[port9] = 127;

		}
		else if(vexRT[Btn5U] ==1)
		{
			motor[port6] = 127;
			//motor[port7] = 127;
			motor[port8] = -127;
			//	motor[port9] = -127;
		}
		else
		{
			motor[port6] = 0;
			//motor[port7] = 0;
			motor[port8] = 0;
			//	motor[port9] = 0;
		}
		if(vexRT[Btn7L] == 1)   //Meta Counter go
		{
			motor[port10] = 127;
		}
		else if(vexRT[Btn7D] == 1)	//Clockwise
		{
			motor[port10] = -127;
		}
		else
		{
			motor[port10] = 0;
		}

		/*if(vexRT[Btn8R] == 1)			//Hook
		{
		motor[port1] =127;
		}
		else if(vexRT[Btn8U] ==1)
		{
		motor[port1] = -127;
		}
		else
		{
		motor[port1] = 0;*/

		if(vexRT[Btn6D] ==1) //Pincer
		{
			//rightArmSpeed += 1;
			motor[port9] = 100;

		}
		else if(vexRT[Btn6U] ==1)
		{
			//rightArmSpeed -= 1;
			motor[port9] = -100;
		}
		else
		{
			motor[port9] = 0;
		}
	}
	/*if(vexRT[Btn7R] == 1)  //Lifting in one button
	{

	motor[port6] = -127;
	motor[port7] = -127;
	motor[port8] = -127;
	motor[port9] = -127;
	wait(2);
	motor[port1] = 127;
	wait(.3);
	stopMotor(port1);
	stopMotor(port6);
	stopMotor(port7);
	stopMotor(port8);
	stopMotor(port9);
	}*/
}
