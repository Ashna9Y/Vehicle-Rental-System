#include "TIME.h"
#include <iostream>

TIME::TIME(int h,int m)//time constructor 
{
	hour = h;
	minute = m;
}
void TIME::display()//displaying time
{
	std::cout << " " << hour << ":" << minute << std::endl;
	return;
}
int TIME::total_hours(TIME& et)
{
	//counting hours from start time and end time 
	int hours = 0;
	if (hour > et.hour)
	{
		hours = hour - et.hour;
	}
	else if (hour < et.hour)
	{
		hours = et.hour - hour;
	}
	std::cout << std::endl << "Total hours car rented: " << hours << std::endl;
	return hours;
}