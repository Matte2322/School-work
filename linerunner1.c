#pragma config(Sensor, S1,     touchSensor,              sensorTouch)
#pragma config(Sensor, S2,     compassSensor,            sensorVirtualCompass)
#pragma config(Sensor, S3,     lightSensor,              sensorLightActive)
#pragma config(Sensor, S4,     sonarSensor,              sensorSONAR)
#pragma config(Motor,  motorA,          gripperMotor,       tmotorNormal, PIDControl, encoder)
#pragma config(Motor,  motorB,          rightMotor,         tmotorNormal, PIDControl, encoder)
#pragma config(Motor,  motorC,          leftMotor,          tmotorNormal, PIDControl, encoder)

void moveForward(int powerLevel) // determine powerlevel either moving forward or backward
{
	motor[leftMotor] = powerLevel;
	motor[rightMotor] = powerLevel;
}

task main()
{
	int fullPower = 100;
	//int fullStop = 0;
	int partialPower = 50;
	bool foundBlack = false;
	int lineCount = 0;
	//int repeats = 0;

	displayBigTextLine(3, "DoorMat");

	while(true)
	{

    if(SensorValue(lightSensor) < 30)
		{
			foundBlack = true;
		}

		if(foundBlack && SensorValue(lightSensor) >= 30)
		{
			foundBlack = false;
			lineCount++;
		}

		displayTextLine(5, "line #: %d", lineCount);

		if(SensorValue(lightSensor) > 30)
		{
			moveForward(partialPower);
		}

		if(lineCount == 1)
		{
		 	--lineCount;
			moveForward(-fullPower);
			wait1Msec(1000);
			continue;
		}
		else if(lineCount == 2)
		{
			--lineCount;
			moveForward(-fullPower);
			wait1Msec(2000);
			continue;
		}
	}
}
