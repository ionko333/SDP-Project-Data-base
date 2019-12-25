#ifndef UPDATE_H_INCLUDED
#define UPDATE_H_INCLUDED
#include "AuxiliaryFunctions.h"


void updateId(unsigned long long int,long long  int,long long  int);
void updatePlane(char[257],long long int,long long int);
void updateType(char[257],long long int, long long int);
void updateFlights(unsigned long long int, long long int, long long int);

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
	if (attribute == "Id")
	{
		cout << "Please type the new Id for this record\n";
		unsigned long long int newId;
		cin >> newId;
		updateId(newId, numOfRecords, pos);
		isOptimized = false;
	}
	else if (attribute == "Plane")
	{
		cout << "Please type the new Plane for this record\n";
		char newPlane[257];
		cin.getline(newPlane, 256);
		updatePlane(newPlane, numOfRecords, pos);
	}
	else if (attribute == "Type")
	{
		cout << "Please type the new Type for this record\n";
		char newType[257];
		cin.getline(newType, 256);
		updateType(newType, numOfRecords, pos);
	}
	else if (attribute == "Flights")
	{
		cout << "Please type the new number of flights for this record\n";
		unsigned long long int newFlights;
		cin >> newFlights;
		updateFlights(newFlights, numOfRecords, pos);
	}
}

void updateId(unsigned long long int newId, long long int getRecordsCnt, long long int position)
{
	ifstream iFile;
	iFile.open("Planes.db", ios::binary);
	if (!iFile.good())
	{
		cerr << "File cannot be opened\n";
		return;
	}
	Record * records = new Record[getRecordsCnt];
	for (int i = 0; i < getRecordsCnt; i++)
	{
		iFile.read((char*)&records[i], sizeof(Record));
	}
	iFile.close();
	records[position].Id = newId;
	ofstream oFile;
	oFile.open("Planes.db", ios::binary);
	if (!oFile.good())
	{
		cerr << "File cannot be opened\n";
		delete[] records;
		return;
	}
	for (int i = 0; i < getRecordsCnt; i++)
	{
		oFile.write((const char*)&records[i],sizeof(Record));
	}
	cout << "Id updated successfully\n";
	oFile.close();
}

void updatePlane(char newPlane[257], long long int getRecordsCnt, long long int position)
{
	ifstream iFile;
	iFile.open("Planes.db", ios::binary);
	if (!iFile.good())
	{
		cerr << "File cannot be opened\n";
		return;
	}
	Record * records = new Record[getRecordsCnt];
	for (int i = 0; i < getRecordsCnt; i++)
	{
		iFile.read((char*)&records[i], sizeof(Record));
	}
	iFile.close();
	int length = strlen(newPlane);
	for (int i = 0; i < length; i++)
	{
		records[position].Plane[i] = newPlane[i];
	}
	records[position].Plane[length] = '\0';
	ofstream oFile;
	oFile.open("Planes.db", ios::binary);
	if (!oFile.good())
	{
		cerr << "File cannot be opened\n";
		delete[] records;
		return;
	}
	for (int i = 0; i < getRecordsCnt; i++)
	{
		oFile.write((const char*)&records[i], sizeof(Record));
	}
	cout << "Plane updated successfully\n";
	oFile.close();
}

void updateType(char newType[257], long long int getRecordsCnt, long long int position)
{
	ifstream iFile;
	iFile.open("Planes.db", ios::binary);
	if (!iFile.good())
	{
		cerr << "File cannot be opened\n";
		return;
	}
	Record * records = new Record[getRecordsCnt];
	for (int i = 0; i < getRecordsCnt; i++)
	{
		iFile.read((char*)&records[i], sizeof(Record));
	}
	iFile.close();
	int length = strlen(newType);
	for (int i = 0; i < length; i++)
	{
		records[position].Type[i] = newType[i];
	}
	records[position].Type[length] = '\0';
	ofstream oFile;
	oFile.open("Planes.db", ios::binary);
	if (!oFile.good())
	{
		cerr << "File cannot be opened\n";
		delete[] records;
		return;
	}
	for (int i = 0; i < getRecordsCnt; i++)
	{
		oFile.write((const char*)&records[i], sizeof(Record));
	}
	cout << "Type updated successfully\n";
	oFile.close();
}

void updateFlights(unsigned long long int newFlights, long long int getRecordCnt, long long int position)
{
	ifstream iFile;
	if (!iFile.good())
	{
		cerr << "File cannot be opened\n";
		return;
	}
	iFile.open("Planes.db", ios::binary);
	Record * records = new Record[getRecordCnt];
	for (int i = 0; i < getRecordCnt; i++)
	{
		iFile.read((char*)&records[i], sizeof(Record));
	}
	iFile.close();
	records[position].Flights = newFlights;
	ofstream oFile;
	oFile.open("Planes.db", ios::binary);
	if (!oFile.good())
	{
		cerr << "File cannot be opened\n";
		delete[] records;
		return;
	}
	for (int i = 0; i < getRecordCnt; i++)
	{
		oFile.write((const char*)&records[i], sizeof(Record));
	}
	cout << "Flights updated successfully\n";
	oFile.close();
	delete[] records;
}
#endif // UPDATE_H_INCLUDED
