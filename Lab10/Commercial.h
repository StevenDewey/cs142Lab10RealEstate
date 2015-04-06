#include "Property.h"

class Commercial : public Property
{
	private:
		bool bdiscount;
		double discount;
		double taxDue;

	public:
		//---------------------------------------------------------------------------------------
		/* 
		 * Constructor/Destructor
		 * 
		 * Handles creation and deletion of Residential Property objects.
		 * 
		 */
		Commercial(bool rental_in, double value_in, bool bdiscouont_in, string address_in, double discount);
		~Commercial();
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