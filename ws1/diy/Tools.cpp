/*Name:Nisham Bohora
//AddressID:nbohora@myseneca.ca  
//ID NO:1554469183
//Function defination of those function are define which are not related to the phonedir 
but help to make code clear like helping function*/

#include <iostream>
#include "Tools.h"

using namespace std;
namespace sdds
{
	bool valid(long long min, long long max, long long val) 
	{
		return min <= val && val <= max;
	}

	long long getLongLong(long long min, long long max, const char* valueName) 
	{
		long long val;
		bool done = false;
		while (!done) {
			cin >> val;
			if (cin.fail()) {
				cin.clear();
				cout << "Bad Number, try again: ";
			}
			else {
				if (!valid(min, max, val)) {
					cout << "Invalid " << valueName << "!" << endl
						<< "The " << valueName << " must be between " << min << " and " << max << ": ";
				}
				else {
					done = true;
				}
			}
			cin.ignore(1000, '\n');
		}
		return val;
	}
	//Function Defination to get phone number
	long long getPhoneNumber()
	{
		return getLongLong(1000000000LL, 9999999999LL, "Phone Number");
	}

	//Function Defination of getstr
	void getStr(char* str, int len)
	{
		cin.getline(str, len, '\n');
	}
	//Function Defination of yes function
	bool yes() 
	{
		char ch;
		ch = cin.get();
		cin.ignore(1000, '\n');
		return ch == 'y' || ch == 'Y';
	}

	//Function Defination to lowercase
	void toLowerCase(char* lowerCase, const char* str)
	{
		int i;
		for (i = 0; str[i] && i < 30; i++) 
		{
			lowerCase[i] = str[i] | 0x20;
		}
		lowerCase[i] = 0;
	}
	//Function Defination to get Name
	void getName(char* name) 
	{
		getStr(name, 30);
	}

	
}
