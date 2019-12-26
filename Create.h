#ifndef CREATE_H_INCLUDED
#define CREATE_H_INCLUDED
#include "AuxiliaryFunctions.h"

void createRecord()
{
	cout << "Please type the new record's desired Id\n";
	unsigned long long int Id;
	cin >> Id;
	cin.ignore();
	long long int a = recordPosition(Id);
	if (a > -1)
	{
		cout << "A record with this Id already exists in the data base\n";
		return;
	}
	ofstream oFile;
	oFile.open("Planes.db", ios::app | ios::binary);
	if (!oFile.good())
	{
		cerr << "File could not be opened\n";
		return;
	}
	cout << "Please type the Plane\n";
	char Plane[257];
	cin.getline(Plane, 257);
	cout << "Please type the type \n";
	char Type[257];
	cin.getline(Type, 257);
	cout << "Please type the number of flights\n";
	unsigned long long int Flights;
	cin >> Flights;
	cin.ignore();
	Record record(Id, Plane, Type, Flights);
	oFile.write((const char*)&record, sizeof(Record));
	oFile.close();

}

#endif // CREATE_H_INCLUDED
