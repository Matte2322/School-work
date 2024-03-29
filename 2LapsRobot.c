#pragma config(StandardModel, "RVW REMBOT")

task main()
{
	string name = "DoorMat";
	displayTextLine(3,"%s", name);
	wait1Msec(2000); // Robot waits for 2000 milliseconds before executing program

	for(int repeats = 0; repeats <= 8; repeats++) { // repeats 8 times to make 2 laps

		// Moves forward for 2 seconds
		displayTextLine(3, "Going forward");
		motor[rightMotor] = 100;
		motor[leftMotor]  = 100;
		wait1Msec(2000);

		// Turn right 90 degress for 1.4 second
		displayTextLine(3, "Turning right");
		motor[rightMotor] = 0;
		motor[leftMotor] = 50;
		wait1Msec(1400);

	}	
	
}
