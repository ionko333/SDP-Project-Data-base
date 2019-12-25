#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED

#include <iostream>
#include <cstring>

using namespace std;

struct Record
{
private:
	unsigned long long int Index;
public:
	long long unsigned int Id;
	char Plane[257];
	char Type[257];
	long long unsigned int Flights;
	Record(long long unsigned int, const char[257], const char[257], long long unsigned int);
	friend ostream& operator<<(ostream& os, const Record& rec);
	unsigned long long int getIndex()const { return Index; }
	void setIndex(unsigned long long int newIndex) { Index = newIndex; }
};
Record::Record(long long unsigned int _Id = 0, const char _Plane[257] = "",
	const char  _Type[257] = "", long long unsigned int _Flights = 0)
{
	Id = _Id;
	Flights = _Flights;
	int planeLength = strlen(_Plane);
	for (int i = 0; i < planeLength; i++)
	{
		Plane[i] = _Plane[i];
	}
	Plane[planeLength] = '\0';
	int typeLength = strlen(_Type);
	for (int i = 0; i < typeLength; i++)
	{
		Type[i] = _Type[i];
	}
	Type[typeLength] = '\0';
}

ostream&operator<<(ostream& os, const Record& rec)
{
	os << rec.Id << " " << rec.Plane << " " << rec.Type << " " << rec.Flights << '\n';
	return os;
}


#endif // RECORD_H_INCLUDED
