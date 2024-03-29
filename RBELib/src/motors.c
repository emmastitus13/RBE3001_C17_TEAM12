/*
 * motors.c
 *
 *  Created on: Jan 31, 2017
 *      Author: Rayyan
 */
#include <RBELib/RBELib.h>


void stopMotors(){
	int i_;
	for (i_ = 0; i_ < 4; i_++) {
		setDAC(i_, 0);
	}
}


void gotoAngles(int lowerTheta, int upperTheta){
	int ang_L = getADC(2);
	int ang_H = getADC(3);

	unsigned short pid_H = calcPID('H', upperTheta, ang_H);
	unsigned short pid_L = calcPID('L', lowerTheta, ang_L);

	driveLink(0, pid_L);
	driveLink(1, pid_H);
}


void gotoXY(int x, int y){

}


void driveLink(int link, int dir){
	// Upper link
	if(link == 1){
		// Limit dir value to -4095 to +4095
		if(dir >= 0){
			if (dir > 4095) {
				dir = 4095;
			}
			setDAC(2, 0);
			setDAC(3, dir);
		}
		if(dir < 0){
			if (dir < -4095) {
				dir = -4095;
			}
			setDAC(2, dir*-1);
			setDAC(3, 0);
		}
	}
	// Lower link
	if(link == 0){
		// Limit dir value to -4095 to +4095
		if(dir >= 0){
			if (dir > 4095) {
				dir = 4095;
			}
			setDAC(0, dir);
			setDAC(1, 0);
		}
		if(dir < 0){
			if (dir < -4095) {
				dir = -4095;
			}
			setDAC(0, 0);
			setDAC(1, dir*-1);
		}
	}
}



void homePos(){

}
