#include <iostream>
#include <cstdlib>

#include "Map.h"
//#include "Dictionary.h"
#include "City.h"
#include "GeoLocation.h"

using namespace std;

int main()
{

	Map<GeoLocation, City> * map = new Map<GeoLocation, City>;

	// Opening file
	FILE * file;
	char * fileName = "cities100000.txt";
	fopen_s(&file, fileName, "r");

	//Buffer variables for file reader.
	char line[100];
	char cityBuffer[86];
	float longBuffer, latBuffer;
	int popBuffer;

	//Reading file line by line and adding values to Map object.
	if (file == NULL) {
		cout << "Couldn't read file.";
	}
	else {
		while (fgets(line, sizeof(line) , file) != NULL) {
			//%[^\t] reads everything until tab.
			sscanf(line, "%[^\t]%f%f%d", cityBuffer, &longBuffer, &latBuffer, &popBuffer);
			try {
				map->Add(*(new GeoLocation(longBuffer, latBuffer)), *(new City(cityBuffer, popBuffer)));
			}
			catch (const char * msg)
			{
				cout << "Error: " << msg << endl;
			}
		}
	}

	// User interface
	cout << "City-Search-O-Matic" << endl << endl;

	float longitudeInput, latitudeInput;

	cout << "Enter longitude and latitude: " << endl;
	cout << "Hint: 30.05127 101.96033" << endl;
	cout << "Longitude: ";
	cin >> longitudeInput;
	cout << "Latitude: ";
	cin >> latitudeInput;
	GeoLocation * coordsSearch = new GeoLocation(longitudeInput, latitudeInput);

	if (map->HasKey(*coordsSearch))
	{
		cout << "City found:" << endl;
		cout << (*map)[*coordsSearch] << endl;
	}
	else
	{
		cout << "No city at that location!" << endl;
	}


	cout << "\n\nEnter q to quit.";

	cout << *map;
	char endProgram;
	cin >> endProgram;
	return 0;
}