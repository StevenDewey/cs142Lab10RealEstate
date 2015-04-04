#include "Property.h"

class Commercial : public Property
{
	private:
		int rental;
		double value;
		int vacant;

	public:
		//---------------------------------------------------------------------------------------
		/* 
		 * Constructor/Destructor
		 * 
		 * Handles creation and deletion of Residential Property objects.
		 * 
		 */
		Commercial(int rental_in, double value_in, int vacant_in);
		~Commercial();
		
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