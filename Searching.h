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
		if (temp.getId() == Id)
		{
			return mid;
		}
		if (temp.getId() > Id)
		{
			return binarySearch(iFile, l, mid - 1, Id);
		}
		return binarySearch(iFile, mid + 1, r, Id);
	}
	return -1;
}


void optimalSearch()
{
	int cnt = getRecordsCnt();
	if (cnt == 0)
	{
		cout << "Data base is empty \n";
		return;
	}
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
	int cnt = getRecordsCnt();
	bool found = false;
	if (cnt == 0)
	{
		cout << "Data base is empty \n";
		return;
	}
	cout << "Please enter the Id of the record you are looking for \n";
	unsigned long long int Id;
	cin >> Id;
	cin.ignore();
	long long int pos = recordPosition(Id);
	if (pos == -1)
	{
		cout << "A record with such Id does not exist \n";
		return;
	}
	Record t;
	ifstream iFile;
	iFile.open("Planes.db", ios::binary);
	if (!iFile.good())
	{
		cerr << "File cannot be opened \n";
		return;
	}
	iFile.seekg(pos*sizeof(Record),ios::beg);
	iFile.read((char*)&t,sizeof(Record));
	iFile.close();
}

#endif // SEARCHING_H_INCLUDED
