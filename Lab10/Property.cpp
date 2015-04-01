//Author: Steven Dewey
// Description: .cpp file to describe the variables and functions associated with the Property class

#include "Property.h"
#include <iomanip>

using namespace std;

//---------------------------------------------------------------------------------------
Property::Property(string address_in)
{
	address = address_in;
	
}
Property::~Property(){}

//---------------------------------------------------------------------------------------
string Property::toString()
{
	stringstream ss;
	ss << "\nAddress: " << address << endl;
	
	return ss.str();
}
//---------------------------------------------------------------------------------------
