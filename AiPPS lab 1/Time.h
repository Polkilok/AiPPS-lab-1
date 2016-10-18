#pragma once
#include <iomanip>
#include <iostream>
#include <string>
#include "TimeImp.h" 
#include "CivilianTimeImp.h" 
#include "ZuluTimeImp.h"

class Time {
public:
	Time() {}
	Time(int hr, int min) {
		imp_ = new TimeImp(hr, min);
	}
	virtual void tell() {
		imp_->tell();
	}
protected:
	TimeImp *imp_;
};