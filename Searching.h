#ifndef SEARCHING_H_INCLUDED
#define SEARCHING_H_INCLUDED
#include "AuxiliaryFunctions.h"

long long int binarySearch(ifstream& iFile, int l, int r, unsigned long long int Id)
{
	if (r >= 1) {
		Record temp;
		int mid = getRecordsCnt() / 2;
		iFile.seekg(mid * sizeof(Record), ios::beg);
		iFile.read((char*)&temp, sizeof(Record));
		if (temp.Id == Id)
		{
			return mid;
		}
		if (temp.Id > Id)
		{
			return binarySearch(iFile, l, mid - 1, Id);
		}
		return binarySearch(iFile, mid + 1, r, Id);
	}
	return -1;
}


void optimalSearch()
{
	cout << "Please type the record's Id\n";
	unsigned long long int Id;
	cin >> Id;
	cin.ignore();
	ifstream iFile;
	iFile.open("Planes.db", ios::binary);
	long long int size = getRecordsCnt();
	if (!iFile.good())
	{
		cerr << "File cannot be opened\n";
		return;
	}
	long long int position = binarySearch(iFile, 0, size - 1, Id);
	if (position == -1)
	{
		cout << "A record with such Id does not exist in this data base\n";
		return;
	}
	Record t;
	iFile.seekg(position * sizeof(Record), ios::beg);
	iFile.read((char*)&t, sizeof(Record));
	cout << t;
	iFile.close();
}

void normalSearch()
{
	cout << "Please enter the Id of the record you are looking for \n";
	unsigned long long int Id;
	cin >> Id;
	cin.ignore();
	long long int size = getRecordsCnt();
	Record t;
	ifstream iFile;
	iFile.open("Planes.db", ios::binary);
	if (!iFile.good())
	{
		cerr << "File cannot be opened \n";
		return;
	}
	for (int i = 0; i < size; i++)
	{
		iFile.read((char*)&t, sizeof(Record));
		if (t.Id == Id)
		{
			cout << t;
			iFile.close();
			break;
		}
	}
	iFile.close();
}

#endif // SEARCHING_H_INCLUDED
