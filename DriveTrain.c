#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     frontLeft,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     frontRight,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     backRight,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     backLeft,      tmotorTetrix, openLoop)
#pragma config(Sensor, S2,     gyro,           sensorI2CHiTechnicGyro)


#include<JoystickDriver.c>
#include<spirit.h>

int x1 = joystick.joy1_x1;
int x2 = joystick.joy1_x2;
int y1 = joystick.joy1_y1;
int rotclock = 0;
int mordorleft = motor[frontLeft] + motor[frontLeft] + rotclock;
const int power = 75;//motor power
//factors to multiply power by

task main()
{
	waitForStart();
	
	while(true)
	{
		//update joystick
		getJoystickSettings(joystick);
		x1 = joystick.joy1_x1;
		x2 = joystick.joy1_x2;
		y1 = joystick.joy1_y1;
		//set drive motors

		motor[frontLeft] = y1 + x1 + x2;
		motor[frontRight] = -y1 + x1 + x2;
		motor[backLeft] = y1 - x1 + x2;
		motor[backRight] = -y1 - x1 + x2;

		if (SensorValue[gyro] > 1)
   rotclock= rotclock+ SensorValue[gyro]
;
if (SensorValue[gyro] < -1)
    rotclock= rotclock+ SensorValue[gyro]
;
mordorleft = motor[frontLeft] + motor[frontLeft] + rotclock;
}//end while loop
}
