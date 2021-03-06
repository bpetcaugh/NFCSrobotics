#pragma config(Sensor, in8,    gyro,           sensorGyro)
#pragma config(Sensor, dgtl7,  FRSensor,       sensorQuadEncoder)
#pragma config(Sensor, dgtl10, BLSensor,       sensorQuadEncoder)
#pragma config(Motor,  port2,           FLwheel,       tmotorVex393_MC29, openLoop, encoderPort, None)
#pragma config(Motor,  port3,           FRwheel,       tmotorVex393_MC29, openLoop, encoderPort, None)
#pragma config(Motor,  port4,           TLGear,        tmotorVex393_MC29, openLoop, encoderPort, None)
#pragma config(Motor,  port5,           BRwheel,       tmotorVex393_MC29, openLoop, encoderPort, None)
#pragma config(Motor,  port6,           BLwheel,       tmotorVex393_MC29, openLoop, encoderPort, None)
#pragma config(Motor,  port7,           BRGear,        tmotorVex393_MC29, openLoop, encoderPort, None)
#pragma config(Motor,  port8,           BLGear,        tmotorVex393_MC29, openLoop, encoderPort, None)
#pragma config(Motor,  port9,           TRGear,        tmotorVex393_MC29, openLoop, encoderPort, None)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int degree = 0;
int error = 1;

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

	SensorType[in8] = sensorNone;
	wait1Msec(1000);

	SensorType[in8] = gyro;
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

		setMotor(port4, -85); //The Scooper lifts up
		setMotor(port7, 85);
		setMotor(port8, -85);
		setMotor(port9, 85);
		wait(1.2);

				stopMotor(port4); //The Scooper stops lifting
		stopMotor(port7);
		stopMotor(port8);
		stopMotor(port9);

		wait(1);

	clearTimer(T1);

	while (time1[T1] < 3000)
	{
		if (SensorValue[gyro] < degree-error && SensorValue[gyro]  > degree + error)
		{
			motor[FLwheel] = -127;
			motor[FRwheel] = -127;
			motor[BLwheel] = -127;
			motor[BRwheel]= -127;
		}
		else if (SensorValue[gyro] < degree-error)
		{
			motor[FLwheel] = 127;
			motor[FRwheel] = -127;
			motor[BLwheel] = 127;
			motor[BRwheel]= -127;
		}
		else
		{
			motor[FLwheel] = -127;
			motor[FRwheel] = 127;
			motor[BLwheel] = -127;
			motor[BRwheel]= 127;
		}


	}
			stopMotor(FLwheel);
		stopMotor(FRwheel);
		stopMotor(BLwheel);
		stopMotor(BRwheel);

		setMotor(FLwheel, 127); //Has the robot move backwards
		setMotor(FRwheel, -127);
		setMotor(BRwheel, -127);
		setMotor(BLwheel, 127);
		wait(1.5);

		stopMotor(FLwheel);
		stopMotor(FRwheel);
		stopMotor(BLwheel);
		stopMotor(BRwheel);

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
		//Right side of the robot is controlled by the right joystick, Y-axis
		motor[port5] = vexRT[Ch3];
		motor[port3] = vexRT[Ch3];
		//Left side of the robot is controlled by the left joystick, Y-axis
		motor[port2] = -vexRT[Ch2];
		motor[port6] = -vexRT[Ch2];

		if(vexRT[Btn5U] == 1)
		{
			setMotor(port4, -125); //move arm up
			setMotor(port8, -125); //move arm up
		}
		else if (vexRT[Btn5D] == 1)
		{
			setMotor(port4, 125); //move arm down
			setMotor(port8, 125); //move arm down
		}
		else
		{
			stopMotor(port4);
			stopMotor(port8);
		}

		//

		if(vexRT[Btn6U] == 1)
		{
			setMotor(port7, 125); //move arm up
			setMotor(port9, 125); //move arm up
		}
		else if (vexRT[Btn6D] == 1)
		{
			setMotor(port7, -125); //move arm down
			setMotor(port9, -125); //move arm down
		}
		else
		{
			stopMotor(port7);
			stopMotor(port9);
		}

	}
}
