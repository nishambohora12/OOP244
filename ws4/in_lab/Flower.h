#ifndef SDDS_FLOWER_H
#define SDDS_FLOWER_H
/*
Name : Nisham Bohora
SenecaID:nbohora@myseneca.ca
ID:154469183
file:FLower.h
Section:NAB
*/
#include <iostream>
namespace sdds {
const int NAME_MAX_LEN =25;
const int COL_MAX_LEN=15;

	class Flower {
	private:
		char* f_name;
		char* f_colour;
		double f_price;
	public:
		Flower();
		Flower(const char* flowerName, const char* flowerColour, double value);
		~Flower();
		const char* name() const;
		const char* colour() const;
		double price() const;
		bool isEmpty()const;
		void setEmpty();
		void setName(const char* prmopt);
		void setColour(const char* prompt);
		void setPrice(const char* prompt);
		void setFlower();
		std::ostream& display()const;


	};







}





#endif