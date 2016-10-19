#pragma once
#include <iostream>
#include <string>
#include "TimeImp.h" 
#include "CivilianTimeImp.h" 


class ZuluTimeImp : public TimeImp {
public:
	ZuluTimeImp(int hr, int min, int zone) : TimeImp(hr, min) {
		if (zone == 5)
			strcpy(zone_, " Eastern Standard Time");
		else if (zone == 6)
			strcpy(zone_, " Central Standard Time");
	}

	/* virtual */
	void tell() {
		std::cout << "time is " << hr_ << "  " << min_ << "  " << zone_ <<
			std::endl;
	}
protected:
	char zone_[30];
};
