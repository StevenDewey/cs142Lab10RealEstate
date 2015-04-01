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
		string address;

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
		Property(string address_in);
		virtual ~Property();
		
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