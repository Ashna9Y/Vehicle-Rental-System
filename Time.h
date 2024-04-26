#ifndef TIME_H
#define TIME_H

#include <string>
#include "Vehicle.h"

class TIME
{
private:
	int hour;
	int minute;
public:
	TIME(int,int);
	void display();
	int total_hours(TIME &et);
	friend void rent_hours(Car& cobj, int time_i);
	friend void rent_hours(Bike& bobj, int time_i);
};

#endif //TIME_H
