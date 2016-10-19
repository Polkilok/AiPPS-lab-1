#pragma once
#include <iostream>
#include <string>
#include "TimeImp.h" 
#include "CivilianTimeImp.h" 
#include "ZuluTimeImp.h"
#include "Time.h"
class CivilianTime : public Time {
public:
	CivilianTime(int hr, int min, int pm) {
		imp_ = new CivilianTimeImp(hr, min, pm);
	}
};
class ZuluTime : public Time {
public:
	ZuluTime(int hr, int min, int zone) {
		imp_ = new ZuluTimeImp(hr, min, zone);
	}
};
int main() {
	Time *times[3];
	times[0] = new Time(14, 30);
	times[1] = new CivilianTime(2, 30, 1);
	times[2] = new ZuluTime(14, 30, 6);
	for (int i = 0; i < 3; i++)
		times[i]->tell();
}