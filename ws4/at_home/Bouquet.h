/*
Name : Nisham Bohora
SenecaID:nbohora@myseneca.ca
ID:154469183
file:Bouquet.h
Section:NAB
*/


#ifndef SDDS_BOUQUET_H
#define SDDS_BOUQUET_H
#include "Flower.h"
#include <iostream>


namespace sdds 

{
const int MESS_MAX_LEN = 25;
const int MAX_FLOWERS = 3;
	
	class Bouquet {
	private:
		double b_price;
		char* b_message;
		Flower* b_flowers;
		int b_flowerCount;
		void flushKeyboard() const;


	public:
		Bouquet();
	    Bouquet(const Flower* flowers, int noOfFlowers = MAX_FLOWERS, const char* message="Congratulations");
		~Bouquet();
		const char* message() const;
		double price() const;
		bool isEmpty()const;
		void setEmpty();
		void setMessage(const char* prompt);
		void discardBouquet();
		void arrangeBouquet();
		std::ostream& display() const;



	};



}

#endif