#pragma config(Sensor, S1,     touchSensor,              sensorTouch)
#pragma config(Sensor, S2,     compassSensor,            sensorVirtualCompass)
#pragma config(Sensor, S3,     lightSensor,              sensorLightActive)
#pragma config(Sensor, S4,     sonarSensor,              sensorSONAR)
#pragma config(Motor,  motorA,          gripperMotor,       tmotorNormal, PIDControl, encoder)
#pragma config(Motor,  motorB,          rightMotor,         tmotorNormal, PIDControl, encoder)
#pragma config(Motor,  motorC,          leftMotor,          tmotorNormal, PIDControl, encoder)


void driveStraight (int powerLevel)
{
		motor[rightMotor] = powerLevel;
		motor[leftMotor] = powerLevel;
}

void turnRight90 ()
{
	nMotorEncoder[leftMotor] = 0;
	while (nMotorEncoder[leftMotor] <175)
	{
		motor[rightMotor] = -50;
		motor[leftMotor] = 50;
	}
	motor[leftMotor] = 0;
}

task main()
{
	string botName = "   DoorMat";

	displayTextLine(2, "%s", botName);

	while(true)
	{

		driveStraight(100);

		if(SensorValue(lightSensor) <= 10)
		{
			wait1Msec(400);
			turnRight90();
		}
	}
}
