#ifndef SHOWOFFSETLIMIT_H_INCLUDED
#define SHOWOFFSETLIMIT_H_INCLUDED
#include "AuxiliaryFunctions.h"

void showOffsetLimit()
{
	long long int cnt = getRecordsCnt();
	cout << "Please type the limit \n";
	unsigned long long int limit;
	cin >> limit;
	cin.ignore();
	cout << "Please type the offset \n";
	unsigned long long int offset;
	cin >> offset;
	cin.ignore();
	if (limit + offset > cnt )
	{
		cout << "The sum of limit and offset can't be higher than the amount of records in the data base, which is: " << cnt << endl;
		return;
	}
	ifstream iFile;
	iFile.open("Planes.db", ios::binary);
	if (!iFile)
    {
        cerr << "File cannot be opened \n";
        return;
    }
	Record rec;
	iFile.seekg(offset*sizeof(Record),ios::beg);
	for (int i = 0; i < limit; i++)
	{
		iFile.read((char*)&rec, sizeof(Record));
		cout << rec;
	}
	iFile.close();
}

#endif // SHOWOFFSETLIMIT_H_INCLUDED
