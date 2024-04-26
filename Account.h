#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>

class account
{
protected:
	std::string name;
	std::string password;
public:
	account();
	account(std::string, std::string);
	virtual void display() = 0;
	~account() {};
};


class account_user : public account
{
private:
	std::string contact_num;
	std::string city;
public:
	account_user();
	account_user(std::string, std::string, std::string , std::string);
	void display();
	bool checkaccount_user(std::string, std::string);
};


class account_admin :public account
{
private:
	int admin_id;
public:
	account_admin();
	account_admin(std::string, std::string, int);
	void display();
	bool checkaccount_admin(std::string, std::string);
};

#endif //ACCOUNT_H
