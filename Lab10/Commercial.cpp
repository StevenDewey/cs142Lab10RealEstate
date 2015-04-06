#include "Commercial.h"

double const TAXCOMRENT = 0.012;
double const TAXCOMNOT = 0.01;

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
string Commercial::taxReport()
{
	stringstream ss;
	ss << Property::taxReport();

	if (bdiscount)
	{
		value = value * (1 - discount);

		if (rental)
		{
			taxDue = value * TAXCOMRENT;
		}
		else
		{
			taxDue = value * TAXCOMNOT;
		}
	}
	else
	{
		if (rental)
		{
			taxDue = value * TAXCOMRENT;
		}
		else
		{
			taxDue = value * TAXCOMNOT;
		}
	}
	

	ss << "Taxes due on this property are: " << taxDue << endl;

	return ss.str();
}
double Commercial::getTaxDue()
{
	return taxDue;
}