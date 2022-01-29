#pragma config(Sensor, S1,     touchSensor,              sensorTouch)
#pragma config(Sensor, S2,     compassSensor,            sensorVirtualCompass)
#pragma config(Sensor, S3,     lightSensor,              sensorLightActive)
#pragma config(Sensor, S4,     sonarSensor,              sensorSONAR)
#pragma config(Motor,  motorA,          gripperMotor,       tmotorNormal, PIDControl, encoder)
#pragma config(Motor,  motorB,          rightMotor,         tmotorNormal, PIDControl, encoder)
#pragma config(Motor,  motorC,          leftMotor,          tmotorNormal, PIDControl, encoder)

// forked from John Lugo's code
// Buggy Bot
void goForward(int powerLevel)
{
	motor[leftMotor] = powerLevel;
	motor[rightMotor] = powerLevel;
}

void turn90Right(int wheelTurn, int wheelTurn1)
{
	motor[leftMotor] = wheelTurn;
	motor[rightMotor] = wheelTurn1;
}

void turn90Left(int wheelLeft, int wheelRight)
{
	motor[leftMotor] = wheelLeft;
	motor[rightMotor] = wheelRight;
}


task main()
{
    int maximumSpeed = 100;
    displayTextLine(3,"DoorMat");

    goForward(maximumSpeed);
    wait1Msec(1000);



    int repeats = 0;
    while(repeats <= 2)
    {
  	if(SensorValue(sonarSensor) < 30)
 	{
      		turn90Right(50, 0);
      		wait1Msec(1000);

      		repeats++;
  	}
    }
	 goForward(maximumSpeed);
	 wait1Msec(450);

	 turn90Left(0, 100);
	 wait1Msec(455);

	 goForward(maximumSpeed);
	 wait1Msec(3000);

	 turn90Right(100, 0);
	 wait1Msec(450);

	 goForward(maximumSpeed);
	 wait1Msec(1500);

	 turn90Right(100, 0);
	 wait1Msec(350);

	 goForward(maximumSpeed);
	 wait1Msec(1000);

	 int repeats1 = 0;
	 while(repeats1 <= 2)
	 {
		if(SensorValue(sonarSensor) < 30)
	 	{
	 		turn90Left(0, 100);
	 		wait1Msec(1200);
	 		repeats1++;
	 	}
	 }
	 goForward(maximumSpeed);
	 wait1Msec(400);

	turn90Left(0, 100);
	wait1Msec(400);

	goForward(maximumSpeed);
	wait1Msec(3000);
}

