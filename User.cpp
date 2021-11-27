#include "User.h"

User::User()
{
    
}
User::User(string id, string name, string email, string phone)
{
	this -> id = id;
	this -> name = name;
	this -> email = email;
	this -> phone = phone;
}

string User::get_id()
{
	return id;
}
void User::set_id(string id)
{
	this -> id = id;
}

string User::get_name()
{
	return name;
}

void User::set_name(string name)
{
	this -> name = name;
}

string User::get_email()
{
	return email;
}

void User::set_email(string email)
{
	this -> email = email;
}

string User::get_phone()
{
	return phone;
}

void User::set_phone(string phone)
{
	this -> phone = phone;
}
