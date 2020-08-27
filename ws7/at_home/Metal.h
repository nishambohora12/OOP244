/*
Name : Nisham Bohora
SenecaID:nbohora@myseneca.ca
ID:154469183
file:Ore.h
Section:NAB
*/


#ifndef SDDS_METAL_H
#define SDDS_METAL_H
#define DEFAULT_MOHS 2.5
#define NAME_LEN 10
#include "Ore.h"
namespace sdds
{
	class Metal:public Ore {


	private:
		char* m_name;
		double m_mohs;

	public:
		Metal();
		Metal(double m_weight, int purityOfMetal, const char* classification, const char* metalName, double metaMohs);
		~Metal();
		void safeEmpty();
		void refine();
		std::ostream& display(std::ostream& os)const;
		std::istream& input(std::istream& is);

		

	};
	std::istream& operator>>(std::istream& is, Metal& met);
	std::ostream& operator<<(std::ostream& os, const Metal& met);

}


#endif