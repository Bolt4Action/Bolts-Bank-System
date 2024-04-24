#include <iostream>
#include "Client.h"
#include "Admin.h"
#include "FilesHelper.h"
#include "FileManager.h"
#include "Parser.h"
using namespace std;

int main()
{
	Employee z("Franklin", "87654321", 100000);
	z.addClient(Client("Micheal De Santa", "Ab12345678", 5000));
	z.addClient(Client("Franklin Clinton", "Ab12345678", 5000));
	z.addClient(Client( "Trevor Philips", "Ab12345678", 5000));
	z.addClient(Client("Carl Johnson", "Ab12345678", 5000));
	z.addClient(Client("Tommy Vercetti", "Ab12345678", 5000));
	z.listClient();
	//FilesHelper::getAllClients();
	//testing client ID generation




	// 
	//testing split and reading from client database.
	//cout << Parser::split(Parser::getClientByID(1))[3];

	//testing reading from a file
	//string line = "1#Micheal#Ab12345678#5000.000000";
	//cout << stoi(line.substr(0, line.find('#')));


	//testing getLastID from Client
	//cout << Client::getLastID();
}