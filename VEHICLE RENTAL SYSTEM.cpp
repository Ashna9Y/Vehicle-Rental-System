#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Vehicle.h"
#include "Account.h"
#include "Date.h"
#include "Time.h"

using namespace std;
int choice = 0;

int main()
{
	//initializing pointers
	account_user* user_account_ptr = new account_user();
	account_admin* admin_account_ptr = new account_admin();
	Car* car_ptr = new Car();
	Bike* bike_ptr = new Bike();

	//program starts here
	cout << endl << " ********************************************************** ";
	cout << endl << " *                                                        * ";
	cout << endl << " *         WELCOME TO VEHICLE RENTAL SYSTEM               * ";
	cout << endl << " *                                                        * ";
	cout << endl << " ********************************************************** ";
	cout << endl;

	start://label
	cout << endl << " ********************************************************** ";
	cout << endl << " *                  1.USER                                * ";
	cout << endl << " *                  2.ADMIN                               * ";
	cout << endl << " ********************************************************** ";
	cout << endl;
	cout << "Enter choice: ";
	cin >> choice;

	fstream file; //creating file stream

	if (choice == 1)
	{
		//if user
		cout << endl;
		cout << endl << " ********************************************************** ";
		cout << endl << " *                  1.ADD ACCOUNT FOR USER                * ";
		cout << endl << " *                  2.LOGIN - USER                        * ";
		cout << endl << " ********************************************************** ";
		cout << endl;
		int choice1;
		cout << "Enter choice: ";
		cin >> choice1;
		if (choice1 == 1)
		{
			//making and adding new account
			int i;
			string uname, ucity, upassword, cnumber;
			cout << endl << "Enter account number: ";
			cin >> i;
			cout << endl << "Enter user name: ";
			cin.ignore();
			getline(cin, uname);
			cout << "Enter user contact number: ";
			cin >> cnumber;
			cout << "Enter user city: ";
			cin.ignore();
			getline(cin, ucity);
			cout << "Enter password: ";
			cin.ignore();
			getline(cin, upassword);
			user_account_ptr = new account_user(uname, upassword, cnumber, ucity);
			file.open("USER_FILE.dat", ios::out | ios::app | ios::binary);
			file.write(reinterpret_cast<char*>(&(*user_account_ptr)), sizeof(account_user));
			file.close();
			cout << endl << "ACCOUNT ADDED SUCCESSFULLY!" << endl;
			goto mainmenu;
		}
		else if (choice1 == 2)
		{
			//login if account exists 
			string uname_check, upassword_check;
			cout << endl << "Enter user name: ";
			cin.ignore();
			getline(cin, uname_check);
			cout << endl << "Enter password: ";
			cin.ignore();
			getline(cin, upassword_check);
			file.open("USER_FILE.dat", ios::in | ios::binary);
			vector<account_user> users_vector;
			while (file.read(reinterpret_cast<char*>(&(*user_account_ptr)), sizeof(account_user)))
			{
				users_vector.push_back(*user_account_ptr);
			}
			for (int i = 0; i < users_vector.size() ; i ++)
			{
				if (users_vector[i].checkaccount_user(uname_check, upassword_check))
				{
					cout << endl << "LOGIN SUCCESSFULL!";
					file.close();
					users_vector.clear();
					goto mainmenu;
				}
				else
				{
					cout << endl << "Invalid credentials!" << endl;
					goto start;
				}
			}
			users_vector.clear();
		}
		else
		{
			cout << endl << "WRONG CHOICE!" << endl;
			goto start;
		}

	}
	else if (choice == 2)
	{
		//for admin
		cout << endl;
		cout << endl << " ********************************************************** ";
		cout << endl << " *                  1.ADD ACCOUNT FOR ADMIN               * ";
		cout << endl << " *                  2.LOGIN - ADMIN                       * ";
		cout << endl << " ********************************************************** ";
		cout << endl;
		int choice1;
		cout << "Enter choice: ";
		cin >> choice1;
		if (choice1 == 1)
		{
			//making and adding new account
			int i;
			string aname, apassword;
			int a_id;
			cout << endl << "Enter account number: ";
			cin >> i;
			cout << endl << "Enter admin name: ";
			cin.ignore();
			getline(cin, aname);
			cout << "Enter password: ";
			cin.ignore();
			getline(cin, apassword);
			cout << "Enter admin id: ";
			cin >> a_id;
			admin_account_ptr = new account_admin(aname, apassword, a_id);
			file.open("ADMIN_FILE.dat", ios::out | ios::app | ios::binary);
			file.write(reinterpret_cast<char*>(&(*admin_account_ptr)), sizeof(account_admin));
			file.close();
			cout << endl << "ACCOUNT ADDED SUCCESSFULLY!" << endl;
			goto adminmenu;
		}
		else if (choice1 == 2)
		{
			//login if account exists for admin 
			string aname_check, apassword_check;
			cout << endl << "Enter admin name: ";
			cin.ignore();
			getline(cin, aname_check);
			cout << endl << "Enter password: ";
			cin.ignore();
			getline(cin, apassword_check);
			file.open("ADMIN_FILE.dat", ios::in | ios::binary);
			vector<account_admin> admin_vector;
			while (file.read(reinterpret_cast<char*>(&(*admin_account_ptr)), sizeof(account_admin)))
			{
				admin_vector.push_back(*admin_account_ptr);
			}
			for (int i = 0; i < admin_vector.size(); i++)
			{
				if (admin_vector[i].checkaccount_admin(aname_check, apassword_check))
				{
					cout << endl << "LOGIN SUCCESSFULL!";
					file.close();
					admin_vector.clear();
					goto adminmenu;
				}
			}
			admin_vector.clear();
		}
		else
		{
			cout << endl << "WRONG CHOICE!" << endl;
			goto start;
		}
	}

mainmenu: //if login of user is successfull and after account creation
	cout << endl;
	cout << endl << " ********************************************************** ";
	cout << endl << " *                  USER MAIN MENU                        * ";
	cout << endl << " *                  1.RENT VEHICLE                        * ";
	cout << endl << " *                  2.EXIT                                * ";
	cout << endl << " ********************************************************** ";
	cout << endl;
	cout << "Enter choice: ";
	cin >> choice;
	if (choice == 1)
	{
		//renting
		string vehicle_type;
		cout << "Are you renting car or bike?";
		cin >> vehicle_type;
		if (vehicle_type == "car")
		{
			//renting car
			int choice2;
			cout << "Are you renting it on daily basis(1) or hourly basis(2)? ";
			cin >> choice2;
			if (choice2 == 1)
			{
				//daily basis

				//calculating days
				int date_i, month_i, year_i;
				cout << "Enter start date month year: ";
				cin >> date_i >> month_i >> year_i;
				DATE start_date(date_i, month_i, year_i);
				cout << "Enter end date month year: ";
				cin >> date_i >> month_i >> year_i;
				DATE end_date(date_i, month_i, year_i);
				int total_days = start_date.days(end_date);

				double upper_limit;
				cout << "Enter upper limit for daily rental price you prefer: ";
				cin >> upper_limit;
				file.open("CAR_FILE.dat", ios::in | ios::binary);
				vector<Car> car_vector;
				while(file.read(reinterpret_cast<char*>(&(*car_ptr)), sizeof(Car)))
				{
					car_vector.push_back(*car_ptr);
				}
				for (int i = 0; i < car_vector.size(); i++)
				{
					if (car_vector[i].display_in_range_days(upper_limit))
					{
					}
				}
				car_vector.clear();
				file.close();
				int cnum;
				cout << "Enter car number you like to rent: ";
				cin >> cnum;
				cout << endl << "************YOUR RECIEPT*******************";
				file.open("CAR_FILE.dat", ios::in | ios::binary);
				while (file.read(reinterpret_cast<char*>(&(*car_ptr)), sizeof(Car)))
				{
					car_vector.push_back(*car_ptr);
				}
				for (int i = 0; i < car_vector.size(); i++)
				{
					if (car_vector[i].display_selected_car(cnum))
					{
						rent_days(car_vector[i], total_days);
					}
					file.close();
				}
				cout << endl;
				car_vector.clear();
				goto mainmenu;
			}
			else if (choice2 == 2)
			{
				//hourly basis

				//calculating hours
				int hour_i,minute_i;
				cout << "Enter start time(hour and minute): ";
				cin >> hour_i >> minute_i;
				TIME start_time(hour_i, minute_i);
				cout << "Enter end time(hour and minute): ";
				cin >> hour_i >> minute_i;
				TIME end_time(hour_i, minute_i);
				int total_hours = start_time.total_hours(end_time);

				double upper_limit;
				cout << "Enter upper limit for hourly rental price you prefer: ";
				cin >> upper_limit;
				file.open("CAR_FILE.dat", ios::in | ios::binary);
				vector<Car> car_vector;
				while (file.read(reinterpret_cast<char*>(&(*car_ptr)), sizeof(Car)))
				{
					car_vector.push_back(*car_ptr);
				}
				for (int i = 0; i < car_vector.size(); i++)
				{
					if (car_vector[i].display_in_range_hours(upper_limit))
					{
						car_vector[i].display();
					}
				}
				car_vector.clear();
				file.seekg(0, ios::beg);
				int cnum;
				cout << "Enter car number you like to rent: ";
				cin >> cnum;
				cout << endl << "************YOUR RECIEPT*******************";
				while (file.read(reinterpret_cast<char*>(&(*car_ptr)), sizeof(Car)))
				{
					car_vector.push_back(*car_ptr);
				}
				for (int i = 0; i < car_vector.size(); i++)
				{
					if (car_vector[i].display_selected_car(cnum))
					{
						rent_hours(car_vector[i], total_hours);
					}
					file.close();
				}
				cout << endl;
				car_vector.clear();
				goto mainmenu;
			}
			else
			{
				cout << endl << "Invalid input!" << endl;
				goto mainmenu;
			}
		}
		else if (vehicle_type == "bike")
		{
			//renting bike

			int choice2;
			cout << "Are you renting it on daily basis(1) or hourly basis(2)? ";
			cin >> choice2;
			if (choice2 == 1)
			{
				//daily basis

				//calculating days
				int date_i, month_i, year_i;
				cout << "Enter start date month year: ";
				cin >> date_i >> month_i >> year_i;
				DATE start_date(date_i, month_i, year_i);
				cout << "Enter end date month year: ";
				cin >> date_i >> month_i >> year_i;
				DATE end_date(date_i, month_i, year_i);
				int total_days = start_date.days(end_date);

				double upper_limit;
				cout << "Enter upper limit for price per day: ";
				cin >> upper_limit;
				file.open("BIKE_FILE.dat", ios::in | ios::binary);
				vector<Bike> bike_vector;
				while (file.read(reinterpret_cast<char*>(&(*bike_ptr)), sizeof(Bike)))
				{
					bike_vector.push_back(*bike_ptr);
				}
				for (int i = 0; i < bike_vector.size(); i++)
				{
					if (bike_vector[i].display_in_range_days(upper_limit))
					{
						bike_vector[i].display();
					}
				}
				bike_vector.clear();
				file.seekg(0, ios::beg);
				int bnum;
				cout << "Enter bike number you like to rent: ";
				cin >> bnum;
				cout << endl << "************YOUR RECIEPT*******************";
				while (file.read(reinterpret_cast<char*>(&(*bike_ptr)), sizeof(Bike)))
				{
					bike_vector.push_back(*bike_ptr);
				}
				for (int i = 0; i < bike_vector.size(); i++)
				{
					if (bike_vector[i].display_selected_bike(bnum))
					{
						rent_days(bike_vector[i], total_days);
					}
					file.close();
				}
				bike_vector.clear();
				cout << endl;
				goto mainmenu;
			}
			else if (choice2 == 2)
			{
				//hourly basis
				//calculating hours
				int hour_i, minute_i;
				cout << "Enter start time(hour and minute): ";
				cin >> hour_i >> minute_i;
				TIME start_time(hour_i, minute_i);
				cout << "Enter end time(hour and minute): ";
				cin >> hour_i >> minute_i;
				TIME end_time(hour_i, minute_i);
				int total_hours = start_time.total_hours(end_time);

				double upper_limit;
				cout << "Enter upper limit for hourly rental price you prefer: ";
				cin >> upper_limit;
				file.open("BIKE_FILE.dat", ios::in | ios::binary);
				vector<Bike> bike_vector;
				while (file.read(reinterpret_cast<char*>(&(*bike_ptr)), sizeof(Bike)))
				{
					bike_vector.push_back(*bike_ptr);
				}
				for (int i = 0; i < bike_vector.size(); i++)
				{
					if (bike_vector[i].display_in_range_hours(upper_limit))
					{
						bike_vector[i].display();
					}
				}
				bike_vector.clear();
				file.seekg(0, ios::beg);
				int bnum;
				cout << "Enter bike number you like to rent: ";
				cin >> bnum;
				cout << endl << "************YOUR RECIEPT*******************";
				while (file.read(reinterpret_cast<char*>(&(*bike_ptr)), sizeof(Bike)))
				{
					bike_vector.push_back(*bike_ptr);
				}
				for (int i = 0; i < bike_vector.size(); i++)
				{
					if (bike_vector[i].display_selected_bike(bnum))
					{
						rent_hours(bike_vector[i], total_hours);
					}
					file.close();
				}
				bike_vector.clear();
				cout << endl;
				goto mainmenu;
			}
			else
			{
				cout << endl << "Invalid input!" << endl;
				goto mainmenu;
			}
		}
		else
		{
			cout << endl << "INVALID INPUT!" << endl;
			goto mainmenu;
		}
	}
	else if (choice == 2)
	{

		return 0;
	}
	else
	{
		//invalid choice
		cout << endl << "INVALID CHOICE!" << endl;
		goto start;
	}

adminmenu: //if admin login is successful
	cout << endl;
	cout << endl << " ********************************************************** ";
	cout << endl << " *                  ADMIN MAIN MENU                       * ";
	cout << endl << " *                  1.ADD VEHICLE                         * ";
	cout << endl << " *                  2.VIEW VEHICLE LIST                   * ";
	cout << endl << " *                  3.DELETE VEHICLE                      * ";
	cout << endl << " *                  4.EXIT                                * ";
	cout << endl << " ********************************************************** ";
	cout << endl;
	cout << "Enter choice: ";
	cin >> choice;
	if (choice == 1)
	{
		addvehicle: //label
		//adding vehicle
		cout << endl;
		cout << endl << " ********************************************************** ";
		cout << endl << " *                  ADD VEHICLE                           * ";
		cout << endl << " *                  1.ADD CAR                             * ";
		cout << endl << " *                  2.ADD BIKE                            * ";
		cout << endl << " ********************************************************** ";
		cout << endl;
		cout << "Enter choice: ";
		cin >> choice;
		if (choice == 1)
		{
			//adding car 
			string brand_add, model_add, fuel_type_add, drive_type_add,drive_experience_add;
			double rentalpriceperday_add, rentalpriceperhour_add, mileage_add;
			int seat_add , car_number;
			cout << endl << "Enter car number: ";
			cin >> car_number;
			cout << endl << "Enter brand: ";
			cin.ignore();
			getline(cin, brand_add);
			cout << endl << "Enter model: ";
			cin.ignore();
			getline(cin, model_add);
			cout << endl << "Enter rental price per day: ";
			cin >> rentalpriceperday_add;
			cout << endl << "Enter rental price per hour: ";
			cin >> rentalpriceperhour_add;
			cout << endl << "Enter mileage: ";
			cin >> mileage_add;
			cout << endl << "Enter fuel type: ";
			cin.ignore();
			getline(cin, fuel_type_add);
			cout << endl << "Enter seat number: ";
			cin >> seat_add;
			cout << endl << "Enter drive type: ";
			cin.ignore();
			getline(cin, drive_type_add);
			cout << endl << "Enter drive experience: ";
			cin.ignore();
			getline(cin, drive_experience_add);
			car_ptr = new Car(car_number, brand_add, model_add, rentalpriceperday_add, rentalpriceperhour_add, mileage_add, fuel_type_add, seat_add, drive_type_add, drive_experience_add);
			file.open("CAR_FILE.dat", ios::out | ios::app | ios::binary);
			file.write(reinterpret_cast<char*>(&(*car_ptr)), sizeof(Car));
			cout << endl << "Car added sucessfully!" << endl;
			file.close();
			int j;
			cout << "Add another vehicle(1) or exit(2)? ";
			cin >> j;
			if (j == 1)
			{
				goto addvehicle;
			}
			else
			{
				goto adminmenu;
			}
		}
		else if (choice == 2)
		{
			//adding bike
			string brand_add, model_add, fuel_type_add, type_add;
			double rentalpriceperday_add, rentalpriceperhour_add, mileage_add;
			int bike_number;
			cout << endl << "Enter bike number: ";
			cin >> bike_number;
			cout << endl << "Enter brand: ";
			cin.ignore();
			getline(cin, brand_add);
			cout << endl << "Enter model: ";
			cin.ignore();
			getline(cin, model_add);
			cout << endl << "Enter rental price per day: ";
			cin >> rentalpriceperday_add;
			cout << endl << "Enter rental price per hour: ";
			cin >> rentalpriceperhour_add;
			cout << endl << "Enter mileage: ";
			cin >> mileage_add;
			cout << endl << "Enter fuel type: ";
			cin.ignore();
			getline(cin, fuel_type_add);
			cout << endl << "Enter type: ";
			cin.ignore();
			getline(cin, type_add);
			bike_ptr = new Bike(bike_number, brand_add, model_add, rentalpriceperday_add, rentalpriceperhour_add, mileage_add, fuel_type_add, type_add);
			file.open("BIKE_FILE.dat", ios::out | ios::app | ios::binary);
			file.write(reinterpret_cast<char*>(&(*bike_ptr)), sizeof(Bike));
			cout << endl << "Bike added sucessfully!" << endl;
			file.close();
			int j;
			cout << "Add another vehicle(1) or exit(2)? ";
			cin >> j;
			if (j == 1)
			{
				goto addvehicle;
			}
			else
			{
				goto adminmenu;
			}
		}
		else
		{
			cout << endl << "Invalid vehicle type!" << endl << "Re-enter choice: " << endl;
			goto addvehicle;
		}
	}

	else if (choice == 2)
	{
		cout << endl << "******** LIST OF CARS: ********" << endl;
		file.open("CAR_FILE.dat", ios::in | ios::binary);
		vector<Car> car_vector;
		while(file.read(reinterpret_cast<char*>(&(*car_ptr)), sizeof(Car)))
		{
			car_vector.push_back(*car_ptr);
		}
		for (int i = 0; i < car_vector.size(); i++)
		{
			cout << endl;
			car_vector[i].display();
			cout << endl;
		}
		car_vector.clear();
		file.close();
		cout << endl << "******** LIST OF BIKES: ********" << endl;
		file.open("BIKE_FILE.dat", ios::in | ios::binary);
		vector<Bike>bike_vector;
		while(file.read(reinterpret_cast<char*>(&(*bike_ptr)), sizeof(Bike)))
		{
			bike_vector.push_back(*bike_ptr);
		}
		for (int i = 0; i < bike_vector.size(); i++)
		{
			cout << endl;
			bike_vector[i].display();
			cout << endl;
		}
		bike_vector.clear();
		file.close();
		goto start;
	}
	else if (choice == 3)
	{
		//deleting vehicle
		string vehicle_type;
		cout << "Are you deleting car or bike?";
		cin >> vehicle_type;
		if (vehicle_type == "car")
		{
			//deleting car
			file.open("CAR_FILE.dat", ios::in | ios::binary);
			vector<Car> cars;
			while (file.read(reinterpret_cast<char*>(&(*car_ptr)), sizeof(Car))) 
			{
				cars.push_back(*car_ptr);
			}
			int num_to_delete;
			cout << endl << "Enter car number you like to delete: ";
			cin >> num_to_delete;
			for (int i = 0 ; i < cars.size() ; i++)
			{
				if (cars[i].delete_car(num_to_delete))
				{
				      int it = i; //index to delete
					  cars.erase(cars.begin() + it - 1);
				}
			}
			file.close();
			file.clear();

			// Rewrite the updated vector back to the file
			file.open("CARS_FILE.dat", ios::out | ios::binary | ios::trunc);
			for (int i = 0; i < cars.size(); i++)
			{
				file.write(reinterpret_cast<const char*>(&cars[i]), sizeof(Car));
			}
			file.close();
			cars.clear();
			cout << "Car with ID " << num_to_delete << " deleted successfully." << endl;
			goto adminmenu;

		}
		else if (vehicle_type == "bike")
		{
			//deleting bike
			file.open("BIKE_FILE.dat", ios::in | ios::binary);
			vector<Bike> bikes;
			while (file.read(reinterpret_cast<char*>(&(*bike_ptr)), sizeof(Bike)))
			{
				bikes.push_back(*bike_ptr);
			}
			int num_to_delete;
			cout << endl << "Enter bike number you like to delete: ";
			cin >> num_to_delete;
			for (int i = 0 ; i < bikes.size() ; i ++)
			{
				if (bikes[i].delete_bike(num_to_delete))
				{
					int it = i; //index to delete
					bikes.erase(bikes.begin() + it);
					cout << "Bike with ID " << num_to_delete << " deleted successfully." << endl;
				}
			}
			file.close();
			file.clear();
			// Rewrite the updated vector back to the file
			file.open("BIKES_FILE.dat", ios::out | ios::binary | ios::trunc);
			for (int i = 0; i < bikes.size(); i++)
			{
				file.write(reinterpret_cast<const char*>(&bikes[i]), sizeof(Bike));
			}
			file.close();
			file.clear();
			bikes.clear();
			goto adminmenu;

		}
		else
		{
			cout << endl << "INVALID INPUT!" << endl;
			goto adminmenu;
		}
	}
	else if (choice == 4)
	{
		return 0;
	}
	else
	{
		//invalid choice
		cout << endl << "INVALID CHOICE!" << endl;
	}

	delete user_account_ptr;
	delete admin_account_ptr;
	delete car_ptr;
	delete bike_ptr;
	return 0;
}


