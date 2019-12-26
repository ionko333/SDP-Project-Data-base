#ifndef DELETE_H_INCLUDED
#define DELETE_H_INCLUDED
#include "Create.h"

void DeleteRecord()
{
	long long int cntRecords = getRecordsCnt();
	if (cntRecords == 0)
	{
		cout << "Cannot delete from an empty data base\n";
		return;
	}
	cout << "Please type the Id of the record you want to delete\n";
	unsigned long long int Id;
	cin >> Id;
	cin.ignore();
	if (recordPosition(Id) == -1)
	{
		cout << "A record with such Id does not exist\n";
		return;
	}
	long long int position = recordPosition(Id);
	Record * records = new (std::nothrow) Record[cntRecords];
	if (!records)
	{
		cout << "Error\n";
		return;
	}
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
		oFile.write((const char*)&records[i], sizeof(Record));
	}
	for (int i = position + 1; i < cntRecords; ++i)
	{
		oFile.write((const char*)&records[i], sizeof(Record));
	}
	oFile.close();
	delete[] records;
	cout << "Record deleted successfully!\n";
}


#endif // DELETE_H_INCLUDED
