#ifndef UPDATE_H_INCLUDED
#define UPDATE_H_INCLUDED
#include "AuxiliaryFunctions.h"


void updateAttribute(bool isOptimized)
{
	long long int numOfRecords = getRecordsCnt();
	if (numOfRecords == 0)
	{
		cout << "Data base is empty\n";
		return;
	}
	cout << "Please type the Id of the record you want to update\n";
	unsigned long long int Id;
	cin >> Id;
	cin.ignore();
	int pos = recordPosition(Id);
	if (pos == -1)
	{
		cout << "A record with this Id does not exist in the data base\n";
		return;
	}
	string attribute;
	cout << "Please type the attribute you want to change\n";
	cin >> attribute;
	cin.ignore();
	fstream file;
	file.open("Planes.db", ios::in | ios::out | ios::binary);
	if (!file.good())
	{
		cerr << "File cannot be opened\n";
		return;
	}
	file.seekg(pos * sizeof(Record), ios::beg);
	Record rec;
	file.read((char*)&rec, sizeof(Record));
	if (attribute == "Id")
	{
		cout << "Please type the new Id for this record\n";
		unsigned long long int newId;
		cin >> newId;
		cin.ignore();
		bool alreadyExists = false;
		int newPos = recordPosition(newId);
		if (newPos > -1)
		{
			cout << "A record with the desired Id already exists in our data base \n";
			return;
		}
		rec.setId(newId);
		isOptimized = false;
	}
	else if (attribute == "Plane")
	{
		cout << "Please type the new Plane for this record\n";
		char newPlane[257];
		cin.getline(newPlane, 257);
		rec.setPlane(newPlane);
	}
	else if (attribute == "Type")
	{
		cout << "Please type the new Type for this record\n";
		char newType[257];
		cin.getline(newType, 257);
		rec.setType(newType);
	}
	else if (attribute == "Flights")
	{
		cout << "Please type the new number of flights for this record\n";
		unsigned long long int newFlights;
		cin >> newFlights;
		cin.ignore();
		rec.setFlights(newFlights);
	}
	file.seekp(pos * sizeof(Record), ios::beg);
	if (!file.good())
	{
		cerr << "File is not good xD \n";
		return;
	}
	file.write((const char*)&rec, sizeof(Record));
	cout << "Update was successful \n";
	file.close();
}
#endif // UPDATE_H_INCLUDED
