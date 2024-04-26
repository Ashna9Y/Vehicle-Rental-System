#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle() //vehicle constructor initializing objects
{
	number = 0;
	brand = " ";
	model = " ";
	rentalpriceperday = 0.0;
	rentalpriceperhour = 0.0;
	mileage = 0.0;
	fuel_type = " ";
}

Vehicle::Vehicle(int n, std::string b, std::string m , double rppd, double rpph, double mi , std::string ft)
{
	//vehicle constructor assigning values
	number = n;
	brand = b;
	model = m;
	rentalpriceperday = rppd;
	rentalpriceperhour = rpph;
	mileage = mi;
	fuel_type = ft;
}

Vehicle::~Vehicle() {}

int Car::number_car = 0;
Car::Car():Vehicle() //car constructor initializing objects
{
	seat = 0;
	drive_type = " ";
	drive_experience = " ";
}
Car::Car(int cn, std::string bi, std::string mi, double rppdi, double rpphi,double mi_i, std::string ft_i, int s, std::string dt, std::string de):Vehicle(cn,bi,mi,rppdi,rpphi,mi_i,ft_i)
{
	//car constructor to assign values
	seat = s;
	drive_type = dt;
	drive_experience = de;
	number_car++;
}

void Car::display()
{
	//displaying car details
	std::cout << std::endl << "Vehicle details :";
	std::cout << std::endl << "Car: ";
	std::cout << std::endl << "Car number: "<<number;
	std::cout << std::endl << "Brand: " << brand;
	std::cout << std::endl << "Model: " << model;
	std::cout << std::endl << "Rental price per day: " << rentalpriceperday;
	std::cout << std::endl << "Rental price per hour: " << rentalpriceperhour;
	std::cout << std::endl << "Mileage: " << mileage;
	std::cout << std::endl << "Fuel type: " << fuel_type;
	std::cout << std::endl << "Number of seats: " << seat;
	std::cout << std::endl << "Drive type: " << drive_type;
	std::cout << std::endl << "Drive experience: " << drive_experience << std::endl;
	return;
}
bool Car::display_in_range_days(double uld)
{
	bool b = false;
	if (rentalpriceperday < uld)
	{
		display();
		b = true;
	}
	return b;
}

bool Car::display_in_range_hours(double ulh)
{
	bool b = false;
	if (rentalpriceperhour < ulh)
	{
		display();
		b = true;
	}
	return b;
}
bool Car::display_selected_car(int index)
{
	bool b = false;
	if (index == number)
	{
		b = true;
	}
	return b;
}
bool Car::delete_car(int index)
{
	bool b = false;
	if (index == number)
	{
		b = true;
	}
	return b;
}

Car::~Car()
{
	number_car--;
}

Bike::Bike()
{
	number = 0;
	brand = " ";
	model = " ";
	rentalpriceperday = 0.0;
	rentalpriceperhour = 0.0;
	mileage = 0.0;
	fuel_type = " ";
	type = " ";
}

Bike::Bike(int n, std::string b, std::string m, double rppd, double rpph, double mi, std::string ft, std::string t):Vehicle(n,b,m,rppd,rpph,mi,ft)
{
	number = n;
	brand = b;
	model = m;
	rentalpriceperday = rppd;
	rentalpriceperhour = rpph;
	mileage = mi;
	fuel_type = ft;
	type = t;
}
int Bike::number_bike = 0;
void Bike::display()
{
	std::cout << std::endl << "Vehicle details :";
	std::cout << std::endl << "Bike: ";
	std::cout << std::endl << "Bike number: " << number;
	std::cout << std::endl << "Brand: " << brand;
	std::cout << std::endl << "Model: " << model;
	std::cout << std::endl << "Rental price per day: " << rentalpriceperday;
	std::cout << std::endl << "Rental price per hour: " << rentalpriceperhour;
	std::cout << std::endl << "Mileage: " << mileage;
	std::cout << std::endl << "Fuel type: " << fuel_type;
	std::cout << std::endl << "Drive type: " << type;
	return;
}
bool Bike::display_in_range_days(double uld)
{
	bool b = false;
	if (rentalpriceperday < uld)
	{
		display();
		b = true;
	}
	return b;
}

bool Bike::display_in_range_hours(double ulh)
{
	bool b = false;
	if (rentalpriceperhour < ulh)
	{
		display();
		b = true;
	}
	return b;
}

bool Bike::display_selected_bike(int index)
{
	bool b = false;
	if (index == number)
	{
		b = true;
		display();
	}
	return b;
}

bool Bike::delete_bike(int num)
{
	bool b = false;
	if (num == number)
	{
		b = true;
	}
	return b;
}

Bike::~Bike()
{
	number_bike--;
}