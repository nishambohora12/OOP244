/*
Name : Nisham Bohora
SenecaID:nbohora@myseneca.ca
ID:154469183
file:Pencil.cpp
Section:NAB
*/


#define _CRT_SECURE_NO_WARNINGS
#include "Pencil.h"
#include<iostream>
#include<cstring>

using namespace std;
namespace sdds
{
Pencil::Pencil() :pencil_graphite(0)//Default Constructor Function Defination
{
	strcpy(pencil_HB_scale, "");
}
Pencil::Pencil(const char* hbscale, int graphite)//Two Argument Function Defination
{
	if (hbscale == nullptr || hbscale[0] == '\0')//Condtion check for paratmeter empty State
	{
		strcpy(pencil_HB_scale,"");
		pencil_graphite = graphite;
	}
	else {
		strcpy(pencil_HB_scale, hbscale);
	
		if (graphite < 1 || graphite >100) 
		{
			graphite = GRAPHITE_MAX;
		}
		pencil_graphite = graphite;
	}
}
Pencil::~Pencil() //Default Destructor
{
	//
}
void Pencil::write(const char* wordText ) //Function to Receive Text
{
	int wordlength = strlen(wordText);
	if (pencil_graphite == 0)
	{
		cout << "We can't write without graphite!" << endl;
	}
	else 
	{
		cout << "Writing out the following: " << wordText << " with a Pencil!" << endl;
		for (int i = 0; i < wordlength; i++) {
			if (wordText[i] == ' ') 
			{
				pencil_graphite -= 5;//Reduce  graphite According to space
				if (pencil_graphite < 0)
				{
					pencil_graphite = 0;
				}
			}
		}
	}
}

void Pencil::refill(int newGraphite) //Refill Function Defiantion
{
	{
		cout << "Refilling the pencil with graphite" << endl;

		pencil_graphite += newGraphite; //Adding new Graphite to existing

		if (pencil_graphite > GRAPHITE_MAX)
		{
			pencil_graphite = GRAPHITE_MAX;
		}
	}
}
bool Pencil::filled()const //bool to check empty graphite
{
	return pencil_graphite > 0;
}
ostream& Pencil::display(ostream& os)const//Function defination to display Detail of pencil
{
	if (pencil_HB_scale[0] == '\0')//Condition Check
	{
		cout << "This is an empty Pencil" << endl;
	}
	else {
		cout << "Pencil Details" << endl;
		cout << "HB Value: " << pencil_HB_scale << endl;
		cout << "Graphite Remaining: " << pencil_graphite << endl;
	}

	return os;
}
}
