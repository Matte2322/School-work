#pragma config(Sensor, S1,     touchSensor,              sensorTouch)
#pragma config(Sensor, S2,     compassSensor,            sensorVirtualCompass)
#pragma config(Sensor, S3,     lightSensor,              sensorLightActive)
#pragma config(Sensor, S4,     sonarSensor,              sensorSONAR)
#pragma config(Motor,  motorA,          gripperMotor,       tmotorNormal, PIDControl, encoder)
#pragma config(Motor,  motorB,          rightMotor,         tmotorNormal, PIDControl, encoder)
#pragma config(Motor,  motorC,          leftMotor,          tmotorNormal, PIDControl, encoder)

// inconsistent code

void moveForward(int powerLevel) // determine powerlevel either moving forward or backward
{
	motor[leftMotor] = powerLevel;
	motor[rightMotor] = powerLevel;
}

task main()
{
	int fullPower = 100;
	//int fullStop = 0;
	int partialPower = 75;
	bool foundBlack = false;
	int lineCount = 0;
	//int repeats = 0;
	//bool foundDuplicate = false;

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
			lineCount = lineCount + 1;
		}

		displayTextLine(5, "line #: %d", lineCount);

		if(SensorValue(lightSensor) > 30)
		{
			moveForward(fullPower);
		}

		if(lineCount == 1)
		{
			lineCount = lineCount - 1;
			lineCount = lineCount + 2;

			moveForward(-fullPower);
			wait1Msec(1000);
			continue;
		}
		else if(lineCount == 2)
		{
			lineCount = lineCount + 1;
			moveForward(fullPower);
			wait1Msec(2000);
			continue;
		}
		else if(lineCount == 4)
		{
			lineCount = lineCount + 1;
			moveForward(-fullPower);
			wait1Msec(2000);
			continue;
		}
		else if(lineCount == 5)
		{
			lineCount = lineCount + 1;
			moveForward(fullPower);
			wait1Msec(2500);
		}
		else if(lineCount == 7)
		{
			lineCount = lineCount + 1;
			moveForward(-fullPower);
			wait1Msec(3000);
		}
		else if(lineCount == 12)
		{
			lineCount = lineCount + 1;
			moveForward(-fullPower);
			wait1Msec(3500);
		}
		else if(lineCount == 18)
		{
			lineCount = lineCount + 1;
			moveForward(-fullPower);
			wait1Msec(4300);
		}
	}
}
