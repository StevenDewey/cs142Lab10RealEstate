#include <iostream>
#include <string>
#include <ctime> 
#include <iomanip>
#include <fstream>
#include <vector>
#include <math.h>
#include <sstream>
#include "Property.h"
#include "Residential.h"
#include "Commercial.h"

using namespace std;

void check_cin(int& userInput)
{
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        userInput = 0;
    }
}
/*double caclTaxes(bool commRental, bool commNonRent, bool resVacant, bool resOccupied, bool bdiscounted, double discountAmt, double value )
{
	const double commRentalTaxRate = .012;
	const double commNonRentTaxRate = .01;
	const double resVacantRentalTaxRate = .006;
	const double resOccupiedRentalTaxRate = .009;
	double rate;
	if (commRental)
	{
		rate = commRentalTaxRate;
	}
	else if (commNonRent)
	{
		rate = commNonRentTaxRate;
	}
	else if (resVacant)
	{
		rate = resVacantRentalTaxRate;
	}
	else if (resOccupied)
	{
		rate = resOccupiedRentalTaxRate;
	}
	double taxAmt = value * rate;
	if (bdiscounted)
	{
		taxAmt -= discountAmt;
	}
	return taxAmt;
}*/

int main()
{
	//collect input
	vector<Property*> Properties;
	string fileName;
	cout << "Name of File: " << endl;
	cin >> fileName;
	string line;
	ifstream myfile (fileName);
	//make each line an array of characters and loop through to 
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			int i=0;
			while (isalpha(line[i]))
			{
				i++;
			}
			string type = line.substr(0,i);
			if (type == "Residential")
			{
				while (isspace(line[i]))
				{
					i++;
				}
				int j = i; //to determine the starting place for the rental digit
				while (!isspace(line[i]))
				{
					i++;
				}
				string rental = line.substr(j,i-j); //collecting what should be one digit either 0 or 1
				if (rental.size() > 1)
				{
					string errorLine = line.substr(0); //Get the whole line and print it as an ERROR
					cout << "Ignoring bad RESIDENTIAL in input file: " << errorLine << endl;
				}
				else
				{
					while (isspace(line[i]))//this is looping through what should be one space with no characters present 
					{
						i++;
					}
					int k = i;
					if (!isdigit(line[i]))
					{
						string errorLine = line.substr(0); //Get the whole line and print it as an ERROR
						cout << "Ignoring bad RESIDENTIAL in input file: " << errorLine << endl;
					}
					else
					{
						while (isdigit(line[i]))//this should loop through what the value of the property is
						{
							i++;
						}
						string value = line.substr(k,i-k); //collecting what should be the value of the property
						while (isspace(line[i]))//this is looping through what should be one space with no characters present
						{
							i++;
						}
						int l = i;
						if (!isdigit(line[i]))
						{
							string errorLine = line.substr(0); //Get the whole line and print it as an ERROR
							cout << "Ignoring bad RESIDENTIAL in input file: " << errorLine << endl;
						}
						else
						{
							while (!isspace(line[i]))//determining vacancy
							{
								i++;
							}
							string vacant = line.substr(l,i-l);
							if (vacant.size() > 1)
							{
								string errorLine = line.substr(0); //Get the whole line and print it as an ERROR
							cout << "Ignoring bad RESIDENTIAL in input file: " << errorLine << endl;
							}
							else
							{
								while (isspace(line[i]))//this is looping through what should be one space with no characters present
								{
									i++;
								}
								string address = line.substr(i);
								bool brental;
								if (rental == "0")
								{
									brental = false;
								}
								else
								{
									brental = true;
								}
								bool occupied;
								if (vacant == "0")
								{
									occupied = false;
								}
								else
								{
									occupied = true;
								}
								double dvalue;
								stringstream st;
								st << value;
								st >> dvalue;
								Properties.push_back(new Residential(brental, dvalue, occupied, address));
							}
						}
					}
				}
			}
			else if (type == "Commercial")
			{
				while (isspace(line[i]))
				{
					i++;
				}
				int j = i; //to determine the starting place for the rental digit
				while (!isspace(line[i]))
				{
					i++;
				}
				string rental = line.substr(j,i-j); //collecting what should be one digit either 0 or 1
				if (rental.size() > 1)
				{
					string errorLine = line.substr(0); //Get the whole line and print it as an ERROR
					cout << "Ignoring bad RESIDENTIAL in input file: " << errorLine << endl;
				}
				else
				{
					while (isspace(line[i]))//this is looping through what should be one space with no characters present 
					{
						i++;
					}
					int k = i;
					if (!isdigit(line[i]))
					{
						string errorLine = line.substr(0); //Get the whole line and print it as an ERROR
						cout << "Ignoring bad RESIDENTIAL in input file: " << errorLine << endl;
					}
					else
					{
						while (isdigit(line[i]))//this should loop through what the value of the property is
						{
							i++;
						}
						string value = line.substr(k,i-k); //collecting what should be the value of the property
						while (isspace(line[i]))//this is looping through what should be one space with no characters present
						{
							i++;
						}
						int l = i;
						if (!isdigit(line[i]))
						{
							string errorLine = line.substr(0); //Get the whole line and print it as an ERROR
							cout << "Ignoring bad COMMERCIAL in input file: " << errorLine << endl;
						}
						else
						{
							while (!isspace(line[i]))//determining vacancy
							{
								i++;
							}
							string vacant = line.substr(l,i-l);
							if (vacant.size() > 1)
							{
								string errorLine = line.substr(0); //Get the whole line and print it as an ERROR
								cout << "Ignoring bad COMMERCIAL in input file: " << errorLine << endl;
							}
							else
							{
								while (isspace(line[i]))//this is looping through what should be one space with no characters present
								{
									i++;
								}
								if (!isdigit(line[i]))
								{
									string errorLine = line.substr(0); //Get the whole line and print it as an ERROR
									cout << "Ignoring bad COMMERCIAL in input file: " << errorLine << endl;
								}
								else
								{
									int m = i;
									while (!isspace(line[i]))//determining vacancy
									{
										i++;
									}
									string discount = line.substr(m,i-m);
									while (isspace(line[i]))//this is looping through what should be one space with no characters present
									{
										i++;
									}
									string address = line.substr(i);
									bool brental;
									if (rental == "0")
									{
										brental = false;
									}
									else
									{
										brental = true;
									}
									bool bdiscount;
									if (vacant == "1")
									{
										bdiscount = true;
									}
									else
									{
										bdiscount = false; //its occupied
									}
									double dvalue;
									stringstream st;
									st << value;
									st >> dvalue;
									double ddiscount;
									stringstream st2;
									st2 << discount;
									st2 >> ddiscount;
									Properties.push_back(new Commercial(brental, dvalue, bdiscount, address, ddiscount));
								}
							}
						}
					}
				}
			}
			else
			{
				
				string entireLine = line;
				cout << "Ignoring unknown types of properties appearing in the input file: " << entireLine << endl;
			}	
		}
		cout << "All valid properties:" << endl;
		for (int i = 0; i < Properties.size(); i++)
		{
			cout << Properties[i]->toString() << endl;
		}
		cout << endl << endl;
		/*
		//Print out TAX stuff
		int userInput;
		cout << "\n\n Please select one of these options: " << endl;
		cout << "1 - Sort Tax Report by Tax Amount " << endl;
		cout << "2 - Show Current Balance " << endl;
		cout << "3 - Do not Sort Report " << endl;
		cin >> userInput;
		check_cin(userInput);
		if (userInput == 1)
		{
			for (int i = 0; i < Properties.size(); i++)
			{
				for (int j = 0; j < Properties.size()-1; j++)
				{
					if (Properties[j]->getTaxDue() > Properties[i]->getTaxDue())
					{
						Property * temp = Properties[j+1];
						Properties[j+1] = Properties[j];
						Properties[j] = temp;

					}
				}
			} 
		}
		else if (userInput == 3)
		{

		}
		*/
		cout << "NOW PRINTING TAX REPORT:" << endl;
		for (int i = 0; i < Properties.size(); i++)
		{
			cout << Properties[i]->taxReport();
		}
		cout << endl << endl;
	}
	else
	{
		cout << "Not able to open file." << endl;
	}

	

	system("pause");
	return 0;
}