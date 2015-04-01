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
			while (!isspace(line[i]))
			{
				i++;
			}
			while (isspace(line[i]))
			{
				i++;
			}

			while (!isspace(line[i]))
			{
				i++;
			}
			while (isspace(line[i]))
			{
				i++;
			}

			while (!isspace(line[i]))
			{
				i++;
			}
			while (isspace(line[i]))
			{
				i++;
			}

			while (!isspace(line[i]))
			{
				i++;
			}
			while (isspace(line[i]))
			{
				i++;
			}
			string address = line.substr(i);
			Properties.push_back(new Property(address));
		}
	}

	for (int i = 0; i < Properties.size(); i++)
	{
		cout << Properties[i]->toString();
	}


	system("pause");
	return 0;
}