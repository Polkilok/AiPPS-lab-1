#pragma once
#include <iomanip>
#include <iostream>
#include <string>
class TimeImp {
public:
	TimeImp(int hr, int min) {
		hr_ = hr;
		min_ = min;
	}
	virtual void tell() {
		std::cout << "time is " << std::setw(2) << std::setfill(48) << hr_ << min_ << std::endl;
	}
protected:
	int hr_, min_;
};