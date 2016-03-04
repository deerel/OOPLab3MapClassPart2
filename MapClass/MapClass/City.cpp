#include <iostream>

#include "City.h"


City::City()
{
}

City::City(char * name, int population)
{
	setName(name);
	setPopulation(population);
}

City::~City()
{
}

void City::setName(char * name)
{
	int stringLenght = 0;
	while (name[stringLenght] != '\0')
	{
		this->name[stringLenght] = name[stringLenght];
		stringLenght++;
		if (stringLenght > LIMIT)
			throw "City name too long.";
	}

	this->name[stringLenght] = '\0';	
}

char * City::getName()
{
	return this->name;
}

void City::setPopulation(int population)
{
	this->population = population;
}

int City::getPopulation()
{
	return population;
}
