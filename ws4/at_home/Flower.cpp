/*
Name : Nisham Bohora
SenecaID:nbohora@myseneca.ca
ID:154469183
Section:NAB
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Flower.h"
#include "utils.h"
#include <cstring>
using namespace std;
namespace sdds
{
	Flower::Flower() {//Default Constructor
		setEmpty();

	}
	Flower::Flower(const char* flowerName, const char* flowerColour, double value) {//Initializing value using constructor that accept three parameter
		if (flowerName != nullptr && flowerName[0] != 0 && flowerColour != nullptr && flowerColour[0] != 0 && value > 0)
		{
			f_name = new char[strlen(flowerName) + 1];//Dynamice memory allocation
			strcpy(f_name, flowerName);

			f_colour = new char[strlen(flowerColour) + 1];//Dynamicmemory allocation
			strcpy(f_colour, flowerColour);


			f_price = value;




		}
		else
			setEmpty();


	}
	Flower::~Flower() { //Deallocation of memory  using Destructor
		if (!isEmpty())
		{
			cout << colour() << " " << name() << " " << "has departed..." << endl;
		}
		else
			cout << "An unknown flower has departed..." << endl;
		delete[] f_name;
		delete[] f_colour;

	}
	const char* Flower::name() const//function to return colour
	{
		return f_name;

	}
	const char* Flower::colour() const//function  to return colour
	{
		return f_colour;
	}
	double Flower::price() const {
		return f_price;
	}
	bool Flower::isEmpty()const {//Checking wheather is empty is valid or not
		return f_name == nullptr && f_colour == nullptr && f_price == 0;
	}
	void Flower::setEmpty()//function to Set object to empty state
	{
		f_name = nullptr;
		f_colour = nullptr;
		f_price = 0;


	}
	void Flower::setName(const char* prompt) {//function to set name of flower

		char flowerName[NAME_MAX_LEN + 1];
		cout << prompt;

		read(flowerName, NAME_MAX_LEN, "A flower's name is limited to 25 characters... Try again: ");
		f_name = new char[strlen(flowerName) + 1];
		strcpy(f_name, flowerName);

	}
	void Flower::setName(const char* name, int len)
	{
		f_name = new char[len + 1];
		strcpy(f_name, name);
	}


	void Flower::setColour(const char* prompt)//function to set colour for flower
	{
		char colourName[COL_MAX_LEN + 1];
		cout << prompt;

		read(colourName, COL_MAX_LEN, "A flower's colour is limited to 15 characters... Try again: ");
		f_colour = new char[strlen(colourName) + 1];
		strcpy(f_colour, colourName);

	}
	void Flower::setColour(const char* colour, int len)
	{
		f_colour = new char[len + 1];
		strcpy(f_colour, colour);
	}
	void Flower::setPrice(const char* prompt) {//function  to set price for flower
		cout << prompt;
		do {
			cin >> f_price;
		} while (f_price <= 0 && cout << "A flower's price is a non-negative number... Try again: ");



	}
	
	void Flower::setPrice(double price)
	{
		if (price > 0)
		{
			f_price = price;
		}

		else {
			price = 1; 
		}
	}

	void Flower::setFlower() {//function to setup whole flower detail
		cout << "Beginning the birth of a new flower..." << endl;
		setName("Enter the flower's name... : ");
		setColour("Enter the flower's colour... : ");
		setPrice("Enter the flower's price... : ");
		cout << "The flower's current details..." << endl;
		display();

	}
	ostream& Flower::display()const//function to display  flower detail
	{
		if (isEmpty()) {
			cout << "This is an empty flower..." << endl;
		}
		else {
			cout << "Flower: " << colour() << " " << name() << " Price: " << price() << endl;
		}
		return cout;

	}



}