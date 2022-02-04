#pragma config(Sensor, S1,     touchSensor,              sensorTouch)
#pragma config(Sensor, S2,     compassSensor,            sensorVirtualCompass)
#pragma config(Sensor, S3,     lightSensor,              sensorLightActive)
#pragma config(Sensor, S4,     sonarSensor,              sensorSONAR)
#pragma config(Motor,  motorA,          gripperMotor,       tmotorNormal, PIDControl, encoder)
#pragma config(Motor,  motorB,          rightMotor,         tmotorNormal, PIDControl, encoder)
#pragma config(Motor,  motorC,          leftMotor,          tmotorNormal, PIDControl, encoder)



void driveStraight(int powerLevel)
{
	motor[leftMotor] = powerLevel;
	motor[rightMotor] = powerLevel;
}

void turnRight90(int powerLevel1, int powerLevel2)
{
	motor[leftMotor] = powerLevel1;
	motor[rightMotor] = powerLevel2;

}

task main()
{
	while(true)
	{
		driveStraight(100);
		if(SensorValue(sonarSensor) <= 15)
		{
			turnRight90(100, 0);
			wait1Msec(200);
		}

	}
}
