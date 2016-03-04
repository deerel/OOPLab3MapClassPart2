#pragma once
#include <iostream>

using std::ostream;

class GeoLocation
{
private:
	float longitude;
	float latitude;
public:
	GeoLocation();
	GeoLocation(float, float);
	~GeoLocation();
	void setLongitude(float);
	float getLongitude();
	void setLatitude(float);
	float getLatitude();
	friend ostream& operator<< (ostream& os, GeoLocation & G) 
	{
		os << G.getLongitude() << " " << G.getLatitude();
		return os;
	}
	friend bool operator== (GeoLocation& L, GeoLocation& R)
	{
		return (L.getLongitude() == R.getLongitude() && L.getLatitude() == R.getLatitude());
	}
};





