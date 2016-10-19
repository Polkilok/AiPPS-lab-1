#pragma once
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
		std::cout << "time is " << hr_ << ":" << min_ << whichM_ << std::endl;
	}
protected:
	char whichM_[4];
};