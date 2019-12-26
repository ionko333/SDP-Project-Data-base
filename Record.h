#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED

#include <iostream>
#include <cstring>

using namespace std;

class Record
{
private:
	unsigned long long int Index;
    unsigned long long int Id;
	char Plane[257];
	char Type[257];
	long long unsigned int Flights;
public:

	Record(long long unsigned int, const char[257], const char[257], long long unsigned int, unsigned long long int);
	friend ostream& operator<<(ostream& os, const Record& rec);
	unsigned long long int getIndex()const { return Index; }
	unsigned long long int getId()const { return Id; }
	unsigned long long int getFlights()const { return Flights; }
	const char* getPlane()const{return Plane;}
	const char* getType()const{return Type;}
	void setIndex(unsigned long long int newIndex) { Index = newIndex; }
	void setId(unsigned long long int newId) { Id = newId; }
	void setPlane(const char* newPlane) { strcpy(Plane,newPlane); }
	void setType(const char* newType) { strcpy(Type,newType); }
	void setFlights(unsigned long long int newFlights) { Flights = newFlights; }
};
Record::Record(long long unsigned int _Id = 0, const char _Plane[257] = "",
	const char  _Type[257] = "", long long unsigned int _Flights = 0, unsigned long long int _Index = 0)
{
    Index = _Index;
	Id = _Id;
	Flights = _Flights;
	strcpy(Plane,_Plane);
	strcpy(Type,_Type);

}
ostream&operator<<(ostream& os, const Record& rec)
{
	os << rec.getId() << " " << rec.getPlane() << " " << rec.getType() << " " << rec.getFlights() << '\n';
	return os;
}


#endif // RECORD_H_INCLUDED
