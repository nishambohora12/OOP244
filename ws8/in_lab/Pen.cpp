
/*
Name : Nisham Bohora
SenecaID:nbohora@myseneca.ca
ID:154469183
file:Pen.cpp
Section:NAB
*/



#define _CRT_SECURE_NO_WARNINGS
#include "Pen.h"
#include<iostream>
#include<cstring>

using namespace std;
namespace sdds
{
	Pen::Pen():pen_style(nullptr) ,pen_ink(0)//Default Constructor
	{

	}
	Pen::Pen(const char* style, int inkAmount)//Two Arguemnt Constructor
	{
		if (style == nullptr || style[0] == '\0')
		{
			pen_ink = 0;
			pen_style = nullptr;
		}

		else
		{
			pen_style = new char[strlen(style) + 1]; // 1 for null byte
			strcpy(pen_style, style);

			if (inkAmount < 1 || inkAmount > 50)
			{
				inkAmount= INK_MAX;
			}
			pen_ink = inkAmount;
		}
	}
	Pen::~Pen() //Default Destructor
	{
		delete[] pen_style;
	}
	void Pen:: write(const char* wordText)//Function to receive the word text
	{
		int lengthText = strlen(wordText);
		if (pen_ink == 0) //Condition check
		{
			cout << "We can't write without ink!" << endl;
		}
		else
		{
			cout << "Writing out the following: " << wordText << " with a Pen!" << endl;
			for (int i = 0; i < lengthText; i++)
			{
				if (wordText[i] != ' ')//Reduce Ink according no of space
				{
					pen_ink -= 2;
					if (pen_ink < 0)
					{
						pen_ink = 0;
					}
				}
			}
		}

	}
	void Pen::refill(int newInk) //Function Defination to refill INK
	{
		{
			cout << "Refilling the pen with ink" << endl;

			if (newInk  > INK_MAX)
			{
				newInk = INK_MAX;
			}

			pen_ink += newInk;//Adding Ink to existing
		}

	}
	bool Pen::filled()const//Bool to check Empty inl
	{
		return pen_ink > 0;
	}
	ostream& Pen::display(ostream& os)const//Display function to Display pen Detail
	{

		if (pen_style == nullptr || pen_style[0] == '\0')
		{
			cout << "This is an empty Pen" << endl;
		}

		else {
			cout << "Pen Details" << endl;
			cout << "Style: " << pen_style << endl;
			cout << "Ink Remaining: " << pen_ink << endl;
		}

		return os;
	}
}
