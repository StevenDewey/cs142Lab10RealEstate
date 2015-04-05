//Author: Steven Dewey
// Description: .cpp file to describe the variables and functions associated with the Property class

#include "Property.h"
#include <iomanip>

using namespace std;

int Property::counter = 0;

//---------------------------------------------------------------------------------------
Property::Property(bool rental_in, double value_in, string address_in)
{
	rental = rental_in;
	value = value_in;
	address = address_in;
	propertyID = counter;
	counter++;
}
Property::~Property(){}

//---------------------------------------------------------------------------------------
string Property::toString()
{
	stringstream ss;
	ss << "Property id: " << propertyID << " ";
	ss << "Address: " << address << " ";
	if (rental)
	{
		ss << "Rental ";
	}
	else
	{
		ss << "NOT rental ";
	}
	ss << "Estimated value: " << value << " ";
	
	return ss.str();
}
//---------------------------------------------------------------------------------------

string Property::taxReport()
{
	stringstream ss;
	ss << "** Taxes due for the property at: " << address << endl;
	ss << "Property id: " << propertyID << endl;
	ss << "This property has an estimated value of: " << value << endl;
	

	return ss.str();
}
double Property::getTaxDue()
{
	return 0;
}
