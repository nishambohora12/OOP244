/*
Name : Nisham Bohora
SenecaID:nbohora@myseneca.ca
ID:154469183
file:Ore.h
Section:NAB
*/


#ifndef SDDS_ORE_H
#define SDDS_ORE_H
#include<iostream>
//Setting up default value
#define DEFAULT_WEIGHT 300.50
#define DEFAULT_PURITY 20
#define CLASS_LEN 30
namespace sdds
{
	class Ore//Class Declaration
	{
	private:
		double o_weight;
		int o_purity;
		char o_classification[CLASS_LEN + 1];
	public://Method prototype Declaration 
		Ore();
		Ore(double weight, int val, const char* classification="Unknown");
		~Ore();
		void safeEmpty();
		bool refine();
		std::ostream& display(std::ostream& os)const;
		std::istream& input(std::istream& is);



	};
	//Helper function prototype declaration
	std::ostream& operator<<(std::ostream& os, const Ore& ore);
	std::istream& operator>>(std::istream& os, Ore& ore);
}
#endif