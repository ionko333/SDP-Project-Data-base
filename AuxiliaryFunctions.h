#ifndef AUXILIARYFUNCTIONS_H_INCLUDED
#define AUXILIARYFUNCTIONS_H_INCLUDED
#include "Record.h"
#include <fstream>

long long int getRecordsCnt()
{
	ifstream iFile;
	if (!iFile.good())
	{
		return -1;
	}
	iFile.open("Planes.db", ios::binary);
	iFile.seekg(0, ios::end);
	int cnt = iFile.tellg() / sizeof(Record);
	iFile.close();
	return cnt;
}

int recordPosition(unsigned long long int Id)
{
	int recordsCnt = getRecordsCnt();
	ifstream iFile;
	iFile.open("Planes.db", ios::binary);
	int pos = 0;
	Record rec;
	for (int i = 0; i < recordsCnt; ++i)
	{
		iFile.read((char*)&rec, sizeof(Record));
		if (Id == rec.Id)
		{
			return pos;
		}
		pos++;
	}
	iFile.close();
	return -1;
}

#endif // AUXILIARYFUNCTIONS_H_INCLUDED
