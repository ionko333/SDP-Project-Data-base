#ifndef OPTIMIZE_H_INCLUDED
#define OPTIMIZE_H_INCLUDED
#include "AuxiliaryFunctions.h"

void merge(Record* arr, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	Record* L = new (std::nothrow) Record[n1];
	if (!L)
	{
		cerr << "Error\n";
		return;
	}
	Record* R = new (std::nothrow) Record[n2];
	if (!R)
	{
		cerr << "Error\n";
		return;
	}

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i].getId() <= R[j].getId())
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
	delete[] R;
	delete[] L;
}

void mergeSort(Record* arr, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

void optimize(bool isOptimized)
{
	if (isOptimized)
	{
		cout << "The data base is already optimized\n";
		return;
	}
	long long int size = getRecordsCnt();
	ifstream iFile;
	iFile.open("Planes.db", ios::binary);
	if (!iFile.good())
	{
		cerr << "File cannot be opened\n";
		return;
	}
	Record * records = new (std::nothrow) Record[size];
	if (!records)
	{
		cerr << "Error\n";
		return;
	}
	for (int i = 0; i < size; i++)
	{
		iFile.read((char*)&records[i], sizeof(Record));
	}
	iFile.close();
	mergeSort(records, 0, size - 1);
	ofstream oFile;
	oFile.open("Planes.db", ios::binary);
	if (!oFile.good())
	{
		cerr << "File cannot be opened\n";
		delete[] records;
		return;
	}
	for (int i = 0; i < size; i++)
	{
		records[i].setIndex(i);
	}
	for (int i = 0; i < size; i++)
	{
		oFile.write((const char*)&records[i], sizeof(Record));
	}
	oFile.close();
	isOptimized = true;
	delete[] records;
}

#endif // OPTIMIZE_H_INCLUDED
