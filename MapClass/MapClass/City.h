#pragma once
#include <iostream>

using std::ostream;

class City
{
private:
	const enum {LIMIT = 90};
	char name[LIMIT];
	int population;
public:
	City();
	City(char *, int);
	~City();
	void setName(char *);
	char * getName();
	void setPopulation(int);
	int getPopulation();
	friend ostream& operator<< (ostream& os, City& C)
	{
		os << C.getName() << " " << C.getPopulation();
		return os;
	}
};

