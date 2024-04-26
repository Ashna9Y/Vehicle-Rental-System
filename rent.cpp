#include "Time.h"
#include "Date.h"
#include "Vehicle.h"
#include <iostream>

void rent_days(Car& cobj, int days_i)
{
	//calculating rent of car based on days
	double rent = 0.0;
	rent = cobj.rentalpriceperday * days_i;
	std::cout << "Total days car rented: " << days_i << std::endl;
	std::cout << "Total rent of car: " << rent << std::endl;
	return;
}

void rent_hours(Car& cobj, int hours_i)
{
	////calculating rent of car based on hours
	double rent = 0.0;
	rent = cobj.rentalpriceperhour * hours_i;
	std::cout << "Total hours car rented: " << hours_i << std::endl;
	std::cout << "Total rent of car: " << rent << std::endl;
	return;
}

void rent_days(Bike& bobj, int days_i)
{
	//calculating rent of bike based on days
	double rent = 0.0;
	rent = bobj.rentalpriceperday * days_i;
	std::cout << "Total days bike rented: " << days_i << std::endl;
	std::cout << "Total rent of bike: " << rent << std::endl;
	return;
}

void rent_hours(Bike& bobj, int hours_i)
{
	//calculating rent of bike based on hours
	double rent = 0.0;
	rent = bobj.rentalpriceperhour * hours_i;
	std::cout << "Total hours bike rented: " << hours_i << std::endl;
	std::cout << "Total rent of bike: " << rent << std::endl;
	return;
}
