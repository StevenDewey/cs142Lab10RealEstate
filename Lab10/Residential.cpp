#include "Residential.h"

Residential::Residential(bool rental_in, double value_in, bool vacant_in, string address_in)
	:Property(rental_in, value_in, address_in)
{
	vacant = vacant_in;
}

string Residential::toString()
{
	stringstream ss;
	ss << Property::toString();
	if (vacant)
	{
		ss << " occupied ";
	}
	else
	{
		ss << " NOT occupied ";
	}
	return ss.str();
}