
/*
Name : Nisham Bohora
SenecaID:nbohora@myseneca.ca
ID:154469183
file:ReportUtlis.cpp
*/
#include "ReportUtils.h"
#include <iostream>
using namespace std;
namespace sdds {

	void line(int lineupto, char symbol) {

		for (int i = 0; i < lineupto; i++)
		{
			cout << symbol;
		}
		
	}

	void flushkeyboard()
	{
		char ch;
		do {
			ch = cin.get();

		} while (ch != '\n');
	}
}
