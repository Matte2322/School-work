#pragma config(Sensor, S1,     touchSensor,              sensorTouch)
#pragma config(Sensor, S2,     compassSensor,            sensorVirtualCompass)
#pragma config(Sensor, S3,     lightSensor,              sensorLightActive)
#pragma config(Sensor, S4,     sonarSensor,              sensorSONAR)
#pragma config(Motor,  motorA,          gripperMotor,       tmotorNormal, PIDControl, encoder)
#pragma config(Motor,  motorB,          rightMotor,         tmotorNormal, PIDControl, encoder)
#pragma config(Motor,  motorC,          leftMotor,          tmotorNormal, PIDControl, encoder)

/************************************\
|*  Programmer: DoorMat             *|  
|*                                  *|
|*  Task: Robotics Academy          *|
|*  Robot: Buggy Bot                *|
\************************************/
void driveStraight(int powerlevel){
	motor[rightMotor] = powerlevel;
	motor[leftMotor] = powerlevel;
}

void turnRight90(int turningRight, int turningRight1){
	motor[rightMotor] = turningRight;
	motor[leftMotor] = turningRight1;
}



task main()
{
	int fullpower = 100;
	int right = 0;
	int right1 = 100;

}
