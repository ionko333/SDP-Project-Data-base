#ifndef DELETE_H_INCLUDED
#define DELETE_H_INCLUDED
#include "Create.h"

void DeleteRecord(unsigned long long int Id,long long int& cntRecords, int position)
{
	cout << "position is: " << position << endl;
	cout << "number of objects to be read: " << cntRecords << endl;
	Record * records = new Record[cntRecords];
	ifstream iFile;
	iFile.open("Planes.db",ios::binary);
	if (!iFile.good())
	{
		cerr << "File could not be opened\n";
		delete[] records;
		return;
	}
	for (int i = 0; i < cntRecords; i++)
	{
		iFile.read((char*)&records[i], sizeof(Record));
		cout << "Reading: " << records[i].Id << " " << records[i].Plane << " " << records[i].Type << " " << records[i].Flights << endl;
	}
	iFile.close();
	ofstream oFile;
	oFile.open("Planes.db",ios::binary);
	if (!oFile.good())
	{
		cerr << "File could not be opened\n";
		delete[] records;
		return;
	}
	for (int i = 0; i < position; ++i)
	{
		oFile.write((char*)&records[i], sizeof(Record));
		cout << "Writing: " << records[i].Id << " " << records[i].Plane << " " << records[i].Type << " " << records[i].Flights << endl;
	}
	for (int i = position + 1; i < cntRecords; ++i)
	{
		oFile.write((char*)&records[i], sizeof(Record));
		cout << "Writing: " << records[i].Id << " " << records[i].Plane << " " << records[i].Type << " " << records[i].Flights << endl;
	}
	oFile.close();
	delete[] records;
	cout << "Record deleted successfully!\n";
	--cntRecords;
}


#endif // DELETE_H_INCLUDED
