#pragma once
#include <fstream>
#include "Person.h"
#include "Client.h"
#include "Validation.h"


class Employee : public Person
{
protected:
	double salary = 0;

	int getLastID()
	{
		if (allEmployees.empty())
		{
			return 0;
		}
		else
		{
			vector<Employee>::iterator it = allEmployees.begin();
			while ( it != allEmployees.end() - 1)
			{
				it++;
			}
			Employee x = *it;
			return x.getID();
		}
	}
public:
	static vector<Employee> allEmployees;
	//Constructors
	Employee(string name, string password, double salary)
		: Person(Validation::validName(name), Validation::validPassword(password)),
		salary(Validation::validSalary(salary))
	{
		id = getLastID() + 1;
	}

	//Getters
	double getSalary() const
	{
		return salary;
	}
	//Setters
	bool setSalary(double _salary) 
	{
		if (Validation::isValidSalary(_salary))
		{
			this->salary = _salary;
			return true;
		}
		else
		{
			return false;
		}
	}
	
	void display()
	{
		cout << "Employee Name: " << name << endl
			<< "Employee ID: " << id << endl
			<< "Employee Salary: " << salary << endl
			<< "\n ================================== \n\n";
	}
	static bool addClient(Client obj)
	{
		if (isValidClient(obj))
		{
			Client::allClients.push_back(obj);
			return true;
		}
		else
		{
			return false;
		}
	}
	static Client* searchClientByID(int id) { //We return a pointer, not an object, so that we can return NULL if not found.

		Client* c = nullptr;

		for (int i = 0; i < Client::allClients.size(); i++) 
		{
			if (Client::allClients[i].getID() == id) 
			{
				c = &Client::allClients[i];
				return c;
			}
		}
		return nullptr;
	}
	void listClients() {

		for (int i = 0; i < Client::allClients.size(); i++) {

			Client::allClients[i].display();
		}
	}

	void editClient(int id, string name, string password, double balance) {

		Client* c = searchClientByID(id);
		if (c != nullptr) {

			c->setName(name);
			c->setPassword(password);
			c->setBalance(balance);
		}
		else {

			cout << "Client ID Not Found!" << endl;
		}
	}
private:
	//Validation for objects before adding them to vector.
	  static bool isValidClient(Client& obj)
	{
		if (
			Validation::isValidName(obj.getName()) &&
			Validation::isValidPassword(obj.getPassword()) &&
			Validation::isValidBalance(obj.getBalance())
			)
		{
			return true;
		}
		return false;
	}
};

