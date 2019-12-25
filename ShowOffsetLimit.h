#ifndef SHOWOFFSETLIMIT_H_INCLUDED
#define SHOWOFFSETLIMIT_H_INCLUDED
#include "AuxiliaryFunctions.h"

void showOffsetLimit()
{
	long long int cnt = getRecordsCnt();
	cout << "Please type the limit \n";
	unsigned long long int limit;
	cin >> limit;
	cout << "Please type the offset \n";
	unsigned long long int offset;
	cin >> offset;
	if (limit + offset > cnt - 1)
	{
		cout << "The sum of limit and offset can't be higher than the amount of records in the data base, which is: " << cnt << endl;
		return;
	}
	ifstream iFile;
	iFile.open("Planes.db", ios::binary);
	Record* records = new Record[cnt];
	for (int i = 0; i < cnt; i++)
	{
		iFile.read((char*)&records[i], sizeof(Record));
	}
	iFile.close();
	for (int i = offset; i < offset + limit; i++)
	{
		cout << records[i];
	}
	delete[] records;
}

#endif // SHOWOFFSETLIMIT_H_INCLUDED
