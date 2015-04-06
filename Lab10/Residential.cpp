#include "Residential.h"

double const TAXRESOCC = 0.006;
double const TAXRESNOT = 0.009;

Residential::Residential(bool rental_in, double value_in, bool vacant_in, string address_in)
	:Property(rental_in, value_in, address_in)
{
	vacant = vacant_in;
	value = value_in;
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

string Residential::taxReport()
{
	stringstream ss;
	ss << Property::taxReport();
	if (vacant) 
	{
		taxDue = value * TAXRESOCC;
	}
	else
	{
		taxDue = value * TAXRESNOT;
	}
	
	ss << "Taxes due on this property are: " << taxDue << endl;

	return ss.str();
}

double Residential::getTaxDue()
{
	return taxDue;
}