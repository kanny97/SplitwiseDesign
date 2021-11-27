#pragma once
#include <string>
using namespace std;

class User
{
private:
	string id;
	string name;
	string email;
	string phone;
public:
    User();
	User(string id, string name, string email, string phone);
	string get_id();
	void set_id(string id);
	string get_name();
	void set_name(string name);
	string get_email();
	void set_email(string email);
	string get_phone();
	void set_phone(string phone);
};