#include "Commercial.h"

double const TAXCOMRENT = 0.012;
double const TAXCOMNOT = 0.01;

Commercial::Commercial(bool rental_in, double value_in, bool bdiscount_in, string address_in, double discount_in)
	:Property(rental_in, value_in, address_in)
{
	discount = discount_in;
	bdiscount = bdiscount_in;
	newValue = value_in;
	newRental = rental_in;
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
		newValue = newValue * (1 - discount);

		if (newRental)
		{
			taxDue = newValue * TAXCOMRENT;
		}
		else
		{
			taxDue = newValue * TAXCOMNOT;
		}
	}
	else
	{
		if (newRental)
		{
			taxDue = newValue * TAXCOMRENT;
		}
		else
		{
			taxDue = newValue * TAXCOMNOT;
		}
	}
	

	ss << "Taxes due on this property are: " << taxDue << endl;

	return ss.str();
}
double Commercial::getTaxDue()
{
	return taxDue;
}