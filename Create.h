#ifndef CREATE_H_INCLUDED
#define CREATE_H_INCLUDED
#include "AuxiliaryFunctions.h"

void createRecord(unsigned long long int Id,long long int& cntRecords)
{
	ofstream oFile;
	oFile.open("Planes.db", ios::app | ios::binary);
	if (!oFile.good())
	{
		cerr << "File could not be opened\n";
		return;
	}
	cout << "Please type the Plane\n";
	char Plane[257];
	cin.getline(Plane, 256);
	//cout << "plane name read: \"" << Plane << "\"" << endl;
	//cin.ignore();
	cout << "Please type the type \n";
	char Type[257];
	cin.getline(Type, 256);
	//cout << "plane type read: \"" << Type << "\"" << endl;
	//cin.ignore();
	cout << "Please type the number of flights\n";
	unsigned long long int Flights;
	cin >> Flights;
	cin.ignore();
	//cout << "number of flights read: " << Flights << endl;
	Record record(Id, Plane, Type, Flights);
	oFile.write((const char*)&record, sizeof(Record));
	oFile.close();
	++cntRecords;
}

#endif // CREATE_H_INCLUDED
