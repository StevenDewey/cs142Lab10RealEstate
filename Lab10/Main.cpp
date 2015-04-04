#include <iostream>
#include <string>
#include <ctime> 
#include <iomanip>
#include <fstream>
#include <vector>
#include <math.h>
#include <sstream>
#include "Property.h"

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

int main()
{
	vector<Property*> Properties;
	string fileName;
	cout << "Name of File: " << endl;
	cin >> fileName;
	string line;
	ifstream myfile (fileName);
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
				cout << type << endl;
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
				cout << rental << endl;
				if (rental.size() > 1)
				{
					//do nothing for now
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
						//do nothing for now.
					}
					else
					{
						while (isdigit(line[i]))//this should loop through what the value of the property is
						{
							i++;
						}
						string value = line.substr(k,i-k); //collecting what should be the value of the property
						cout << value << endl;
						while (isspace(line[i]))//this is looping through what should be one space with no characters present
						{
							i++;
						}
						int l = i;
						if (!isdigit(line[i]))
						{
							//do nothing for now
						}
						else
						{
							while (!isspace(line[i]))//determining vacancy
							{
								i++;
							}
							string vacant = line.substr(l,i-l);
							cout << vacant << endl;
							if (vacant.size() > 1)
							{
								//do nothing for now
							}
							else
							{
								while (isspace(line[i]))//this is looping through what should be one space with no characters present
								{
									i++;
								}
								string address = line.substr(i);
								cout << address << endl;
								Properties.push_back(new Property(address));
							}
						}
					}
				}
			}
			else if (type == "Commercial")
			{
				cout << type << endl;
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
				cout << rental << endl;
				if (rental.size() > 1)
				{
					//do nothing for now
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
						//do nothing for now.
					}
					else
					{
						while (isdigit(line[i]))//this should loop through what the value of the property is
						{
							i++;
						}
						string value = line.substr(k,i-k); //collecting what should be the value of the property
						cout << value << endl;
						while (isspace(line[i]))//this is looping through what should be one space with no characters present
						{
							i++;
						}
						int l = i;
						if (!isdigit(line[i]))
						{
							//do nothing for now
						}
						else
						{
							while (!isspace(line[i]))//determining vacancy
							{
								i++;
							}
							string vacant = line.substr(l,i-l);
							cout << vacant << endl;
							if (vacant.size() > 1)
							{
								//do nothing for now
							}
							else
							{
								while (isspace(line[i]))//this is looping through what should be one space with no characters present
								{
									i++;
								}
								if (!isdigit(line[i]))
								{
									//do nothing for now
								}
								else
								{
									int m = i;
									while (!isspace(line[i]))//determining vacancy
									{
										i++;
									}
									string discount = line.substr(m,i-m);
									cout << discount << endl;
									while (isspace(line[i]))//this is looping through what should be one space with no characters present
									{
										i++;
									}
									string address = line.substr(i);
									cout << address << endl;
									Properties.push_back(new Property(address));
								}
							}
						}
					}
				}
			}
			else
			{
				
				string entireLine = line;
				cout << entireLine << endl;
			}	
		}
	}

	for (int i = 0; i < Properties.size(); i++)
	{
		cout << Properties[i]->toString();
	}


	system("pause");
	return 0;
}