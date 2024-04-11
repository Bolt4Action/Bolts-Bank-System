#pragma once
#include <iostream>
#include <string>
using namespace std;


class Validation
{
public:
	//Validation for Setters (Refuses to work if the input is invalid)
	static bool isValidName(const string& name)
	{
		if ((name.length() >= 5 && name.length() <= 20) && isAlphaOrSpace(name))
		{
			return true;
		}
		return false;
	}
	static bool isValidPassword(const string& password)
	{
		if (password.length() >= 8 && password.length() <= 20)
		{
			return true;
		}
		return false;
	}
	static bool isValidBalance(const double& balance)
	{
		if (balance >= 1500)
		{
			return true;
		}
		return false;
	}
	static bool isValidSalary(const double& salary)
	{
		if (salary >= 5000)
		{
			return true;
		}
		return false;
	}

	//Validation for the Constructor (Creates an Object with Invalid Properties if the parameters are invalid)
static string validName(const string& _name)
{
	if (isValidName(_name))
	{
	return _name;
	}
	return "Invalid Name";
}
static string validPassword(const string& _password)
{
	if (isValidPassword(_password))
	{
		return _password;
	}	
	return "Invalid Password";
}
static double validBalance(const double& _balance)
{
	if (isValidBalance(_balance))
	{
		return _balance;
	}
	return -1;
}
static double validSalary(const double& _salary)
{
	if (isValidSalary(_salary))
	{
		return _salary;
	}
	return -1;
}


private:
	static bool isAlphaOrSpace(const string& string)
	{
		for (char c : string)
		{
			if (!isalpha(c) || c != ' ')
			{
				return false;
			}
		}
			return true;
	}
};