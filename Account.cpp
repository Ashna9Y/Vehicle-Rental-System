#include "Account.h"
#include <iostream>
account::account() //account constructor for initializing object
{
	name = " ";
	password = " ";
}
account::account(std::string n, std::string p)
{
	//account constructor for assigning values to object 
	name = n;
	password = p;
}

account_user::account_user() :account()//user account constructor for initializing object
{
	contact_num = " ";
	city = " ";
}

account_user::account_user(std::string nu, std::string pu, std::string cn, std::string c) :account(nu,pu)
{
	//user account constructor for assigning values to object 
	contact_num = cn;
	city = c;
}
void account_user::display()
{
	//displaying user account details
	std::cout << std::endl << "User details: ";
	std::cout << std::endl << "Name: "<<name;
	std::cout << std::endl << "Contact number: "<<contact_num;
	std::cout << std::endl << "City: " << city << std::endl;
	return;
}

bool account_user::checkaccount_user(std::string un_check, std::string up_check)
{
	//check if user account exists
	return (name == un_check && password == up_check);
}


account_admin::account_admin():account()//admin account constructor for initializing object
{
	admin_id = 0;
}

account_admin::account_admin(std::string an, std::string ap, int aid):account(an,ap)
{
	//admin account constructor for assigning values to object 
	admin_id = aid;
}

void account_admin::display()
{
	//displaying admin account details
	std::cout << std::endl << "Admin details: ";
	std::cout << std::endl << "Name: " << name;
	std::cout << std::endl << "Id: " << admin_id << std::endl;
	return;
}

bool account_admin::checkaccount_admin(std::string an_check, std::string ap_check)
{
	//check if admin account exists
	return (name == an_check && password == ap_check);
}
