#ifndef DATE_H
#define DATE_H

#include "Vehicle.h"

class DATE
{
private:
	int date;
	int month;
	int year;
public:
	DATE(int, int, int);
	void dispaly();
	int days(DATE& ed);
	friend void rent_days(Car& cobj, int days_i);
	friend void rent_days(Bike& bobj, int days_i);
};

#endif //DATE_H
