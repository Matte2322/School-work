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
	bool foundBlack = false;
	int lineCount = 0;
	
	displayBigTextLine(3, "DoorMat");
	
	while(true)
	{
		moveForward(fullPower);
		if(sensorValue(lightSensor) < 45)
		{
			foundBlack = true;		
		}
		
		if(foundBlack && sensorValue(lightSensor) >= 45)
		{
			foundBlack = false;
			lineCount++;
		}
		
		displayTextLine(5, "line #: %d", lineCount);
		if(lineCount == 0) 
		{
			continue;		
		}
	}
}
