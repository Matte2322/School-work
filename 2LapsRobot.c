#pragma config(StandardModel, "RVW REMBOT")

task main()
{
	string name = "DoorMat";
	displayCenteredBigTextLine(3, "%s", name);
	wait1Msec(2000);						// Robot waits for 2000 milliseconds before executing program

	for(int repeats = 0; repeats <= 8; repeats++) { // repeats 8 times to make 2 laps

		// Moves forward for 2 seconds
		motor[rightMotor] = 100;
		motor[leftMotor]  = 100;
		wait1Msec(2000);

	// Turn right 90 degress for 1.4 second
		motor[rightMotor] = 0;
		motor[leftMotor] = 50;
		wait1Msec(1400);


	}


}
