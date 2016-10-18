#pragma once
#include <iomanip>
#include <iostream>
#include <string>
#include "TimeImp.h" 
class CivilianTimeImp : public TimeImp {
public:
	CivilianTimeImp(int hr, int min, int pm) : TimeImp(hr, min) {
		if (pm)
			strcpy(whichM_, " PM");
		else
			strcpy(whichM_, " AM");
	}

	/* virtual */
	void tell() {
		cout << "time is " << hr_ << ":" << min_ << whichM_ << endl;
	}
protected:
	char whichM_[4];
};