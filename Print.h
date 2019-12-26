#ifndef PRINT_H_INCLUDED
#define PRINT_H_INCLUDED
#include "AuxiliaryFunctions.h"

void printAll()
{
	int cnt = getRecordsCnt();
	ifstream iFile;
	iFile.open("Planes.db", ios::binary);
	Record rec;
	for (int i = 0; i < cnt; i++)
	{
		iFile.read((char*)&rec, sizeof(Record));
		cout << rec;
	}
	iFile.close();
}


#endif // PRINT_H_INCLUDED
