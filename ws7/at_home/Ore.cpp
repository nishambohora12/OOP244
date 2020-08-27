/*
Name : Nisham Bohora
SenecaID:nbohora@myseneca.ca
ID:154469183
file:Ore.cpp
Section:NAB
*/

#define _CRT_SECURE_NO_WARNINGS
#include"Ore.h"
#include<iostream>
#include<cstring>
#include<iomanip>	


using namespace std;
namespace sdds {

	Ore::Ore()
	{
		safeEmpty();
	}
	Ore::Ore(double weight, int val, const char* classification) //Three arguement constructor
	{
		if (weight < 1)//condition check
		{
			o_weight = DEFAULT_WEIGHT;
		}
		else
		{
			o_weight = weight;
		}

		if (val < 1 || val > 100)//condition check
		{
			o_purity = DEFAULT_PURITY;
		}
		else
		{
			o_purity = val;
		}

		strncpy(o_classification, classification, CLASS_LEN);

	}
	void Ore::safeEmpty()//Function defination to set object empty
	{
		o_weight = 0.0;
		o_purity = 0.0;
		strcpy(o_classification, "");
	}
	Ore::~Ore()
	{

	}
	bool Ore::refine()
	{
		bool check = false;
		if (o_purity == 100)
		{
			cout << "Can no longer be refined" << endl;
		}

		else
		{
			o_weight -= 20;
			o_purity += 10;
			if (o_purity > 100)
			{
				o_purity = 100;

			}
			check = true;
		}
		return check;
	}
	std::ostream& Ore::display(ostream& os)const//Function defination to display the value
	{
		if (o_classification[0] == '\0')
		{

			os << "This ore is imaginary" << endl;

		}
		else
		{
			os << "Weight: " << setprecision(2) << fixed << o_weight << endl;
			os << "Purity: " << o_purity << endl;
			os << "Classification: " << setprecision(2) << fixed << o_classification << endl;

		}
		return os;
	}
	std::istream& Ore::input(istream& is) //Function defination accept input from user
	{
		{
			double weight = 0.0;
			int purity = 0;
			char classification[CLASS_LEN];

			cout << "Enter a value for this ore's weight: ";
			is >> weight;

			cout << "Enter a value for this ore's purity: ";
			is >> purity;
			is.ignore();

			cout << "Enter a classification for the ore (MAX 30 chars): ";
			is.getline(classification, 31);


			if (weight < 1)//condition check
			{
				o_weight = DEFAULT_WEIGHT;
			}
			else
			{
				o_weight = weight;
			}

			if (purity < 1 || purity > 100)//condition check
			{
				o_purity = DEFAULT_PURITY;
			}
			else
			{
				o_purity = purity;
			}

			strncpy(o_classification, classification, CLASS_LEN);

			return is;
		}
	}

	//Helper Function
	std::ostream& operator<<(ostream& os, const Ore& ore)//Display operator operload function
	{
		os << "Ore" << endl;
		ore.display(os);
		return os;
	}
	std::istream& operator>>(istream& os, Ore& ore)//Input operator overlaod function
	{
		ore.input(os);
		return os;
	}


}