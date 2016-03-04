#include "GeoLocation.h"

GeoLocation::GeoLocation()
{
}

GeoLocation::GeoLocation(float longitude, float latitude)
{
	setLongitude(longitude);
	setLatitude(latitude);
}

GeoLocation::~GeoLocation()
{
}

void GeoLocation::setLongitude(float longitude)
{
	this->longitude = longitude;
}

float GeoLocation::getLongitude()
{
	return longitude;
}

void GeoLocation::setLatitude(float latitude)
{
	this->latitude = latitude;
}

float GeoLocation::getLatitude()
{
	return latitude;
}
