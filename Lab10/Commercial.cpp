#include "Commercial.h"

Commercial::Commercial(bool rental_in, double value_in, bool bdiscount_in, string address_in, double discount_in)
	:Property(rental_in, value_in, address_in)
{
	discount = discount_in;
	bdiscount = bdiscount_in;
}
Commercial::~Commercial(){}

//---------------------------------------------------------------------------------------
string Commercial::toString()
{
	stringstream ss;
	ss << Property::toString();
	if (bdiscount)
	{
		ss << "Discounted ";
		ss << "Discount " << discount << " ";
	}
	else
	{
		ss << "Not discounted ";
	}
	return ss.str();
}
//----------------