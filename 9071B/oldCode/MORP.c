#pragma config(Sensor, dgtl1,  buttonControl,  sensorTouch)
#pragma config(Motor,  port2,           sorterWheel,   tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
int wheelTurn = 0;
task main()
{
	while (!(3==2))
	{
		if (SensorValue[dgtl1] == 1)
		{
			wheelTurn = 1;
		}
		while (wheelTurn ==1)
		{
			motor[port2] = -20;
			wait(1);
			motor[port2] = 0;
			wait(1);
			if (SensorValue[dgtl1] == 1)
			{
				wheelTurn = 0;
			}
		}
	}
}
