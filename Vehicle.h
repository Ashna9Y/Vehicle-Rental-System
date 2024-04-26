#ifndef VEHICLE_H   //include gaurd so that file is not included more than once 
#define VEHICLE_H


#include <string>

class Vehicle
{
protected:
	int number;
	std::string brand;
	std::string model;
	double rentalpriceperday;
	double rentalpriceperhour;
	double mileage;
	std::string fuel_type;
public:
	Vehicle();
	Vehicle(int, std::string, std::string, double, double, double, std::string);
	virtual void display() = 0; 
	virtual bool display_in_range_days(double) = 0;
	virtual bool display_in_range_hours(double) = 0;
	~Vehicle();
};


class Car :public Vehicle
{
private:
	int seat;
	std::string drive_type;
	std::string drive_experience;

public:
	Car();
	Car(int, std::string, std::string, double, double, double,std::string, int, std::string, std::string);
	static int number_car;
	void display();
	bool display_in_range_days(double);
	bool display_in_range_hours(double);
	bool display_selected_car(int);
	bool delete_car(int);
	friend void rent_hours(Car& cobj, int time_i);
	friend void rent_days(Car& cobj, int days_i);
	~Car();
};


class Bike :public Vehicle
{
private:
	std::string type;
public:
	Bike();
	Bike(int, std::string, std::string, double, double, double, std::string, std::string);
	static int number_bike;
	void display();
	bool display_in_range_days(double);
	bool display_in_range_hours(double);
	bool display_selected_bike(int);
	bool delete_bike(int);
	friend void rent_hours(Bike& bobj, int time_i);
	friend void rent_days(Bike& bobj, int days_i);
	~Bike();
};
#endif //VEHICLE_H