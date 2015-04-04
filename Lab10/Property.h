//Author: Steven Dewey
//Description: Declaring the Player class and all variables and functions that make up the class.

#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Property
{
	private:
		bool rental;
		double value;
		string address;
		static int counter;
		int propertyID;
	public:
		//---------------------------------------------------------------------------------------
		/* 
		 * Constructor/Destructor
		 * 
		 * Handles creation and deletion of Property objects.
		 * 
		 * Parameter: address_in
		 *		The address of a new Property
		 */
		Property(bool rental_in, double value_in, string address_in);
		~Property();
		
		//---------------------------------------------------------------------------------------
		/* 
		 * toString
		 * 
		 * This function returns a string that has all of the information about the property.
		 * 
		 * Return:
		 *		A data string about this property
		 */
		virtual string toString();
		//---------------------------------------------------------------------------------------
};