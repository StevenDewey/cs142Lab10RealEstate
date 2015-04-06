#include "Property.h"
//#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Residential : public Property
{
	private:
		bool vacant;
		double taxDue;
	public:
		//---------------------------------------------------------------------------------------
		/* 
		 * Constructor/Destructor
		 * 
		 * Handles creation and deletion of Residential Property objects.
		 * 
		 */
		Residential(bool rental_in, double value_in, bool vacant_in, string address_in);
		~Residential();
		string taxReport();
		double getTaxDue();
		//---------------------------------------------------------------------------------------
		/* 
		 * toString
		 * 
		 * This function returns a string that has all of the information about the property.
		 * 
		 * Return:
		 *		A data string about this property
		 */
		string toString();
		//---------------------------------------------------------------------------------------
};
