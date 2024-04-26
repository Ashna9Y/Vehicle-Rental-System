#include "Date.h"
#include <iostream>
DATE::DATE(int d, int m, int y)//date constructor
{
	date = d;
	month = m;
	year = y;
}
void DATE::dispaly()
{
	//displaying date 
	std::cout << " " << date << "/" << month << "/" << year << std::endl;
	return;
}
int DATE::days(DATE& ed)
{
	//coutning number of days from start and end date 
	int days = 0;
	if (year == ed.year)
	{
		if (month == ed.month)
		{
			days = ed.date - date + 1;
		}
		else if (month == 1 && ed.month == 2)
		{
			days = (31 - date + 1) + (ed.date) + 1;
		}
		else if (month == 2 && ed.month == 3)
		{
			days = (28 - date + 1) + (ed.date) + 1;
		}
		else if (month == 3 && ed.month == 4)
		{
			days = (31 - date + 1) + (ed.date) + 1;
		}
		else if (month == 4 && ed.month == 5)
		{
			days = (30 - date + 1) + (ed.date) + 1;
		}
		else if (month == 5 && ed.month == 6)
		{
			days = (31 - date + 1) + (ed.date) +1;
		}
		else if (month == 6 && ed.month == 7)
		{
			days = (30 - date + 1) + (ed.date) +1;
		}
		else if (month == 7 && ed.month == 8)
		{
			days = (31 - date + 1) + (ed.date) +1;
		}
		else if (month == 8 && ed.month == 9)
		{
			days = (31 - date + 1) + (ed.date) +1;
		}
		else if (month == 9 && ed.month == 10)
		{
			days = (30 - date + 1) + (ed.date) +1;
		}
		else if (month == 10 && ed.month == 11)
		{
			days = (31 - date + 1) + (ed.date) +1;
		}
		else if (month == 11 && ed.month == 12)
		{
			days = (30 - date + 1) + (ed.date) +1;
		}

	}

	else if (ed.year == year + 1)
	{
		if (month == 12 && ed.month == 1)
		{
			days = (31 - date + 1) + (ed.date) + 1;
		}
	}

	std::cout << std::endl << "Number of days car rented: " << days << std::endl;
	return days;
}
